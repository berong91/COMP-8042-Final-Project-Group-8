//
// Created by duyph on 2023-04-26.
//

#include "CommandProcessor.h"
#include "SystemManager.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

CommandProcessor::CommandProcessor(const string &input1,
                                   const string &input2,
                                   const string &input3) {
    inputdata_.dataPath = input1;
    inputdata_.commandScriptPath = input2;
    inputdata_.logPath = input3;

    GISSystem = SystemManager(inputdata_.dataPath);
}

void CommandProcessor::run() {
    while (true) {
        cout << "input > ";
        processUserChoice(getUserChoice());
    }
}


vector<string> CommandProcessor::splitInputArgs(const string &input, char delimiter) {
    // Split the input by delimiter into vector of string
    vector<string> substrings;
    istringstream iss(input);
    string substring;

    while (getline(iss, substring, delimiter)) {
        substrings.push_back(substring);
    }

    return substrings;
}

pair<string, vector<string>> CommandProcessor::parseInput(const vector<string> &input) {
    if (input.empty()) {
        return make_pair("", vector<string>());
    }

    string command = input[0];
    vector<string> arguments(input.begin() + 1, input.end());

    return make_pair(command, arguments);
}


pair<string, vector<string>> CommandProcessor::getUserChoice() {
    // Geting user input
    string input;
    getline(cin, input);

    // Split input into vector of string
    vector<string> inputVector = splitInputArgs(input, '\t');

    // Separate the command to the command arguments
    pair<string, vector<string>> result = parseInput(inputVector);

    return result;
}

void CommandProcessor::processUserChoice(pair<string, vector<std::string>> choice) {
    // Retrieve the command and its arguments
    string input = choice.first;
    vector<string> command_args = choice.second;



    // TODO: process choice further into command and arguments for command
    // TODO: processing each cases by their own function
    // TODO: each function should verify their arguments
    if (input == allUserChoice.wordChoice) {
        GISSystem.word(command_args);
    } else if (input == allUserChoice.importChoice) {
        GISSystem.import(command_args);
    } else if (input == allUserChoice.debugChoice) {
        GISSystem.debug(command_args);
    } else if (input == allUserChoice.whatIsChoice) {
        GISSystem.what_is(command_args);
    } else if (input == allUserChoice.whatIsInChoice)
        GISSystem.what_is_in(command_args);
    else if (input == allUserChoice.whatIsAtChoice) {
        GISSystem.what_is_at(command_args);
    } else if (input == allUserChoice.exitChoice) {
        // just to do cleanup and stuff
        GISSystem.quit();
    } else {
        // Incorrect choice
    }
}
