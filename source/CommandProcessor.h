//
// Created by duyph on 2023-04-26.
//

#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include "SystemManager.h"
#include "Command.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class CommandProcessor {
public:
    CommandProcessor(const string &input1, const string &input2, const string &input3);

    void run();


private:
    vector<string> splitInputArgs(const string &input, char delimiter);

    pair<string, vector<string>> parseInput(const vector<string> &input);

    pair<string, vector<string>> getUserChoice();

    void processUserChoice(pair<string, vector<std::string>> choice);

    struct InputData {
        string dataPath;
        string commandScriptPath;
        string logPath;
    };

    CommandUserChoice allUserChoice;

    string userChoice_;
    InputData inputdata_;
    SystemManager GISSystem;
};

#endif //COMMANDPROCESSOR_H
