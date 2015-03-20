#include "myFunction.h"
#include "global.h"

// function to open input file
void openInput(ifstream &inputFile, string fileName) {

    inputFile.open(fileName.c_str());

    // perform sanity check it
    if (!inputFile.is_open()) {
        printOutput(logFile, "Cannot open input file: " + fileName + "\n", true);
    }

}

// function to open output file
void openOutput(ofstream &outputFile, string fileName) {

    outputFile.open(fileName.c_str());

    // perform sanity check it
    if (!outputFile.is_open()) {
        if (fileName == logFileName) {
            // if we can open error file, just print out to terminal
            cout << "Cannot open log file: " << logFileName << endl;
        } else {
            printOutput(logFile, "Cannot open output file: " + fileName + "\n", true);
        }
    }

}

// check whether a string contains only digits
bool is_digits(string str) {

    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;

}

// change all the letters in a string to lower case
string lowerString(string str) {

    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }

    return str;

}

// change all the letters in a string to upper case
string upperString(string str) {

    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }

    return str;

}

// convert a int string
string intToString(int num) {

    ostringstream numStream;
    numStream << num;

    return numStream.str();

}

// print messeage to both terminal and a file
void printOutput(ofstream &outputFile, const string &message, bool needExit, string fileName) {

    // if output file is not opened, it is error file. Open it first
    if (!outputFile.is_open()) {
        openOutput(outputFile, fileName);
    }

    cout << message;
    outputFile << message;

    if (needExit) {
        exit(EXIT_FAILURE);
    }

}

// deal with some left things to exit program safely
void finishProgram() {

	// if open error file, close it
    if (logFile.is_open()) {
        logFile.close();
    }

}