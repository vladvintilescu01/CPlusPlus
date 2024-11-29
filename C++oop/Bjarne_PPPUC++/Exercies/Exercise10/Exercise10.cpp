#include "Exercise10.h"
namespace Chrono {
	// member function definitions:
	Date::Date(int yy, Month mm, int dd)
		: y{ yy }, m{ mm }, d{ dd }
	{
		if (!is_date(yy, mm, dd)) throw invalid_argument("data scrisa incorect!!!");
	}
	const Date& default_date()
	{
		static Date dd{ 2001,Month::jan,1 }; // start of 21st century
		return dd;
	}
	Date::Date()
		:y{ default_date().year() },
		m{ default_date().month() },
		d{ default_date().day() }
	{
	}
	string Date::convert_month_to_string() const {
		string month = "";
		switch (m) {
		case Month::jan:
			month = "january";
			break;
		case Month::feb:
			month = "february";
			break;
		case Month::mar:
			month = "march";
			break;
		case Month::apr:
			month = "april";
			break;
		case Month::may:
			month = "may";
			break;
		case Month::jun:
			month = "june";
			break;
		case Month::jul:
			month = "july";
			break;
		case Month::aug:
			month = "august";
			break;
		case Month::sep:
			month = "september";
			break;
		case Month::oct:
			month = "october";
			break;
		case Month::nov:
			month = "november";
			break;
		case Month::dec:
			month = "december";
			break;
		}
		return month;
	}
	void Date::add_day(int n)
	{
		d = d + n;
	}
	void Date::add_month(int n)
	{
		
	}
	void Date::add_year(int n)
	{
		if (m == Month::feb && d == 29 && !leapyear(y + n)) { // beware of leap years!
			m = Month::mar; // use March 1 instead of February 29
			d = 1;
		}
		y += n;
	}
	// helper functions:
	bool is_date(int y, Month m, int d)
	{
		// assume that y is valid
		if (d <= 0) return false; // d must be positive
		if (m < Month::jan || Month::dec < m) return false;
		int days_in_month = 31; // most months have 31 days
		switch (m) {
		case Month::feb: // the length of February varies
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days_in_month = 30; // the rest have 30 days
			break;
		}
		if (days_in_month < d) return false;
		return true;
	}
	bool leapyear(int y)
	{
		// exercise 10
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
			return true;
		}
		return false;
	}
	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}
	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}
	ostream& operator<<(ostream& os, const Date& d)
	{
		return os << '(' << d.year()
			<< ',' << d.convert_month_to_string()
			<< ',' << d.day() << ')';
	}
	istream& operator>>(istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') { // oops: format error
			is.clear(ios_base::failbit); // set the fail bit
			return is;
		}
		dd = Date(y, Month(m), d); // update dd
		return is;
	}
	
	//Day day_of_week(const Date& d)
	//{
	//	// . . .
	//}
	//Date next_Sunday(const Date& d)
	//{
	//	// ...
	//}
	//Date next_weekday(const Date& d)
	//{
	//	// . . .
	//}
	Day Date::day_of_week() const {
    // Zeller's Congruence algorithm for calculating day of the week
    int m = int(this->m);
    int y = this->y;
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    int k = y % 100;
    int j = y / 100;
    int day_of_week = (d + 13 * (m + 1) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
    return static_cast<Day>((day_of_week + 6) % 7);
}
	Date Date::next_workday() {
		//int next_day;
		switch (day_of_week()) {
		case Day::friday:
			add_day(3);
			return *this;
		case Day::saturday:
			add_day(2);
			return *this;
		default:
			add_day(1);
			return *this;
		}
	}
	int Date::week_of_year() {
		int days_of_month = 31;
		switch (month()) {
		case Month::feb: // the length of February varies
			days_of_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days_of_month = 30; // the rest have 30 days
			break;
		}
		Date initial_date{ y, Month::jan, 1 };
		int initial = static_cast<int>(initial_date.day_of_week());
		return (days_of_month + initial) / 7 + 1;
	}
} // Chrono
int main() {
	using namespace Chrono;
	try {
		Date today{ 2024, Month::nov, 11 };
		cout << "Today: " << today << "\n";
		cout << "Next workday: " << today.next_workday() << "\n";
		cout << "Week of the year: " << today.week_of_year() << "\n";
	}
	catch (invalid_argument& e) {
		cerr << "Error: " << e.what() << '\n';
	}
	return 0;
}