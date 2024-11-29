#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class RomanHelper {
public:
    string to_roman(unsigned int n) {
        string result = "";
        // List of values and symbols for Roman numerals in descending order
        int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        std::string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        for (int i = 0; i < 13; i++) {
            if (n >= values[i]) {
                result += symbols[i];
                n -= values[i];
            }
        }
        return result;
    }
    int from_roman(std::string& rn) {
        int result = 0;
        int length = rn.size();
        unordered_map<char, int> roman_values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        for (int i = 0; i < length; i++) {
            int value = roman_values[rn[i]];
            if (value < roman_values[rn[i + 1]] && i + 1 < length) {
                result -= value;
            }
            else {
                result += value;
            }
        }
        return result;
    }
} RomanNumerals;
int main() {

}