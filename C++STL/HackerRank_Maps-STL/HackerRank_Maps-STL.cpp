#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int q;
    int option;
    cin >> q;
    map<string, int> student;
    for (int i = 0; i < q; i++) {
        cin >> option; 
        string X;
        int Y;
        if (option == 1) {
            cin >> X >> Y;
            student[X] += Y;
        }
        if (option == 2) {
            cin >> X;
            student.erase(X);
            student[X] = 0;
        }
        if (option == 3) {
            cin >> X;
            
           if (student.find(X) != student.end()) {
                cout << student[X] << "\n";
           }
           else {
                cout << "0\n";
           }
            
        }
    }
    return 0;
}



