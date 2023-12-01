#pragma once

#include <clickhouse/client.h>

using namespace std;
using namespace clickhouse;

extern vector<string> allLog;

class DbService
{
private:
    string dbName;
    string tableName = "paramsC";
    int paramsCount;
    unique_ptr<ClientOptions> op;
    unique_ptr<Client> client;
    vector<string> values;

public:
    DbService(const string dbUser, const string dbPassword, const string name, const string table, int count);
    ~DbService();

    void Connect();
    void Reconnect();
    void CreateTableAndColums();
    void CreateTableAndColumsWithParamId();
    void InsertData(float data);
    void InsertDataWithParamId(float data);
    void DropDataBase();
    uint64_t GetRowsCount();
};
