//
// Created by duyph on 2023-04-26.
//

#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class SystemManager {
public:
    SystemManager() = default;

    SystemManager(string data_path);

    void word(vector<string> vector);

    void import(vector<string> vector);

    void debug(vector<string> vector);

    void what_is(vector<string> vector);

    void what_is_in(vector<string> vector);

    void what_is_at(vector<string> vector);

    void quit();

private:
    string _dataFilePath;
    unordered_map<string, long> nameIndex;
};


#endif //SYSTEMMANAGER_H
