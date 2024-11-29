#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

void check_values(int a, int size) {
	if (a < 0 || a > size) {
		throw out_of_range("Position is out of range");
	}
}

int main() {
	try{
	int n,x,c,a,b;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	cin >> c;
	int size = v.size();
	check_values(c, size);
	c = c - 1;
	v.erase(v.begin() + c);
	size = v.size();
	cin >> a >> b;
	check_values(a, size);
	check_values(b, size);
	a = a - 1;
	b = b - 1;
	v.erase(v.begin() + a, v.begin() + b);
	cout << v.size() <<"\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i)<<" ";
	}
	}
	catch (out_of_range& e) {
		cerr << "Error: " << e.what() << "\n";
	}
	return 0;
}
