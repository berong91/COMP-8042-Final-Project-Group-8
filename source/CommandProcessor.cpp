//
// Created by duyph on 2023-04-26.
//

#include "CommandProcessor.h"
#include <iostream>;

using namespace std;

CommandProcessor::CommandProcessor(const std::string &input1,
                                   const std::string &input2,
                                   const std::string &input3) {
    inputdata_.dataPath = input1;
    inputdata_.commandScriptPath = input2;
    inputdata_.logPath = input3;
}

void CommandProcessor::run() {
    while (true) {
        cout << "input > ";
        string choice = getUserChoice();
        processUserChoice(choice);
    }
}

string CommandProcessor::getUserChoice() {
    string choice;
    getline(cin, choice);
    return choice;
}

void CommandProcessor::processUserChoice(const string &choice) {
    string input = choice;

    // TODO: process choice further into command and arguments for command

    // TODO: processing each cases by their own function
    if (input == allUserChoice.wordChoice) {
        cout << input << endl;
    } else if (input == allUserChoice.importChoice) {
        cout << input << endl;
    } else if (input == allUserChoice.debugChoice) {
        cout << input << endl;
    } else if (input == allUserChoice.whatIsChoice) {
        cout << input << endl;
    } else if (input == allUserChoice.whatIsInChoice) {
        cout << input << endl;
    } else if (input == allUserChoice.whatIsAtChoice) {
        cout << input << endl;
    } else if (input == allUserChoice.exitChoice) {
        cout << input << endl;
    } else {
        cout << input << endl;
    }
}