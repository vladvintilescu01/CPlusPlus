// Chrono.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Chrono.h"
using namespace std;
Date::Date() {
    month = Month::feb;
    day = 4;
    year = 2003;
}
Date::Date(Month m, int d, int y) {
    if (m >= Month::feb && m <= Month::dec && d >= 1 && d <= 31) {
        month = m;
        day = d;
        year = y;
    }
    else {
        throw invalid_argument("invalid date");
    }
}
void Date::add_day() {
    if (month == Month::dec && day == 31) {
        day = 1;
        month = Month::jan;
        year += 1;
    }
    else if (day == 31) {
        day = 1;
        month = static_cast<Month>((static_cast<int>(month) + 1) % 12);;
    }
    else {
        day += 1;
    }
}
ostream& operator<<(ostream& os, Date& dd) {
    os << month_to_string(dd.month) << "-" << dd.day << "-" << dd.year;
    return os;
}
string month_to_string(Month m) {
    switch (m) {
    case Month::jan: return "Jan";
    case Month::feb: return "Feb";
    case Month::mar: return "Mar";
    case Month::apr: return "Apr";
    case Month::may: return "May";
    case Month::jun: return "Jun";
    case Month::jul: return "Jul";
    case Month::aug: return "Aug";
    case Month::sep: return "Sep";
    case Month::oct: return "Oct";
    case Month::nov: return "Nov";
    case Month::dec: return "Dec";
    default: return "Unknown";
    }
}
int main()
{ try{
    Date today{ Month::dec,31,1988 };
    Date tomorrow;
    tomorrow = today;
    tomorrow.add_day();
    std::cout << today << "\n";
    std::cout << tomorrow << "\n";
}
catch (invalid_argument& e) {
    cerr << "error: " << e.what() << endl;
    }
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
