#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

enum class Genre {
	fiction, nonfiction, periodical, biography, children
};

class Book {
public:
	Book(string _ISBN, string _title, string _author, int _copyright_date, bool _checked_in, Genre _gen);
	bool verify_checkin();
	bool operator==(Book& book);
	bool operator!=(Book& book);
	friend ostream& operator<<(ostream& os, Book& book);
	string get_title() {
		return title;
	}
	string get_author() {
		return author;
	}
	int get_copyright_date() {
		return copyright_date;
	}
	bool get_checked_in() {
		return checked_in;
	}
	void set_check_in(bool _checked_in) {
		checked_in = _checked_in;
	}
private:
	string ISBN, title, author;
	int copyright_date;
	bool checked_in;
	Genre gen;
};

class Patron {
public:
	Patron(string _user_name, int _card_number, double _library_fees);
	string get_user_name() {
		return user_name;
	}
	int get_card_number() {
		return card_number;
	}
	double get_library_fees(){
		return library_fees;
	}
	void set_library_fees(double amount) {
		library_fees = amount;
	}

private:
	string user_name;
	int card_number;
	double library_fees;
};
struct Transaction {
	Book b;
	Patron p;
	Transaction(const Book& book, const Patron& patron) : b(book), p(patron) {}
};
class Library{
public:
	void add_book(Book& _book);
	void add_patron(Patron& _patron);
	void check_out_book(Patron& _patron, Book& _book);
	vector<string> get_patrons_with_fees();
private:
	vector<Book> book;
	vector<Patron> patron;
	vector<Transaction> transaction;
};