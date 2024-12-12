/*
In this kata, you will sort elements in an array by decreasing frequency of elements. If two elements have the same frequency, sort them by increasing value.

solve({2,3,5,3,7,9,5,3,7}) == {3,3,3,5,5,7,7,2,9}
// We sort by highest frequency to lowest frequency.
// If two elements have same frequency, we sort by increasing value.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

std::vector<int> solve(const std::vector<int>& vec) {
    unordered_map <int, int> frequency;
    for (int i = 0; i < vec.size(); i++) {
        frequency[vec[i]]++;
    }
    vector<pair<int, int>> vecfeq(frequency.begin(), frequency.end());
    std::sort(vecfeq.begin(), vecfeq.end(), [](const pair<int, int>& a, pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
        });

    vector <int> result;
    for (auto& f : vecfeq) {
        for (int i = 0; i < f.second; i++) {
            result.push_back(f.first);
        }
    }

    return result;
}
