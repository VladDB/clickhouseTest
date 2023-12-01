#include "testModel.h"

float TestModel::GenerateData()
{
    time_t timer = time(0);
    float tmp = this->ampl * sin(this->freq * timer);
    this->mtx.unlock();
    return tmp;
}

void TestModel::ConnectToDbAndCreateTable()
{
    this->dbService = std::make_unique<DbService>(this->dbUser, this->dbPass, this->dbName, this->dbTable, this->paramsCount);

    try
    {
        dbService->Connect();

        // Create DB with params
        if (dbType == 0)
            dbService->CreateTableAndColums();
        else
            dbService->CreateTableAndColumsWithParamId();
    }
    catch (const std::exception &e)
    {
        printf("TestModel: %s\n", e.what());
        allLog.push_back("TestModel: " + (string)e.what());
        this->prepareForTesting = false;
    }
    this->prepareForTesting = true;
}

void TestModel::StartTesting()
{
    try
    {
        // start generate and insert
        int counter = 10;
        float data = 0;
        bool needReconnect = false;
        while (!stopTh)
        {
            if (needReconnect)
            {
                this->mtx.lock();
                this->dbService->Reconnect();
                this->mtx.unlock();
                needReconnect = false;
            }

            // make saw
            if (this->rndType != 0)
            {
                if (counter == 10)
                {
                    data = this->GenerateData();
                    counter = 0;
                }
                counter++;
            }
            else
                data = this->GenerateData(); // make sin
            try
            {
                this->mtx.lock();
                if (dbType == 0)
                    this->dbService->InsertData(data);
                else
                    this->dbService->InsertDataWithParamId(data);
                this->mtx.unlock();
            }
            catch (const std::exception &e)
            {
                printf("%s\n", e.what());
                allLog.push_back(e.what());
                this->mtx.unlock();
                needReconnect = true;
            }
            sleep(1);
        }
    }
    catch (const std::exception &e)
    {
        printf("TestModel: %s\n", e.what());
        allLog.push_back("TestModel: " + (string)e.what());
    }
}

void TestModel::ClearThs()
{
    try
    {
        for (auto &th : this->ths)
        {
            th.detach();
        }
        this->ths.clear();
    }
    catch (const std::exception &e)
    {
        printf("TestModel: %s\n", e.what());
        allLog.push_back("TestModel: " + (string)e.what());
    }
}

void TestModel::DropDb()
{
    try
    {
        this->dbService->DropDataBase();
    }
    catch (const std::exception &e)
    {
        printf("TestModel: %s\n", e.what());
        allLog.push_back("TestModel: " + (string)e.what());
        return;
    }
    this->prepareForTesting = false;
}

uint64_t TestModel::GetDBRowsCount()
{
    uint64_t cnt;
    try
    {
        this->mtx.lock();
        cnt = this->dbService->GetRowsCount();
        this->mtx.unlock();
    }
    catch (const std::exception &e)
    {
        printf("TestModel: %s\n", e.what());
        allLog.push_back("TestModel: " + (string)e.what());
        this->mtx.unlock();
    }
    return cnt;
}

string TestModel::ToStr()
{
    string str;
    str.append("DB settings\n");
    str.append("Db Name: ").append(this->dbName).append("\n");
    str.append("User: ").append(this->dbUser).append("\n");
    str.append("Password: ").append(this->dbPass).append("\n");
    str.append("Table name: ").append(this->dbTable).append("\n");
    str.append("Type: ").append(this->dbType == 0 ? "Wide" : "Slim").append("\n");

    str.append("\nTest settings\n");
    str.append("Data type: ").append(this->rndType == 0 ? "as sin" : "as saw").append("\n");
    str.append("Equation: ").append(to_string(this->ampl)).append("sin(").append(to_string(this->freq)).append("*t)\n");
    str.append("Params count: ").append(to_string(this->paramsCount));

    return str;
}