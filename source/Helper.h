//
// Created by duyph on 2023-07-01.
//

#ifndef HELPER_H
#define HELPER_H


#include <string>

using namespace std;

class Helper {
public:
    static string strip(const string &str);

    static long getFileDataSize(FILE *pFile);
};


#endif //HELPER_H
