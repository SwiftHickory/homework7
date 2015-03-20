#include "station.h"
#include "global.h"

bool Station::setNetworkCode(string new_networkCode) {

	if (new_networkCode == "CE") {
        networkCode = CE;
        return true;
    }

    if (new_networkCode == "CI") {
        networkCode = CI;
        return true;
    }

    if (new_networkCode == "FA") {
        networkCode = FA;
        return true;
    }

    if (new_networkCode == "NP") {
        networkCode = NP;
        return true;
    }

    if (new_networkCode == "WR") {
        networkCode = WR;
        return true;
    }

    // otherwise it's a invalid network
    return false;

}

string Station::getNetworkCode() {

	switch (networkCode) {
        case CE:
            return "CE";
            break;
        case CI:
            return "CI";
            break;
        case FA:
            return "FA";
            break;
        case NP:
            return "NP";
            break;
        case WR:
            return "WR";
            break;
    }

}

bool Station::setStationCode(string new_stationCode) {

	// station code must be 3 captital letters or 5 numeric characters
    if (new_stationCode.length() == 5 && is_digits(new_stationCode)) {
    	stationCode = new_stationCode;
        return true;
    }

    if (new_stationCode.length() == 3) {
        if (isupper(new_stationCode[0]) && isupper(new_stationCode[1]) && isupper(new_stationCode[2])) {
        	stationCode = new_stationCode;
            return true;
        }
    }

    return false;

}

string Station::getStationCode() {

	return stationCode;

}

bool Station::setBandType(string new_bandType) {

	// case insensitive so convert it to lower case first
    new_bandType = lowerString(new_bandType);

    if (new_bandType == "long-period") {
        typeOfBand = longperiod;
        return true;
    }

    if (new_bandType == "short-period") {
        typeOfBand = shortperiod;
        return true;
    }

    if (new_bandType == "broadband") {
        typeOfBand = broadband;
        return true;
    }

    return false;

}

string Station::getBandType() {

	switch (typeOfBand) {
        case longperiod:
            return "L";
            break;
        case shortperiod:
            return "B";
            break;
        case broadband:
            return "H";
            break;
    }

}

bool Station::setInstrumentType(string new_instrumentType) {

	// case insensitive so convert it to lower case first
    new_instrumentType = lowerString(new_instrumentType);

    if (new_instrumentType == "high-gain") {
        typeOfInstrument = highgain;
        return true;
    }

    if (new_instrumentType == "low-gain") {
        typeOfInstrument = lowgain;
        return true;
    }

    if (new_instrumentType == "accelerometer") {
        typeOfInstrument = accelerometer;
        return true;
    }

    return false;

}

string Station::getInstrumentType() {

	switch (typeOfInstrument) {
        case highgain:
            return "H";
            break;
        case lowgain:
            return "L";
            break;
        case accelerometer:
            return "N";
            break;
    }

}

bool Station::setOrientation(string str) {

	// case insensitive so convert it to lower case first
    str = lowerString(str);

    if (str.length() < 4) {
        if (isdigit(str[0])) {
            for (int i = 0; i < str.length(); i++) {
                if (str[i] != '1' && str[i] != '2' && str[i] != '3') {
                    return false;
                }
            }

            orientation =  str;

            return true;
        } else if (islower(str[0])) {
            for (int i = 0; i < str.length(); i++) {
                if (str[i] != 'n' && str[i] != 'e' && str[i] != 'z') {
                    return false;
                }
            }

            orientation = str;

            return true;
        }
    }

    return false;

}

string Station::getOrientation() {

	return upperString(orientation);

}

// read table and then produce output
void tableProcessing(ifstream &inputFile, ofstream &outputFile, Earthquake eq) {

    int numberOfValidEntries = 0;
    int numberOfEntryRead = 0;
    int numberOfSignals = 0;
    string networkCode;
    bool isValidEntry = true;
    static const int maximumValidEntries = 300;
    Station entry[maximumValidEntries];

    // read the file to the end of the file or reach maximum valid entry number
    while (inputFile >> networkCode && numberOfValidEntries < maximumValidEntries) {
        numberOfEntryRead++;

        if (processOneEntry(inputFile, entry[numberOfValidEntries], numberOfEntryRead, networkCode)) {
            string orientation = entry[numberOfValidEntries].getOrientation();
            numberOfSignals += orientation.length();
            numberOfValidEntries++;;
        }
    }

    outputFile << numberOfSignals << endl;
    
    // print all the signals to output file
    for (int i = 0; i < numberOfValidEntries; i++) {
    	string orientation = entry[i].getOrientation();

        for (int j = 0; j < orientation.length(); j++) {
            stringstream singalStream;
            singalStream << eq.getEventID() << ".";
            singalStream << entry[i].getNetworkCode() << ".";
            singalStream << entry[i].getStationCode() << ".";
            singalStream << entry[i].getBandType();
            singalStream << entry[i].getInstrumentType();
            singalStream << orientation[j] << endl;

            outputFile << singalStream.str();
        }
    }

    printOutput(logFile, "Total invalid entries ignored: " + intToString(numberOfEntryRead - numberOfValidEntries) + "\n");
    printOutput(logFile, "Totoal valid entries read: " + intToString(numberOfValidEntries) + "\n");
    printOutput(logFile, "Total singal names produced: " + intToString(numberOfSignals) + "\n");

}

// read and processing one entry
bool processOneEntry(ifstream &inputFile, Station &entry, int entryNumber, string networkCode) {

    string stationCode, typeOfInstrument, typeOfBand, orientation;
    bool isValidEntry = true;

    // convert networkCode to enum type
    if (!entry.setNetworkCode(networkCode)) {
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid network.\n");
        isValidEntry = false;
    }

    // read station code
    inputFile >> stationCode;
    if (!entry.setStationCode(stationCode)) {
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid station code.\n");
        isValidEntry = false;
    }

	// read type of band
    inputFile >> typeOfBand;
    if (!entry.setBandType(typeOfBand)) {
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid band type.\n");
        isValidEntry = false;
    }

    // read type of instrument
    inputFile >> typeOfInstrument;
    if (!entry.setInstrumentType(typeOfInstrument)) {
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid instrument type.\n");
        isValidEntry = false;
    }

    // read orientation
    inputFile >> orientation;
    if (!entry.setOrientation(orientation)) {
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid orientation.\n");
        isValidEntry = false;
    }

    return isValidEntry;

}