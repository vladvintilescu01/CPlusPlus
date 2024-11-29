// Chrono.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Chrono.h"
using namespace std;
void init_day(Date& dd, int m, int d, int y) {
    if (m >= 1 && m <= 12 && d >= 1 && d <= 31) {
        dd.month = m;
        dd.day = d;
        dd.year = y;
    }
}
void add_day(Date& dd) {
    if (dd.month == 12 && dd.day == 31) {
        dd.day = 1;
        dd.month = 1;
        dd.year += 1;
    }
    else if (dd.day == 31) {
        dd.day = 1;
        dd.month += 1;
    }
    else {
        dd.day += 1;
    }
}
ostream& operator<<(ostream& os, Date& dd) {
    os << dd.month << "-" << dd.day << "-" << dd.year;
    return os;
}
int main()
{
    Date today;
    init_day(today,6,25,1978 );
    Date tomorrow;
    tomorrow = today;
    add_day(tomorrow);
    std::cout << today <<"\n";
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
