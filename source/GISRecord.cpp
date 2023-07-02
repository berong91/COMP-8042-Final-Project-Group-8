//
// Created by duyph on 2023-04-26.
//

#include "GISRecord.h"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>


using namespace std;

GISRecord::GISRecord(const string &line) {
    vector<string> tokens;
    stringstream ss(line);
    string token;

    while (getline(ss, token, '|')) {
        tokens.push_back(token);
    }

    if (tokens.size() == 19) {
        featureId = tokens[0];
        featureName = tokens[1];
        featureClass = tokens[2];
        stateAlpha = tokens[3];
        stateNumeric = tokens[4];
        countyName = tokens[5];
        countyNumeric = tokens[6];
        primaryLatDms = tokens[7];
        primLongDms = tokens[8];
        primLatDec = tokens[9];
        primLongDec = tokens[10];
        sourceLatDms = tokens[11];
        sourceLongDms = tokens[12];
        sourceLatDec = tokens[13];
        sourceLongDec = tokens[14];
        elevInM = tokens[15];
        elevInFt = tokens[16];
        mapName = tokens[17];
        dateCreated = tokens[18];
        dateEdited = tokens[19];
    }

}

string GISRecord::getFeatureId() const {
    return featureId;
}

string GISRecord::getFeatureName() const {
    return featureName;
}

string GISRecord::getFeatureClass() const {
    return featureClass;
}

string GISRecord::getStateAlpha() const {
    return stateAlpha;
}

string GISRecord::getStateNumeric() const {
    return stateNumeric;
}

string GISRecord::getCountyName() const {
    return countyName;
}

string GISRecord::getCountyNumeric() const {
    return countyNumeric;
}

string GISRecord::getPrimaryLatDms() const {
    return primaryLatDms;
}

string GISRecord::getPrimLongDms() const {
    return primLongDms;
}

string GISRecord::getPrimLatDec() const {
    return primLatDec;
}

string GISRecord::getPrimLongDec() const {
    return primLongDec;
}

string GISRecord::getSourceLatDms() const {
    return sourceLatDms;
}

string GISRecord::getSourceLongDms() const {
    return sourceLongDms;
}

string GISRecord::getSourceLatDec() const {
    return sourceLatDec;
}

string GISRecord::getSourceLongDec() const {
    return sourceLongDec;
}

string GISRecord::getElevInM() const {
    return elevInM;
}

string GISRecord::getElevInFt() const {
    return elevInFt;
}

string GISRecord::getMapName() const {
    return mapName;
}

string GISRecord::getDateCreated() const {
    return dateCreated;
}

string GISRecord::getDateEdited() const {
    return dateEdited;
}

void GISRecord::println() {
    cout << "FeatureId: " + getFeatureId() << endl;
    cout << "FeatureName: " + getFeatureName() << endl;
    cout << "FeatureClass: " + getFeatureClass() << endl;
    cout << "StateAlpha: " + getStateAlpha() << endl;
    cout << "StateNumeric: " + getStateNumeric() << endl;
    cout << "CountyName: " + getCountyName() << endl;
    cout << "CountyNumeric: " + getCountyNumeric() << endl;
    cout << "PrimaryLatDms: " + getPrimaryLatDms() << endl;
    cout << "PrimLongDms: " + getPrimLongDms() << endl;
    cout << "PrimLatDec: " + getPrimLatDec() << endl;
    cout << "PrimLongDec: " + getPrimLongDec() << endl;
    cout << "SourceLatDms: " + getSourceLatDms() << endl;
    cout << "SourceLongDms: " + getSourceLongDms() << endl;
    cout << "SourceLatDec: " + getSourceLatDec() << endl;
    cout << "SourceLongDec: " + getSourceLongDec() << endl;
    cout << "ElevInM: " + getElevInM() << endl;
    cout << "ElevInFt: " + getElevInFt() << endl;
    cout << "MapName: " + getMapName() << endl;
    cout << "DateCreated: " + getDateCreated() << endl;
    cout << "DateEdited: " + getDateEdited() << endl;
}

string GISRecord::getHashKey() {
    // TODO: Apply hash function to retrieve the key
    return getFeatureName() + "|" + getStateAlpha();
}

string GISRecord::genHashKey(string featureName, string stateAlpha) {
    // TODO: Apply hash function to retrieve the key
    return featureName + "|" + stateAlpha;
}


