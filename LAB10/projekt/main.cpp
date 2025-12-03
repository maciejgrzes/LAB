#include <iostream>
#include <string>
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> num(1,9);

struct Adress {
    string street = "";
    int houseNumber = 0;
    int postalCode = 0;
    string city = "";
    int phoneNumber = 0;
};

struct Employee {
    string name = "";
    string surname = "";
    long pesel = 0;
    Adress adress;
    long phoneNumber = 0;
    string position = "";
    int salary = 0;
    long ID = 0;
    Employee* next = nullptr;
    Employee* prev = nullptr;
};

Employee* head = nullptr;

Adress* addAdress(string street, int houseNumber, int postalCode, string city, int phoneNumber) {
    Adress* newAdress = new Adress();
    newAdress->street = street;
    newAdress->houseNumber = houseNumber;
    newAdress->postalCode = postalCode;
    newAdress->city = city;
    newAdress->phoneNumber = phoneNumber;

    return newAdress;
}

void addEmployee(string name, string surname, long pesel, Adress adress, long phoneNumber) {
    Employee* newEmployee = new Employee();
    newEmployee->name = name;
    newEmployee->surname = surname;
    newEmployee->pesel = pesel;
    newEmployee->adress = adress;
    newEmployee->phoneNumber = phoneNumber;
    newEmployee->next = nullptr;
    newEmployee->prev = nullptr;

    string ID = "";
    for (int i = 0; i < 4; i++) {
        ID += to_string(num(gen));
    }
    long lID = stol(ID);

    newEmployee->ID = lID;
}

int main() {
    

    return 0;
}
