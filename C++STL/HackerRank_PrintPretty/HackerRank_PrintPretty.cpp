#include <iostream>
#include <iomanip> 
#include <map>
#include <vector>
using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		
		vector<string>result_A;
		int	dec_A = static_cast<int>(A);
		while (dec_A) {
			map<int, string> conv_hex = { {0,"0"}, { 1,"1"}, {2,"2"}, {3,"3"}, {4,"4"}, {5,"5"}, {6,"6"}, {7,"7"}, {8,"8"}, {9,"9"}, {10,"A"}, {11,"B"}, {12,"C"}, {13,"D"}, {14,"E"}, {15,"F"} };
			int remainder = dec_A % 16;
			
			result_A.push_back(conv_hex[remainder]);
			dec_A /= 16;
		}
		reverse(result_A.begin(), result_A.end());
		cout << "0x";
		for (string result : result_A) {
			cout << result;
		}
		cout << "\n";
		int	dec_B = static_cast<int>(B);
		int count_nr_int = 0;
		while (dec_B) {
			count_nr_int++;
			dec_B /= 10;
		}
		int count_nr = count_nr_int + 4;
		int count_underscore = 15 - count_nr;
		
		while (count_underscore != 0) {
				cout << "_";
				count_underscore--;
		}
		cout << fixed << setprecision(2)<< showpos << B << "\n";
		cout << scientific << setprecision(9) <<noshowpos<< uppercase << C<<"\n";
	}

	return 0;

}