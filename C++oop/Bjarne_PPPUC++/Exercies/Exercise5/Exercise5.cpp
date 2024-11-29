// Exercise5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Exercise5.h"
Book::Book(string _ISBN, string _title, string _author, int _copyright_date, bool _checked_in, Genre _gen) {
	int count_nr = 0;
	char previous_char = 's';
	for (int i = 0; i < _ISBN.size(); i++) {
		char next_char = _ISBN[i + 1];
		if (count_nr < 3) {
			if (!isdigit(_ISBN[i]) && _ISBN[i] != '-') {
				throw invalid_argument("Ai scris gresit isbn-ul, boule!");
			}
			if (_ISBN[i] == '-' && isdigit(previous_char) && (isdigit(next_char) || isalpha(next_char))) {
				count_nr++;
			}
			
		}
		else if (count_nr == 3 && (isdigit(previous_char) && isdigit(_ISBN[i])) || (isalpha(previous_char) && isalpha(_ISBN[i]))) {
			throw invalid_argument("Ai scris gresit isbn-ul, boule!");
		}else if (count_nr == 3 && (isdigit(_ISBN[i]) || (isalpha(_ISBN[i])))) {
			ISBN = _ISBN;
		}
		previous_char = _ISBN[i];
	}
	title = _title;
	author = _author;
	copyright_date = _copyright_date;
	checked_in = _checked_in;
	gen = _gen;
}
Patron::Patron(string _user_name, int _card_number, double _library_fees = 0.0) {
	user_name = _user_name;
	card_number = _card_number;
	library_fees = _library_fees;
}

bool Book::verify_checkin() {
	if (checked_in == true) {
		return true;
	}
	else {
		return false;
	}
}
string genre_to_string(Genre gen) { //helper function
	switch (gen) {
	case Genre::fiction:
		return "fiction";
	case Genre::nonfiction:
		return "nonfiction";
	case Genre::periodical:
		return "periodical";
	case Genre::biography:
		return "biography";
	case Genre::children:
		return "children";
	default: return "undefined";
	}
}
bool Book::operator==(Book& book) {
	if (ISBN == book.ISBN) {
		return true;
	}
	return false;
}
bool Book::operator!=(Book& book) {
	if (ISBN != book.ISBN) {
		return true;
	}
	return false;
}
ostream& operator<<(ostream& os, Book& book) {
	os << book.title << "\n" << book.author << "\n" << book.ISBN << "\n" << genre_to_string(book.gen) << "\n";
	return os;
}
bool verify_users_owes_fees(Patron p) { //helper function
	if (p.get_library_fees() > 0.0) {
		return true;
	}
	return false;
}
// library implementation
void Library::add_book(Book& _book) {
	book.push_back(_book);
}
void Library::add_patron(Patron& _patron) {
	patron.push_back(_patron);
}
void Library::check_out_book(Patron& _patron, Book& _book) {
	bool check_patron = false;
	bool check_book = false;
	for (size_t i = 0; i < patron.size(); i++) {
		if (patron[i].get_card_number() == _patron.get_card_number()) {
			check_patron = true;
			break;
		}
	}
	for (size_t i = 0; i < book.size(); i++) {
		if (book[i].get_title() == _book.get_title()) {
			check_book = true;
			break;
		}
	}
	if (check_book == false || check_patron == false) {
		throw invalid_argument("Nu se afla in librarie cartea sau utilizatoru nu este in librarie");
	}
	if (_patron.get_library_fees() > 0.0) {
		throw invalid_argument("baii trebuie sa platesti datoria!!!");
	}
	if (_book.verify_checkin()) {
		throw invalid_argument("ti-a luat-o altu inainte, cartea deja este inchiriata pentru altcineva!!!");
	}
	_book.set_check_in(true);
	_patron.set_library_fees(30.75);
	transaction.push_back(Transaction(_book, _patron));
	cout << "Bravo! Ai inchiriat cartea cu succes!!!"<<"\n";
}
vector<string> Library::get_patrons_with_fees() {
	vector<string> patrons_with_fees;
	for(size_t i = 0; i < patron.size(); i++){
		if (patron[i].get_library_fees() > 0.0) {
			patrons_with_fees.push_back(patron[i].get_user_name());
		}
	}
	return patrons_with_fees;
}
int main() {
	try {
		// Correct the parameter types: copyright_date as int and add checked_in as a bool
		Book myBook1{ "12-11-11-1", "The Great Gatsby", "F. Scott Fitzgerald", 1925, false, Genre::fiction};
		Book myBook2("12-1111-1-A", "The Great Gatsby", "F. Scott Fitzgerald", 1925, false, Genre::nonfiction);
		Patron patron1{ "karina", 123, 0.0 };
		Patron patron2{ "vlad", 124, 20.2 };
		Library lib;
		lib.add_book(myBook1);
		lib.add_book(myBook2);
		lib.add_patron(patron1);
		lib.add_patron(patron2);
		lib.check_out_book(patron1, myBook1);
		lib.check_out_book(patron2, myBook2);
		/*bool m1 = myBook1 == myBook2;
		bool m2 = myBook1 != myBook2;
		cout << m1 << " " << m2 << "\n";
		cout << myBook1;*/

		//std::cout << "Esti bun, ai scris bine!" << std::endl;
	}
	catch (const std::invalid_argument& e) {
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
