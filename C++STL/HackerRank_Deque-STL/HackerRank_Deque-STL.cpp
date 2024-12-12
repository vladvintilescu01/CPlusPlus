#include <iostream>
#include <deque> 
#include <vector>
#include <algorithm>
using namespace std;

void printKMax(int arr[], int n, int k) {
    deque<int> dq;
    vector<int> result;

    for (size_t i = 0; i < n; i++) {

        dq.push_back(arr[i]);

        if (dq.size() > k) {
            dq.pop_front();
        }
  
        if (dq.size() == k) {
            auto maximum = max_element(dq.begin(), dq.end()); 
            result.push_back(*maximum);                      
        }
    }

    
    for (int max_value : result) {
        cout << max_value << " ";
    }
    cout << endl; 
}


int main() {

    int t;
    int n, k;
    cin >> t;
    while (t > 0) {
        
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}