/******************************************************************************
-   myFunction.h
-   Prog Tools for Scits Engrs - CIVL 8903 Homework VI
-
-   File Discreption: functions used in this program
-
-   Author: Yang Yang
-
-   Github Repository: https://github.com/SwiftHickory/homework6.git
******************************************************************************/

#ifndef MYFUNCTION_H
#define MYFUNCTION_H

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "global.h"

using namespace std;

// function to open input file
void openInput(ifstream &inputFile, string fileName);

// function to open output file
void openOutput(ofstream &outputFile, string fileName);

// check whether a string contains only digits
bool is_digits(string str);

// change all the letters in a string to lower case
string lowerString(string str);

// change all the letters in a string to upper case
string upperString(string str);

// convert a int to string
string intToString(int num);

// print messeage to both terminal and a file
void printOutput(ofstream &outputFile, const string &message, bool needExit = false, string fileName = logFileName);

// deal with some left things to exit program safely
void finishProgram();

#endif