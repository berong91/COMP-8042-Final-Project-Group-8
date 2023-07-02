//
// Created by duyph on 2023-04-26.
//

#ifndef GISRECORD_H
#define GISRECORD_H

#include <string>

using namespace std;

class GISRecord {
public:
    GISRecord() = default;

    GISRecord(const string &line);

    string getFeatureId() const;

    string getFeatureName() const;

    string getFeatureClass() const;

    string getStateAlpha() const;

    string getStateNumeric() const;

    string getCountyName() const;

    string getCountyNumeric() const;

    string getPrimaryLatDms() const;

    string getPrimLongDms() const;

    string getPrimLatDec() const;

    string getPrimLongDec() const;

    string getSourceLatDms() const;

    string getSourceLongDms() const;

    string getSourceLatDec() const;

    string getSourceLongDec() const;

    string getElevInM() const;

    string getElevInFt() const;

    string getMapName() const;

    string getDateCreated() const;

    string getDateEdited() const;

    string getHashKey();

    string genHashKey(string featureName, string stateAlpha);

    void println();

private:
    string featureId;
    string featureName;
    string featureClass;
    string stateAlpha;
    string stateNumeric;
    string countyName;
    string countyNumeric;
    string primaryLatDms;
    string primLongDms;
    string primLatDec;
    string primLongDec;
    string sourceLatDms;
    string sourceLongDms;
    string sourceLatDec;
    string sourceLongDec;
    string elevInM;
    string elevInFt;
    string mapName;
    string dateCreated;
    string dateEdited;
};

#endif //GISRECORD_H
