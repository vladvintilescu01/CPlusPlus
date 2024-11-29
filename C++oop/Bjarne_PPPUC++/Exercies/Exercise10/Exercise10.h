#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;
namespace Chrono {
	enum class Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};
	enum class Day {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};
	class Date {
	public:
		class Invalid { }; // to throw as exception
		Date(int y, Month m, int d); // check for valid date and initialize
		Date(); // default constructor
		// the default copy operations are fine
		// nonmodifying operations:
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }
		string convert_month_to_string() const;
		// modifying operations:
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);

		Day day_of_week() const;
		Date next_workday();
		int week_of_year();
	private:
		int y;
		Month m;
		int d;
	};
	bool is_date(int y, Month m, int d); // true for valid date
	bool leapyear(int y); // true if y is a leap year
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);
	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date& dd);
} // Chrono