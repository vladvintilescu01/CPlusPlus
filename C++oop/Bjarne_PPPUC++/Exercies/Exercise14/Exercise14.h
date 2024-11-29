#pragma once
#include <iostream>
using namespace std;
class Money {
public:
	Money() {
		cents = 0;
	}
	Money(long int _dollar, long int _cents);
	Money(double amount) {
		cents = round_to_double(amount);
	}
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
};