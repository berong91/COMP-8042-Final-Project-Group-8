//
// Created by duyph on 2023-07-01.
//

#include "Helper.h"

string Helper::strip(const string &str) {
    size_t start = 0;
    size_t end = str.length();

    // Find the first non-whitespace character
    while (start < end && isspace(str[start])) {
        start++;
    }

    // Find the last non-whitespace character
    while (end > start && isspace(str[end - 1])) {
        end--;
    }

    // Return the stripped string
    return str.substr(start, end - start);
}
