/******************************************************************************
-   earthquake.h
-   Prog Tools for Scits Engrs - CIVL 8903 Homework VII
-
-   File Discreption: class defination of earthquake
-
-   Author: Yang Yang
-
-   Github Repository: https://github.com/SwiftHickory/homework7.git
******************************************************************************/

#ifndef EARTHQUAKE_H
#define EARTHQUAKE_H

#include "myFunction.h"

// case insensitive
enum typeOfMagnitudeType {
    ml,
    ms,
    mb,
    mw
};

enum months {
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

class Earthquake{
public:
    void setEventID(string new_eventID);
    string getEventID();

    void setDate(string new_date);
    string getDate(;

    void setTimeZone(string new_timeZone);
    string getTimeZone();

    void setEarthquakeName(string new_earthquakeName);
    string getEarthqaukeName();

    void setEvlo(double new_evlo);
    double getEvlo();

    void setEvla(double new_evla);
    double getEvla();

    void setEvdp(double new_evdp);
    double getEvdp();

    void setMagnitudeType(string new_magnitudeType);
    string getMagnitudeType();

    void setMagnitude(float new_magnitude);
    float getMagnitude();

private:
    string eventID;
    string date;
    string time;
    string timeZone;
    string earthquakeName;
    months month;
    int day;
    int year;
    int hour;
    int minute;
    int second;
    int millisecond;
    double evlo;
    double evla;
    double evdp;
    typeOfMagnitudeType magnitudeType;
    float magnitude;

    void setTime(string new_time);
    string getTime();

    void setHour(string new_hour);
    string getHour();

    void setMinute(string new_minute);
    string getMinute();

    void setSecond(string new_second);
    string getSecond();

    void setMillisecond(string new_millisecond);
    string getMillisecond();

    void setMonth(string new_month);
    string getMonth();

    void setDay(string new_day);
    string getDay();

    void setYear(string new_year);
    string getYear();

    // return the numer of days in a month
    int daysOfAMonth();
};

// read header can then produce output header
void headerProcessing(ifstream &inputFile, ofstream &outputFile, string outputFileName, Earthquake eq);

#endif