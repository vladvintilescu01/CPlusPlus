#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }
    int nr_of_query;
    cin >> nr_of_query;
    for (int i = 0; i < nr_of_query; i++) {
        int x;
        cin >> x;
        auto it = lower_bound(elements.begin(), elements.end(), x);
        if (it != elements.end() && *it == x) {
            cout << "Yes " << (it - elements.begin() + 1) << endl; // +1 for 1-based index
        }
        else {
            cout << "No " << (it - elements.begin() + 1) << endl;
        }
    }
    return 0;
}
