#include "earthquake.h"
#include "global.h"

void Earthquak::setEventID(string new_eventID) {

    eventID = new_eventID;

}

string Earthquak::getEventID() {

    return eventID;

}

void Earthquak::setDate(string new_date) {

    // the length of date must be 10
    if (new_date.length() == 10) {

        // date format is mm/dd/yyyy
        string new_month = new_date.substr(0, 2);
        string new_day = new_date.substr(3, 2);
        string new_year = new_date.substr(6, 4);

        setYear(new_year);
        setMonth(new_month);
        setDay(new_day);

        // date format is mm/dd/year or mm-dd-year
        if ((new_date[2] != '/' || new_date[5] != '/') && (new_date[2] != '-' || new_date[5] != '-')) {
            printOutput(logFile, "Error: invalid date format of this earthquake!\n", true);
        }

        date = new_date;
    } else {
        printOutput(logFile, "Error: invalid date of this earthquake!\n", true);
    }

}

string getDate() {

    return date;

}

void Earthquak::setTime(string new_time) {

    // the length of time must be 12
    if (new_time.length() == 12) {
        // time format is hh:mm:ss.fff
        string new_hour = new_time.substr(0, 2);
        string new_minute = new_time.substr(3, 2);
        string new_second = new_time.substr(6, 2);
        string new_millisecond = new_time.substr(9, 3);

        setHour(new_hour);
        setMinute(new_minute);
        setSecond(new_second);
        setMillisecond(new_millisecond);

        // check for delimer
        if (new_time[2] != ':' || new_time[5] != ':' || new_time[8] != '.') {
            printOutput(logFile, "Error: invalid time format of this earthquake!\n", true);
        }

        time = new_time;
    } else {
        printOutput(logFile, "Error: invalid time of this earthquake!\n", true);
    }

}

string Earthquak::getTime() {

    return time;

}

void Earthquak::setHour(string new_hour) {

    if (!is_digits(new_hour)) {
        printOutput(logFile, "Error: invalid time hour of this earthquake!\n", true);
    } else {
        hour = atoi(new_hour.c_str());

        if (hour < 0 || hour > 23) {
            printOutput(logFile, "Error: invalid time hour of this earthquake!\n", true);
        }
    }

}

string Earthquak::getHour() {

    return intToString(hour);

}

void Earthquak::setMinute(string new_minute) {

    if (!is_digits(new_minute)) {
        printOutput(logFile, "Error: invalid time minute of this earthquake!\n", true);
    } else {
        minute = atoi(new_minute.c_str());

        if (minute < 0 || minute > 59) {
            printOutput(logFile, "Error: invalid time minute of this earthquake!\n", true);
        }
    }

}

string Earthquak::getMinute() {

    return intToString(minute);

}

void Earthquak::setSecond(string new_second) {

    if (!is_digits(new_second)) {
        printOutput(logFile, "Error: invalid time second of this earthquake!\n", true);
    } else {
        second = atoi(new_second.c_str());

        if (second < 0 || second > 59) {
            printOutput(logFile, "Error: invalid time second of this earthquake!\n", true);
        }
    }

}

string Earthquak::getSecond() {

    return intToString(second);

}

void Earthquak::setMillisecond(string new_millisecond) {

    if (!is_digits(new_millisecond)) {
        printOutput(logFile, "Error: invalid time millisecond of this earthquake!\n", true);
    } else {
        millisecond = atoi(new_millisecond.c_str());

        if (millisecond< 0) {
            printOutput(logFile, "Error: invalid time millisecond of this earthquake!\n", true);
        }
    }

}

string Earthquak::getMillisecond() {

    return intToString(millisecond);

}

void Earthquak::setTimeZone(string new_timeZone) {

    // time zone must be three characters
    if (new_timeZone.length() != 3) {
        printOutput(logFile, "Error: invalid time zone of this earthquake!\n", true);
    } else {
        timeZone = new_timeZone;
    }

}

string Earthquak::getTimeZone() {

    return timeZone;

}

void Earthquak::setEarthquakeName(string new_earthquakeName) {

    eq.earthquakeName = new_earthquakeName;

}

string Earthquak::getEarthqaukeName() {

    return earthquakeName;
}

void Earthquak::setMonth(string new_month) {

    if (new_month == "01") {
        month = January;
        return;
    }

    if (new_month == "02") {
        month = February;
        return;
    }

    if (new_month == "03") {
        month = March;
        return;
    }

    if (new_month == "04") {
        month = April;
        return;
    }

    if (new_month == "05") {
        month = May;
        return;
    }

    if (new_month == "06") {
        month = June;
        return;
    }

    if (new_month == "07") {
        month = July;
        return;
    }

    if (new_month == "08") {
        month = August;
        return;
    }

    if (new_month == "09") {
        month = September;
        return;
    }

    if (new_month == "10") {
        month = October;
        return;
    }

    if (new_month == "11") {
        month = November;
        return;
    }

    if (new_month == "12") {
        month = December;
        return;
    }
    
    printOutput(logFile, "Error: invalid month of this earthquake!\n", true);

}

string Earthquak::getMonth() {

    switch (month) {
        case January:
            return "January";
            break;
        case February:
            return "February";
            break;
        case March:
            return "March";
            break;
        case April:
            return "April";
            break;
        case May:
            return "May";
            break;
        case June:
            return "June";
            break;
        case July:
            return "July";
            break;
        case August:
            return "August";
            break;
        case September:
            return "September";
            break;
        case October:
            return "October";
            break;
        case November:
            return "November";
            break;
        case December:
            return "December";
            break;
    }

}

void Earthquak::setDay(string new_day) {

    // day should be numbers 
    if (!is_digits(new_day)) {
        printOutput(logFile, "Error: invalid date day of this earthquake!\n", true);
     } else {
        day = atoi(new_day.c_str());
        if (day < 0 || day > daysOfAMonth()) {
            printOutput(logFile, "Error: invalid date day of this earthquake!\n", true);
        }
     }

}

string Earthquak::getDay() {

    string day_str = intToString(day);

    if (day_str.length() == 1) {
        day_str = "0" + day;
    }

    return day_str;

}

void Earthquak::setYear(string new_year) {

    // year should be numbers 
    if (!is_digits(new_year)) {
        printOutput(logFile, "Error: invalid date year of this earthquake!\n", true);
     } else {
        year = atoi(new_year.c_str());
     }

}

string Earthquak::getYear() {

    return intToString(year);

}

void Earthquak::setEvlo(double new_evlo) {

    evlo = new_evlo;

}

double Earthquak::getEvlo() {

    return evlo;

}

void Earthquak::setEvla(double new_evla) {

    evla = new_evla;

}

double Earthquak::getEvla() {

    return evla;

}

void Earthquak::setEvdp(double new_evdp) {

    evdp = new_evdp;

}

double Earthquak::getEvdp() {

    return evdp;

}

void Earthquak::setMagnitudeType(string new_magnitudeType) {

    // case insensitive so convert it to lower case first
    new_magnitudeType = lowerString(new_magnitudeType);

    if (new_magnitudeType == "ml") {
        magnitudeType = ml;
        return;
    }

    if (new_magnitudeType == "ms") {
        magnitudeType = ms;
        return;
    }

    if (new_magnitudeType == "mb") {
        magnitudeType = mb;
        return;
    }

    if (new_magnitudeType == "mw") {
        magnitudeType = mw;
        return;
    }

    printOutput(logFile, "Error: invalid magnitude type of this earthquake!\n", true);

}

string Earthquak::getMagnitudeType() {

    switch (magnitudeType) {
        case ml:
            return "ML";
            break;
        case ms:
            return "Ms";
            break;
        case mb:
            return "Mb";
            break;
        case mw:
            return "Mw";
            break;
    }

}

void Earthquak::setMagnitude(float new_magnitude) {

    // magnitude must be a positive number
    if (new_magnitude <= 0) {
        printOutput(logFile, "Error: magnitude must be a positive number\n", true);
    } else {
        magnitude = new_magnitude;
    }

}

float Earthquak::getMagnitude() {

    return magnitude;

}

// return the numer of days in a month
int Earthquak::daysOfAMonth() {

    switch (month) {
        case January:
            return 31;
            break;
        case February:
            return year % 4 == 0 ? 28 :29;
            break;
        case March:
            return 31;
            break;
        case April:
            return 30;
            break;
        case May:
            return 31;
            break;
        case June:
            return 30;
            break;
        case July:
            return 31;
            break;
        case August:
            return 31;
            break;
        case September:
            return 30;
            break;
        case October:
            return 31;
            break;
        case November:
            return 30;
            break;
        case December:
            return 31;
            break;
    }

}

// read header from input file
void headerProcessing(ifstream &inputFile, ofstream &outputFile, string outputFileName, Earthquake eq) {

    string eventID, date, time, timeZone, earthquakeName;
    double evlo, evla, evdp;
    string magnitudeType;
    float magnitude;

    // first line is event ID
    getline(inputFile, eventID);
    eq.setEventID(eventID);

    // second line is date time and time zone
    inputFile >> date >> time >> timeZone;
    eq.setDate(date);
    eq.setTime(time);
    eq.setTimeZone(timeZone);

    // third line is earthquake name
    // avoid the enter key of last line
    getline(inputFile, earthquakeName);
    getline(inputFile, earthquakeName);
    eq.setEarthquakeName(earthquakeName);

    // forth line is events information
    inputFile >> evlo >> evla >> evdp >> magnitudeType >> magnitude;
    eq.setEvlo(evlo);
    eq.setEvla(evla);
    eq.setEvdp(evdp);
    eq.setMagnitudeType(magnitudeType);
    eq.setMagnitude(magnitude);

    // if all the infomation are correct, then write output header
    openOutput(outputFile, outputFileName);

    outputFile << "# " << eq.getDay() << " " << eq.getMonth() << " " << eq.getYear() << " ";
    outputFile << eq.getTime() << " " << eq.getTimeZone() << " " << eq.getMagnitudeType() << " " << eq.getMagnitude() << " ";
    outputFile << eq.getEarthqaukeName() << " [" << eq.getEventID() << "] (";
    outputFile << eq.getEvlo() << ", " << eq.getEvla() << ", " << eq.getEvdp() << ")" << endl;

}