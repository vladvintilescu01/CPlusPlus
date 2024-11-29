#pragma once
struct Date {
	int month;
	int day;
	int year;
	Date();
	Date(int y, int m, int d);
	void add_day();
};

