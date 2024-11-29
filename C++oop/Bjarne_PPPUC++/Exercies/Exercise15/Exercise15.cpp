// Exercise14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Exercise15.h"
map<pair<string, string>, double> Money::conversion_table;

Money::Money(long int _dollar, long int _cents, string _currency) {
    currency = _currency;
    cents = _dollar * 100 + _cents;
}
Money::Money(double amount, string _currency) {
    currency = _currency;
    long int rounded_amount = round_to_double(amount);
    if (amount * 100 - rounded_amount > 0.0001) {
        throw invalid_argument("Cannot exactly represent the amount in cents.");
    }
    cents = rounded_amount;
}
long int Money::round_to_double(double amount) {
    return static_cast<long int>(round(amount * 100));
}
void Money::set_conversion_table(const string& from, const string& to, double rate) {
    conversion_table[{from, to}] = rate;
    conversion_table[{to, from}] = 1 / rate;
}
double Money::get_conversion_table(string& from, string& to) {
    if (from == to) {
        return 1.0;
    }
    else {
        auto temp = conversion_table.find({from,to});
        if (temp != conversion_table.end()) {
            return temp->second;
        }
    }
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
    os << "$" << dollars << "." << (cents < 10 ? "0" : "") << cents;
    return os;
}

Money Money::operator+(Money& m) {
    if (currency == m.currency) {
        return Money(0, cents + m.cents,currency);
    }
    else {
        double get_conv = get_conversion_table(m.currency, currency);
        long int converted_cents = static_cast<long int>(m.cents * get_conv);
        return Money(0, cents + converted_cents, currency);
    }
}
// Overload the subtraction operator
Money Money::operator-(Money& m) {
    if (currency == m.currency) {
        return Money(0, cents - m.cents, currency);
    }
    else {
        double get_conv = get_conversion_table(m.currency, currency);
        long int converted_cents = static_cast<long int>(m.cents * get_conv);
        return Money(0, cents - converted_cents, currency);
    }
}
//
//// Overload the multiplication operator
//Money Money::operator*(double factor) {
//    return Money(round_to_double((cents / 100.0) * factor));
//}
//
//// Overload the division operator
//Money Money::operator/(double divisor) {
//    if (divisor == 0) {
//        throw std::invalid_argument("Division by zero");
//    }
//    return Money(round_to_double(cents / 100.0 / divisor));
//}

// Comparison operators
bool Money::operator==(const Money& other) const { return cents == other.cents; }
bool Money::operator!=(const Money& other) const { return cents != other.cents; }
bool Money::operator<(const Money& other) const { return cents < other.cents; }
bool Money::operator>(const Money& other) const { return cents > other.cents; }
bool Money::operator<=(const Money& other) const { return cents <= other.cents; }
bool Money::operator>=(const Money& other) const { return cents >= other.cents; }

int main() {
    try {
        // Setting up conversion rates
        Money::set_conversion_table("USD", "EUR", 0.92);  // 1 USD = 0.92 EUR
        Money::set_conversion_table("EUR", "USD", 1.087); // 1 EUR = 1.087 USD
        Money::set_conversion_table("USD", "DKK", 6.58);  // 1 USD = 6.58 DKK
        Money::set_conversion_table("DKK", "USD", 0.152); // 1 DKK = 0.152 USD

        // Testing basic Money initialization
        Money usd1(100.50, "USD");  // $100.50 in USD
        Money eur1(50.75, "EUR");   // €50.75 in EUR
        Money dkk1(329, "DKK");     // 3.29 DKK

        std::cout << "Initial Money objects:" << std::endl;
        std::cout << "usd1: " << usd1 << std::endl;
        std::cout << "eur1: " << eur1 << std::endl;
        std::cout << "dkk1: " << dkk1 << std::endl;

        // Test addition with the same currency
        Money usd2(200, "USD");
        Money sum_usd = usd1 + usd2;
        std::cout << "\nAdding USD to USD:" << std::endl;
        std::cout << usd1 << " + " << usd2 << " = " << sum_usd << std::endl;

        // Test addition with different currencies (USD + EUR)
        Money sum_usd_eur = usd1 + eur1;
        std::cout << "\nAdding USD to EUR:" << std::endl;
        std::cout << usd1 << " + " << eur1 << " = " << sum_usd_eur << std::endl;

        // Test addition with different currencies (USD + DKK)
        Money sum_usd_dkk = usd1 + dkk1;
        std::cout << "\nAdding USD to DKK:" << std::endl;
        std::cout << usd1 << " + " << dkk1 << " = " << sum_usd_dkk << std::endl;

        // Test subtraction with the same currency
        Money diff_usd = usd2 - usd1;
        std::cout << "\nSubtracting USD from USD:" << std::endl;
        std::cout << usd2 << " - " << usd1 << " = " << diff_usd << std::endl;

        // Test subtraction with different currencies (USD - EUR)
        Money diff_usd_eur = usd2 - eur1;
        std::cout << "\nSubtracting EUR from USD:" << std::endl;
        std::cout << usd2 << " - " << eur1 << " = " << diff_usd_eur << std::endl;

        // Test subtraction with different currencies (USD - DKK)
        Money diff_usd_dkk = usd1 - dkk1;
        std::cout << "\nSubtracting DKK from USD:" << std::endl;
        std::cout << usd1 << " - " << dkk1 << " = " << diff_usd_dkk << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

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
