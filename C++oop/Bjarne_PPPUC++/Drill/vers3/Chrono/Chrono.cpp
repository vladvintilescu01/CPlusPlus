// Chrono.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Chrono.h"
using namespace std;
Date::Date() {
    month = 2;
    day = 4;
    year = 2003;
}
Date::Date(int m, int d, int y) {
    if (m >= 1 && m <= 12 && d >= 1 && d <= 31) {
        month = m;
        day = d;
        year = y;
    }
}
void Date::add_day() {
    if (month == 12 && day == 31) {
        day = 1;
        month = 1;
        year += 1;
    }
    else if (day == 31) {
        day = 1;
        month += 1;
    }
    else {
        day += 1;
    }
}
ostream& operator<<(ostream& os, Date& dd) {
    os << dd.month << "-" << dd.day << "-" << dd.year;
    return os;
}
int main()
{
    Date today{6,25,1988};
    Date tomorrow;
    tomorrow = today;
    tomorrow.add_day();
    std::cout << today << "\n";
    std::cout << tomorrow;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
