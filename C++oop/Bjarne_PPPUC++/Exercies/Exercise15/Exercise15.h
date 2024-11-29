#pragma once
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <map>
#include <string>
using namespace std;
class Money {
public:
	Money() {cents = 0;}
	Money(long int _dollar, long int _cents, string _currency);
	Money(double amount, string _currency);
	static void set_conversion_table(const string& from, const string& to, double rate);
	static double get_conversion_table(string& from, string& to);
	friend istream& operator>>(istream& in, Money& m);
	friend ostream& operator<<(ostream& os, Money& m);
	Money operator-(Money& other);
	Money operator+(Money& m);
	Money operator*(double factor);
	Money operator/(double divisor);
	bool operator==(const Money& other) const;
	bool operator!=(const Money& other) const;
	bool operator<(const Money& other) const;
	bool operator>(const Money& other) const;
	bool operator<=(const Money& other) const;
	bool operator>=(const Money& other) const;
private:
	long int round_to_double(double amount);
	long int cents;
	string currency;
	static map<pair<string, string>, double> conversion_table;
};