#include "Exercise2.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void Name_pairs::read_names() {
	string input_name;
		while (cin >> input_name && input_name != "0") {
			name.push_back(input_name);
			read_ages();
		}
}
//void Name_pairs::print() {
//	for (int i = 0; i < name.size(); i++) {
//		cout << "(" << name[i] << "," << age[i] <<")"<< "\n";
//	}
//}
void Name_pairs:: sort() {
	vector <size_t> index(name.size());
	for (size_t i = 0; i < index.size(); i++) {
		index[i] = i;
	}
	std::sort(index.begin(), index.end(), [&](size_t a, size_t b) {
		return name[a] < name[b];
		});

	std::vector<std::string> sorted_name(name.size());
	std::vector<double> sorted_age(age.size());

	for (size_t i = 0; i < index.size(); i++) {
		sorted_name[i] = name[index[i]];
		sorted_age[i] = age[index[i]];
	}
	name = sorted_name;
	age = sorted_age;
}
ostream& operator<<(ostream& os, Name_pairs& np) {
	for (int i = 0; i < np.name.size(); i++) {
		os << "(" << np.name[i] << "," << np.age[i] << ")" << "\n";
	}
	return os;
}
void Name_pairs::operator==(Name_pairs& np) {
	int count = 0;
	for (size_t i = 0; i < name.size(); i++) {
		for (size_t j = 0; j < np.name.size(); j++){
		if (name[i] == np.name[j] && age[i] == np.age[j]) {
			count++;
		}
		}
	}
	cout << count <<"\n";
}

void Name_pairs::operator!=(Name_pairs& np) {
	int count = 0;
	for (size_t i = 0; i < name.size(); i++) {
		int count2 = 0;
		for (size_t j = 0; j < np.name.size(); j++) {
			if (name[i] != np.name[j] && age[i] != np.age[j]) {
				count2++;
			}
		}
		if (count2 == np.name.size()) {
			count++;
		}
	}
	cout << count << "\n";
}
void Name_pairs::read_ages() {
	int input_age;
	cin >> input_age;
	age.push_back(input_age);
		
}

int main() {
	Name_pairs set1;
	set1.read_names();
	//set1.sort();
	//cout << set1;
	Name_pairs set2;
	set2.read_names();
    set1 == set2;
	set1 != set2;
}