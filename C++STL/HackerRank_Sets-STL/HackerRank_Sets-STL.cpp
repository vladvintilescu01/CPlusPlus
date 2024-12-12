#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int query;
    set<int> s;
    cin >> query;
    for (int i = 0; i < query; i++) {
        int x,y;
        
        cin >> x;
        if (x == 1) {
            cin >> y;
            s.insert(y);
            
        }else if (x == 2) {
            cin >> y;
            s.erase(y);
        }
        else if (x == 3) {
            cin >> y;
            if (s.find(y) != s.end()) {
                cout << "Yes" << "\n";
            }
            else {
                cout << "No" << "\n";
            }
        }
    }
   /* for (int ss : s) {
        cout << ss << "\n";
    }*/
    return 0;
}



