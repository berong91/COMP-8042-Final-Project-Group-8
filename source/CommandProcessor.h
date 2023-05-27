//
// Created by duyph on 2023-04-26.
//

#ifndef COMP_8042_ADVANCED_ALGORITHMS_AND_DATA_STRUCTURES_DESIGN_AND_ANALYSIS_COMMANDPROCESSOR_H
#define COMP_8042_ADVANCED_ALGORITHMS_AND_DATA_STRUCTURES_DESIGN_AND_ANALYSIS_COMMANDPROCESSOR_H

#include "string"

using namespace std;

class CommandProcessor {
public:
    CommandProcessor(const string &input1, const string &input2, const string &input3);

    void run();

private:
    string getUserChoice();

    void processUserChoice(const string &choice);

    struct InputData {
        string dataPath;
        string commandScriptPath;
        string logPath;
    };

    struct {
        string wordChoice = "word";
        string importChoice = "import";
        string debugChoice = "debug";
        string whatIsChoice = "what_is";
        string whatIsInChoice = "what_is_in";
        string whatIsAtChoice = "what_is_at";
        string exitChoice = "quit";
    } allUserChoice;

    string userChoice_;
    InputData inputdata_;
};

#endif //COMP_8042_ADVANCED_ALGORITHMS_AND_DATA_STRUCTURES_DESIGN_AND_ANALYSIS_COMMANDPROCESSOR_H
