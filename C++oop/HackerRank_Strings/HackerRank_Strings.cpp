#include <iostream>
#include <string>
using namespace std;

int main() {

    string a, b;
    cin >> a >> b;
    int len1, len2;
    len1 = a.size();
    len2 = b.size();
    string c = a + b;
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;
    cout << len1 << " " << len2 << " "<<"\n";
    cout << c << "\n" << a << " " << b;
    return 0;
}