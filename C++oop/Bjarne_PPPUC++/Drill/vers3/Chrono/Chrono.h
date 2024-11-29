#pragma once
#include <iostream>
using namespace std;
class Date {
public:
	Date();
	Date(int m, int d, int y);
	void add_day();
	friend ostream& operator<<(ostream& os, Date& dd);
private:
	int month;
	int day;
	int year;
};

