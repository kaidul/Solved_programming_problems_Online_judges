#include <bits/stdc++.h>

using namespace std;

bool isLeapYear(int year) {
    if ( year % 400 == 0) return true;
    if ( year % 100 == 0) return false;
    if ( year % 4 == 0 ) return true;
    return false;
}

map <int, int> monthTable;

bool isSunday (int year, int month, int day) {
    int lastTwo = year % 100;
    int century = year / 100;
    int monthTableValue;
    if (isLeapYear(year) and (month == 1 or month == 2)) {
        monthTableValue = monthTable[month] - 1;
    } else {
        monthTableValue = monthTable[month];
    }
    int c = 0;
    switch (century % 4) {
    case 0:
        c = 6;
        break;
    case 1:
        c = 4;
        break;
    case 2:
        c = 2;
        break;
    case 3:
        c = 0;
        break;
    default:
        break;
    }
    int days = ( day + monthTableValue + lastTwo + int (floor(lastTwo / 4)) +  c) % 7;
    if (days == 0)
        return true;
    return false;
}

int main(int argc, char **argv) {
    monthTable[1] = 0;
    monthTable[2] = 3;
    monthTable[3] = 3;
    monthTable[4] = 6;
    monthTable[5] = 1;
    monthTable[6] = 4;
    monthTable[7] = 6;
    monthTable[8] = 2;
    monthTable[9] = 5;
    monthTable[10] = 0;
    monthTable[11] = 3;
    monthTable[12] = 5;
    int total = 0;
    for(int year = 1901; year <= 2000; year++) {
        for(int month = 1; month <= 12; month++) {
            if( isSunday(year, month, 1) ) total++;
        }
    }
    printf("%d\n", total);
    return 0;
}
