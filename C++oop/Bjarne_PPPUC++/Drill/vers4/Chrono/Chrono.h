#pragma once
#include <iostream>
using namespace std;
enum class Month {
	jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
class Date {
public:
	Date();
	Date(Month m, int d, int y);
	void add_day();
	friend ostream& operator<<(ostream& os, Date& dd);
	
private:
	Month month;
	int day;
	int year;
};
string month_to_string(Month m);

