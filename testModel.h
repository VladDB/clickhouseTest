#pragma once

// #include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include<unistd.h>  
#include <thread>
#include <mutex>

#include "dbService.h"

class TestModel
{
private:
    unique_ptr<DbService> dbService;
    mutex mtx;
    
    string dbUser = "default";
    string dbPass = "masterkey";
    string dbName = "test";
    string dbTable = "params";
    int rndType = 0;
    int paramsCount = 50;
    int dbType = 0;
    int ampl = 10;
    int freq = 100;

    float GenerateData();

public:
    bool prepareForTesting = false;
    vector<thread> ths;
    bool stopTh = false;

    TestModel() {}
    ~TestModel() {}

    void SetDbUser(string user) { this->dbUser = user; }
    string GetDbUser() const { return this->dbUser; }

    void SetDbTable(string table) { this->dbTable = table; }
    string GetDbTable() const { return this->dbTable; }

    void SetDbPassword(string pass) { this->dbPass = pass; }
    string GetDbPassword() const { return this->dbPass; }

    void SetDbName(string name) { this->dbName = name; }
    string GetDbName() const { return this->dbName; }

    void SetRndType(int inRndType) { this->rndType = inRndType; }
    int GetRndType() const { return this->rndType; }

    void SetParamsCount(int inCount) { this->paramsCount = inCount; }
    int GetParamsCount() const { return this->paramsCount; }

    void SetDbType(int type) { this->dbType = type; }
    int GetDbType() const { return this->dbType; }

    void SetAmpl(int inAmpl) { this->ampl = inAmpl; }
    int GetAmpl() const { return this->ampl; }

    void SetFreq(int inFreq) { this->freq = inFreq; }
    int GetFreq() const { return this->freq; }

    void ConnectToDbAndCreateTable();
    void StartTesting();
    void ClearThs();
    void DropDb();
    uint64_t GetDBRowsCount();
    string ToStr();
};
