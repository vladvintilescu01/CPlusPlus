#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {

protected:
    string name;
    int age;
public:
    virtual void getdata() {
        cout << "sample";
    }
    virtual void putdata() {
        cout << "sample";
    }
};

class Professor : public Person {

private:
    int publications;
    static int cur_id;
public:

    void getdata() {
        string n;
        int  a, p;
        cin >> n >> a >> p;
        this->name = n;
        this->age = a;
        this->publications = p;
    }
    void putdata() {
        cur_id += 1;
        cout << this->name << " " << this->age << " " << this->publications << " " << this->cur_id << "\n";
    }

};

class Student : public Person {

private:
    int marks[6], sum = 0;
    static int cur_id;
public:

    void getdata() {
        string  n;
        int a, m;
        cin >> n >> a;
        for (int i = 0; i <= 5; i++) {
            cin >> m;
            this->marks[i] = m;
            sum += this->marks[i];
        }
        this->name = n;
        this->age = a;

    }
    void putdata() {
        cur_id += 1;
        cout << this->name << " " << this->age << " " << sum << " " << this->cur_id << "\n";
    }
};

int Student::cur_id = 0;
int Professor::cur_id = 0;

int main() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person* per[4]; /// need to modify!!!!!!!!

    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
