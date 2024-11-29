// Exercise14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Exercise14.h"

Money::Money(long int _dollar, long int _cents) {
    cents = _dollar * 100 + _cents;
}
long int Money::round_to_double(double amount) {
    return static_cast<long int>(round(amount * 100));
}
istream& operator>>(istream& in, Money& m) {
    double input;
    in >> input;
    m.cents = m.round_to_double(input);
    return in;
}

ostream& operator<<(ostream& os, Money& m) {
    int dollars = m.cents / 100;
    int cents = abs(m.cents % 100);
    os<< "$" << dollars << "." << (cents < 10 ? "0" : "") << cents;
    return os;
}

Money Money::operator+(Money& m) {
    return Money(0, cents + m.cents);
}
// Overload the subtraction operator
Money Money::operator-(Money& other){
    return Money(0, cents - other.cents);
}

// Overload the multiplication operator
Money Money::operator*(double factor) {
    return Money(round_to_double((cents / 100.0) * factor));
}

// Overload the division operator
Money Money::operator/(double divisor) {
    if (divisor == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return Money(round_to_double(cents / 100.0 / divisor));
}

// Comparison operators
bool Money::operator==(const Money& other) const { return cents == other.cents; }
bool Money::operator!=(const Money& other) const { return cents != other.cents; }
bool Money::operator<(const Money& other) const { return cents < other.cents; }
bool Money::operator>(const Money& other) const { return cents > other.cents; }
bool Money::operator<=(const Money& other) const { return cents <= other.cents; }
bool Money::operator>=(const Money& other) const { return cents >= other.cents; }

int main() {

    Money m1(123, 45);    // $123.45
    Money m2(100, 50);    // $100.50
    Money m3 = m1 + m2;   // $223.95
    Money m4 = m1 - m2;   // $22.95
    Money m5 = m1 * 1.5;  // $185.18
    Money m6 = m2 / 2.0;  // $50.25

    std::cout << "m1: " << m1 << std::endl;
    std::cout << "m2: " << m2 << std::endl;
    std::cout << "m3 (m1 + m2): " << m3 << std::endl;
    std::cout << "m4 (m1 - m2): " << m4 << std::endl;
    std::cout << "m5 (m1 * 1.5): " << m5 << std::endl;
    std::cout << "m6 (m2 / 2): " << m6 << std::endl;

    return 0;
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
