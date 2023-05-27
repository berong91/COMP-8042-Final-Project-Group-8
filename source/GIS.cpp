//
// Created by duyph on 2023-04-26.
//

#include "CommandProcessor.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        cout << "ERROR MESSAGE. " << endl;
        return 1;
    }

    string databasePath = argv[1];
    string commandScriptPath = argv[2];
    string logPath = argv[3];

    // TODO: Validate path?

    // Initial command processor and pass 3 arguments over
    CommandProcessor processor(databasePath, commandScriptPath, logPath);
    processor.run();

    return 0;
}