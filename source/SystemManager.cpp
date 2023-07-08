//
// Created by duyph on 2023-04-26.
//
#include "GISRecord.h"
#include "Helper.h"
#include "SystemManager.h"


SystemManager::SystemManager(string data_path) {
    // Create new file, or open and erased contents
    _dataFilePath = data_path;

    ofstream dataFile(_dataFilePath);
    if (!dataFile) {
        cout << "Failed to open data file: " << _dataFilePath << "\n";

        _dataFilePath = "./GIS_Data.dat";
        cout << "Using default data file: " << _dataFilePath << "\n";
        ofstream dataFile(_dataFilePath);

        if (!dataFile) {
            cout << "Failed to initial data file: " << _dataFilePath << "\n";
        }
    }
    dataFile.close();
}

void SystemManager::word(vector<string> vector) {

}

void SystemManager::import(vector<string> vector) {
    if (vector.size() != 1) {
        cout << "Number of arguments unmatched" << endl;
        return;
    }

    string importFilePath = vector[0];

    ifstream importFileIFS(importFilePath);
    if (!importFileIFS) {
        std::cout << "Failed to open import file: " << importFilePath << "\n";
        return;
    }

    string line;
    ofstream dataFile(_dataFilePath);

    long curPosition = dataFile.tellp();

    // Read the file line by line
    while (getline(importFileIFS, line)) {
        line = Helper::strip(line);

        if (line ==
            "FEATURE_ID|FEATURE_NAME|FEATURE_CLASS|STATE_ALPHA|STATE_NUMERIC|COUNTY_NAME|COUNTY_NUMERIC|PRIMARY_LAT_DMS|PRIM_LONG_DMS|PRIM_LAT_DEC|PRIM_LONG_DEC|SOURCE_LAT_DMS|SOURCE_LONG_DMS|SOURCE_LAT_DEC|SOURCE_LONG_DEC|ELEV_IN_M|ELEV_IN_FT|MAP_NAME|DATE_CREATED|DATE_EDITED") {
            continue;
        }

        GISRecord record(line);

        if (record.getFeatureName().empty() || record.getStateAlpha().empty()) {
            cout << "Invalid record: " << line << "\n";
            continue;
        }

        // TODO: replace this with our own hashtable
        // Store the ID and position in the hashmap
        string key = record.getHashKey();
        nameIndex[key] = curPosition;

        // TODO: adding new records to the coordinate index
        coordinateIndex.add(record, curPosition);

        // Write the record to the data file
        dataFile << line << endl;

        // update cursor
        curPosition = dataFile.tellp();
    }

    dataFile.close();
    importFileIFS.close();
    cout << "Records imported successfully!\n";
}

void SystemManager::debug(vector<string> vector) {

}

void SystemManager::what_is(vector<string> vector) {
    if (vector.size() != 2) {
        cout << "Number of arguments unmatched" << endl;
        return;
    }

    string recordName = vector[0];
    string recordState = vector[1];

    string key = GISRecord().genHashKey(recordName, recordState);

    // Search for the input key in the hashmap
    auto it = nameIndex.find(key);

    if (it == nameIndex.end()) {
        cout << "Record not found!\n";
        return;
    }

     // Get the position of the record in the data file
    ifstream dataFile(_dataFilePath);

    // Seek to the position of the record in the data file
    long position = it->second;
    dataFile.seekg(position);

    // Read the record from the data file
    string line;
    getline(dataFile, line);
    line = Helper::strip(line);

    GISRecord record(line);
    dataFile.close();

    cout << "Record found" << endl;
    record.println();
}

void SystemManager::what_is_in(vector<string> vector) {

}

void SystemManager::what_is_at(vector<string> vector) {

}

void SystemManager::quit() {
}


