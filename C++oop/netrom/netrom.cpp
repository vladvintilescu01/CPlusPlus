#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    string mail;
public:
    Person(string name, string mail) {
        this->name = name;
        this->mail = mail;
    }
    string getName() {
        return this->name;
    }
    string getEmail() {
        return this->mail;
    }

};
class Customer : public Person {
private:
    int clientNo;
    string clientType;

public:
    Customer(int clientNo, string ) : Person(name, mail) {
        this->clientNo = clientNo;
        this->clientType = clientType;
    };
   
    int getClientNo() {
        return this->clientNo;
    }
    string getClientType() {
        return this->clientType;
    }
};
class Car {
private:
    string manufacturerModel;
    string previousServiceVisit;
    string firstRegistrationCountry;
    double price;
    int milage;
public:
    Car(string manufacturerModel, string previousServiceVisit, string firstRegistrationCountry, double price, int milage) {
        this->manufacturerModel = manufacturerModel;
        this->previousServiceVisit = previousServiceVisit;
        this->firstRegistrationCountry = firstRegistrationCountry;
        this->price = price;
        this->milage = milage;
    }
    string getManufacturerModel() {
        return this->manufacturerModel;
    }
    string getPreviousServiceVisit() {
        return this->previousServiceVisit;
    }
    string getFirstRegistrationCountry() {
        return this->firstRegistrationCountry;
    }
    double getPrice() {
        return this->price;
    }
    int getMilage() {
        return this->milage;
    }
};
int main()
{
    std::cout << "Hello World!\n";
}

class Item {
protected:
    float unitPrice, discount;
public:
    Item(float unitPrice, float discount) {
        this->unitPrice = unitPrice;
        this->discount = discount;
    }
    virtual float getFinalPrice() {
        return unitPrice - (unitPrice * (discount / 100));
    }
};

class PTC : public Item {
private:
    string description;
    int km;
public:
    PTC(string description, int km) : Item(unitPrice,discount) {
        this->description = description;
        this->km = km;
    }
    int getKm() {
        return this->km;
    }
    string getDescription() {
        return this->description = description;
    }
};

class PartRecycle: public Item {
private:
    string description;
    float recyclePrice;
public:
    PartRecycle(string description, float recyclePrice) : Item(unitPrice, discount) {
        this->description = description;
        this->recyclePrice = recyclePrice;
    }
    string getDescription() {
        return this->description = description;
    }
    float getFinalPrice() {
        return Item::getFinalPrice() - recyclePrice;
    }
};
class WorkOrder {
    int id;
    string description;
    string remarksMechanic;
    Car car;
    Customer customer;
    vector<Item> items;
public:
    WorkOrder(int id, string description, string remarksMechanic, Car car, Customer customer) {
        //....
    }
    float getTotalSum() {
        float sum = 0;
        for (auto& item : items) {
            sum += item.getFinalPrice();
        }
        return sum;
    }
    //here is a design where for total sum of all prices of each item
    //we perform compution for each item and then we add all prices from each item
};

// i don't have time to implement but i will try to explain what is need to do:
//we need to create a class "activities" with private members integer: id, starthour and the duration. In public we need to define the function, we traverse all activities to find the available time of each employee...