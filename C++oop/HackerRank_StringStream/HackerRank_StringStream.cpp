#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    // Complete this function'
    stringstream ss(str);
    vector <int> result;
    int number;
    char comma;
    while (ss >> number) {
        result.push_back(number);
        ss >> comma;
    }
    return result;
}

int main() {

    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
