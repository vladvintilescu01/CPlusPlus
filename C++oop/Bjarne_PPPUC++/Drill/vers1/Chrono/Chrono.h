#pragma once
struct Date {
	int month;
	int day;
	int year; 
};
void init_day(Date& dd, int y, int m, int d);
void add_day(Date& dd);