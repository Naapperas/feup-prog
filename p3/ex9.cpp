#include <iostream>
#include <iomanip>
#include <assert.h>
#include <cmath>

using namespace std;

enum Month {
    January = 1, February, March, April, May, June, July, August, September, October, November, December
};

bool isLeap(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int getNumDays(int month, int year) {

    assert(month > 0 && month <= 12); // 

    if (month == 2) {
        return isLeap(year) ? 29 : 28;
    }

    switch (month) {

        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
    }

    return 30;
}

int getWeekDay(int year, int month, int day) {

    int ds = 0;

    double a = year % 100;
    int s = year / 100;
    
    ds += floor((5 * a) / 4);

    int c;

    switch (month) {

        case 1:
            c = (isLeap(year) ? 6 : 0);
            break;
        case 2:
            c = (isLeap(year) ? 2 : 3);
            break;
        case 3:
            c = 3;
            break;
        case 4:
            c = 6;
            break;
        case 5:
            c = 1;
            break;
        case 6:
            c = 4;
            break;
        case 7:
            c = 6;
            break;
        case 8:
            c = 2;
            break;
        case 9:
            c = 5;
            break;
        case 10:
            c = 0;
            break;
        case 11:
            c = 3;
            break;
        case 12:
            c = 5;
            break;
        default:
            break; 
    }

    ds += c;

    ds += day;

    ds -= (2 * (s % 4));

    ds += 7;

    ds %= 7;

    return ds;
}

void showCalendar(int month, int year, ostream& o) { 

    string months;

    switch (month) {
        
        case January:
            months = "January";
            break;
        case February:
            months = "February";
            break;
        case March:
            months = "March";
            break;
        case April:
            months = "April";
            break;
        case May:
            months = "May";
            break;
        case June:
            months = "June";
            break;
        case July:
            months = "July";
            break;
        case August:
            months = "August";
            break;
        case September:
            months = "September";
            break;
        case October:
            months = "October";
            break;
        case November:
            months = "November";
            break;
        case December:
            months = "December";
            break;
        default:
            months = "";
    }

    int numDays = getNumDays(month, year);

    o << months << "/" << year << "\n";
    o << "Sun\tMon\tTue\tWed\tThu\tFri\tSat\n";

    o << '\n';

    for (auto i = 0; i < numDays + (getWeekDay(year, month, 1) - 1); i++) {
        if (i != 0 && i % 7 == 0)
            o << '\n';

        int dayNum = (i - getWeekDay(year, month, 1) + 1);

        if (dayNum < 9) o << ' ';
        if (dayNum < 0) o << '\t';
        else o << (dayNum + 1) << '\t';
    }
    o << "\n";

    o << endl;
}   

void showAnualCalendar(int year, ostream& o) {
    for (int i = 1; i <= 12; i++) {
        showCalendar(i, year, o);
        o << "\n";
    }
}

int main() {    

    int year;
    cout << "Show the calendar of the year: ";
    cin >> year;

    showAnualCalendar(year, cout);

    return 0;
}