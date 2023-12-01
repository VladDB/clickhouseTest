#include "dbService.h"

vector<string> allLog = {"Start App"};

DbService::DbService(const string dbUser, const string dbPassword, const string name, const string table, int count)
{
    this->dbName = name;
    this->tableName = table;
    this->paramsCount = count;
    this->op = std::make_unique<ClientOptions>();
    this->op->SetHost("localhost");
    this->op->SetUser(dbUser);
    this->op->SetPassword(dbPassword);
}

DbService::~DbService()
{
    // client->Execute("DROP DATABASE " + this->dbName);
    // printf("Database %s was deleted\n", this->dbName.c_str());
}

void DbService::Connect()
{
    try
    {
        // соединяемся
        this->client = std::make_unique<Client>(*this->op);

        // создаем БД если нет c таким названием
        client->Execute("CREATE DATABASE IF NOT EXISTS " + this->dbName);

        allLog.push_back("DbService: Database \"" + this->dbName + "\" was created");
        printf("DbService: Database %s was created\n", this->dbName.c_str());
    }
    catch (exception &e)
    {
        allLog.push_back("DbService: " + (string)e.what());
        throw runtime_error("DbService: Bad connect");
    }
}

void DbService::CreateTableAndColums()
{
    try
    {
        string sqlQuery;
        sqlQuery = "CREATE TABLE IF NOT EXISTS " + dbName + "." + tableName + " (timestamp DateTime,";
        for (int i = 0; i < paramsCount; i++)
        {
            sqlQuery.append(" val" + to_string(i));
            sqlQuery.append(" Float32,");

            // add for future request in db
            this->values.push_back("val" + to_string(i));
        }
        sqlQuery.append(") ENGINE = MergeTree() "
                        "PARTITION BY toYYYYMM(timestamp) "
                        "ORDER BY timestamp");

        client->Execute(sqlQuery);

        printf("Table \"%s\" was created with %i params\n", tableName, paramsCount);
        allLog.push_back("DbService: Table \"" + tableName + "\" was created with " + to_string(paramsCount) + " params");
    }
    catch (exception &e)
    {
        // printf("%s\n", e.what());
        allLog.push_back("DbService: " + (string)e.what());
        throw runtime_error("DbService: Bad creation table");
    }
}

void DbService::CreateTableAndColumsWithParamId()
{
    try
    {
        string sqlQuery;
        sqlQuery = "CREATE TABLE IF NOT EXISTS " + dbName + "." + tableName;
        sqlQuery.append(" (timestamp DateTime, "
                        "paramId UInt16, "
                        "value Float32) ");
        sqlQuery.append("ENGINE = MergeTree() "
                        "PARTITION BY toYYYYMM(timestamp) "
                        "ORDER BY timestamp");

        client->Execute(sqlQuery);

        printf("Table \"%s\" was created with params\n", tableName);
        allLog.push_back("DbService: Table \"" + tableName + "\" was created");
    }
    catch (exception &e)
    {
        // printf("%s\n", e.what());
        allLog.push_back("DbService: " + (string)e.what());
        throw runtime_error("DbService: Bad creation table");
    }
}

void DbService::Reconnect()
{
    this->client->ResetConnection();
}

void DbService::InsertData(float data)
{
    try
    {
        Block block;

        time_t now = time(0);
        auto timestamp = std::make_shared<ColumnDateTime>();
        timestamp->Append(now);
        block.AppendColumn("timestamp", timestamp);

        for (auto const &item : this->values)
        {
            auto val = std::make_shared<ColumnFloat32>();
            val->Append(data);
            block.AppendColumn(item, val);
        }

        client->Insert(this->dbName + "." + tableName, block);

        printf("Data was added with value: %f\n", data);
        // allLog.push_back("Data was added with value: " + to_string(data));
    }
    catch (const std::exception &e)
    {
        // printf("%s\n", e.what());
        allLog.push_back("DbService: " + (string)e.what());
        throw runtime_error("DbService: Bad insert to DB");
    }
}

void DbService::InsertDataWithParamId(float data)
{
    try
    {
        Block block;

        time_t now = time(0);
        auto timestamp = std::make_shared<ColumnDateTime>();
        auto paramId = std::make_shared<ColumnUInt16>();
        auto val = std::make_shared<ColumnFloat32>();

        for (int i = 0; i < paramsCount; i++)
        {
            timestamp->Append(now);
            paramId->Append(i);
            val->Append(data);
        }

        block.AppendColumn("timestamp", timestamp);
        block.AppendColumn("paramId", paramId);
        block.AppendColumn("value", val);

        client->Insert(this->dbName + "." + tableName, block);

        printf("Data was added with value: %f\n", data);
        // allLog.push_back("Data was added with value: " + to_string(data));
    }
    catch (const std::exception &e)
    {
        // printf("%s\n", e.what());
        allLog.push_back("DbService: " + (string)e.what());
        throw runtime_error("DbService: Bad insert to DB");
    }
}

void DbService::DropDataBase()
{
    try
    {
        string sqlQuery;
        sqlQuery = "drop database " + dbName;
        client->Execute(sqlQuery);

        printf("Database %s dropped\n", this->dbName.c_str());
        allLog.push_back("Database " + this->dbName + " dropped");
    }
    catch (const std::exception &e)
    {
        printf("%s\n", e.what());
        allLog.push_back(e.what());
        throw runtime_error("DbService: Bad drop DB");
    }
}

uint64_t DbService::GetRowsCount()
{
    uint64_t cnt;
    try
    {
        string sqlQuery = "SELECT count() FROM " + dbName + "." + tableName;
        client->Select(sqlQuery, [&cnt, sqlQuery](const Block &block)
                       {
            for (size_t c = 0; c < block.GetRowCount(); c++)
            {
                auto col = block[0]->As<ColumnUInt64>();
                cnt = col->At(0);
            } });
    }
    catch (const std::exception &e)
    {
        printf("%s\n", e.what());
        allLog.push_back(e.what());
        throw runtime_error("DbService: Bad getting row count");
    }
    return cnt;
}
