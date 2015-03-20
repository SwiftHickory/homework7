/******************************************************************************
-   station.h
-   Prog Tools for Scits Engrs - CIVL 8903 Homework VII
-
-   File Discreption: class defination of station
-
-   Author: Yang Yang
-
-   Github Repository: https://github.com/SwiftHickory/homework7.git
******************************************************************************/

#ifndef STATION_H
#define STATION_H

#include "earthquake.h"

// case sensitive
enum networkCodeType {
    CE,
    CI,
    FA,
    NP,
    WR
};

// case insensitive
enum typeOfBandType {
    longperiod,  // L
    shortperiod,  // B
    broadband  // H
};

// case insensitive
enum typeOfInstrumentType {
    highgain,  // H
    lowgain,  // L
    accelerometer  // N
};

class Station {
public:
    bool setNetworkCode(string new_networkCode);
    string getNetworkCode();

    bool setStationCode(string new_stationCode);
    string getStationCode();

    bool setBandType(string new_bandType);
    string getBandType();

    bool setInstrumentType(string new_instrumentType);
    string getInstrumentType();

    bool setOrientation(string new_orientation);
    string getOrientation();

private:
    networkCodeType networkCode;
    string stationCode;
    typeOfBandType typeOfBand;
    typeOfInstrumentType typeOfInstrument;
    string orientation;  // one to three characters, case insensitive
};

// read table and then produce output
void tableProcessing(ifstream &inputFile, ofstream &outputFile, Earthquake eq);

// read and processing one entry
bool processOneEntry(ifstream &inputFile, Station &entry, int entryNumber, string networkCode);

#endif