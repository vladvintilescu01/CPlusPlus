#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
class Box {

    int l, b, h;

public:

    Box() {
        this->l = 0;
        this->b = 0;
        this->h = 0;
    }

    Box(int length, int breadth, int height) {
        this->l = length;
        this->b = breadth;
        this->h = height;
    }

    Box(Box& B) {
        this->l = B.l;
        this->b = B.b;
        this->h = B.h;
    }

    int getLength() {
        return this->l;
    }

    int getBreadth() {
        return this->b;
    }

    int getHeight() {
        return this->h;
    }

    long long CalculateVolume() {
        return (this->l) * (this->h) * (this->b);
    }

    bool operator<(Box& B) {
        if (this->l < B.l) {
            return true;
        }
        else if (this->b < B.b && this->l == B.l) {
            return true;
        }
        else if (this->h < B.h && this->l == B.l && this->b == B.b) {
            return true;
        }
        else {
            return false;
        }
    }

    friend ostream& operator<<(ostream& os, const Box& B) {
        os << B.l << " " << B.b << " " << B.h;
        return os;
    }
};


void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }

    }
}

int main()
{
    check2();
}