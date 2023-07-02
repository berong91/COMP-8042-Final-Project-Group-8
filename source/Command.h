//
// Created by duyph on 2023-04-26.
//

#include <string>

using namespace std;

#ifndef COMMAND_H
#define COMMAND_H

struct CommandUserChoice {
    string wordChoice = "word";
    string importChoice = "import";
    string debugChoice = "debug";
    string whatIsChoice = "what_is";
    string whatIsInChoice = "what_is_in";
    string whatIsAtChoice = "what_is_at";
    string exitChoice = "quit";
};

#endif //COMMAND_H
