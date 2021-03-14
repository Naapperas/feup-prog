#include <iostream>
#include <assert.h>

using namespace std;

bool isLeap(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int numDays(int month, int year) {

    assert(month >= 0 && month < 12); // 

    if (month == 1) {
        return isLeap(year) ? 29 : 28;
    }

    switch (month) {

        case 0:
        case 2:
        case 4:
        case 6:
        case 7:
        case 9:
        case 11:
            return 31;
    }

    return 30;
}

int main(){



    return 0;
}