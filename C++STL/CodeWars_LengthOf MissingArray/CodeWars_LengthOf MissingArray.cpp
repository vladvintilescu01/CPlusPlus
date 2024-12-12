/*
    
You get an array of arrays.
If you sort the arrays by their length, you will see, that their length-values are consecutive.
But one array is missing!


You have to write a method, that return the length of the missing array.

    
If the array of arrays is null/nil or empty, the method should return 0.

When an array in the array is null or empty, the method should return 0 too!
There will always be a missing element and its length will be always between the given arrays.


*/

#include <vector>
#include <algorithm>
using namespace std;
template<class TYPE>
int getLengthOfMissingArray(std::vector<std::vector<TYPE>> arrayOfArrays)
{
    if (arrayOfArrays.empty()) {
        return 0;
    }
    vector<int> lens;
    for (int i = 0; i < arrayOfArrays.size(); i++) {
        if (arrayOfArrays[i].empty()) {
            return 0;
        }
        lens.push_back(arrayOfArrays[i].size());
    }
    sort(lens.begin(), lens.end());
    for (int i = 1; i <= lens.size(); i++) {
        if (lens[i] - lens[i - 1] > 1) {
            return lens[i] - 1;
        }
    }
    return 0;
}