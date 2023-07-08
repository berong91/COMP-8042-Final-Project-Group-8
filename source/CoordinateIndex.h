//
// Created by duyph on 2023-04-26.
//

#ifndef COORDINATEINDEX_H
#define COORDINATEINDEX_H


#include "GISRecord.h"

class CoordinateIndex {
public:
    CoordinateIndex() = default;

    void add(GISRecord record, long i);

private:
    CoordinateIndex coordinateRegion[4];
    int index;
    long position;

};


#endif //COORDINATEINDEX_H
