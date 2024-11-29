#pragma once
#include <vector>
#include <string>
using namespace std;
class Name_pairs {
public:
    void read_names();
    void print();
    void sort();
    void operator==(Name_pairs& np);
    void operator!=(Name_pairs& np);
    
    friend ostream& operator<<(ostream& os, Name_pairs& np);
    
private:
    std::vector<std::string> name;
    std::vector<double> age;
    void read_ages();
};
