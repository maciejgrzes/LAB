#include <iostream>
#include <string>
#include <random>
using namespace std;

// For random ID generation
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> IDgen(1000,9999);

// Decleration of structs
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

// List head
Employee* head = nullptr;
Employee* lastAdded = nullptr;

Adress* addAdress(string street, int houseNumber, int postalCode, string city, int phoneNumber) {
    Adress* newAdress = new Adress();
    newAdress->street = street;
    newAdress->houseNumber = houseNumber;
    newAdress->postalCode = postalCode;
    newAdress->city = city;
    newAdress->phoneNumber = phoneNumber;

    return newAdress;
}

bool idExists(long value) {
    Employee* temp = head;
    while (temp) {
        if (temp->ID == value) return true;
        temp = temp->next;
    }
    return false;
}

long generateRandomID() {
    Employee* temp = head;
    long ID;

    do {
        ID = IDgen(gen);
    } while (idExists(ID));

    return ID;
}

void addEmployee(string name, string surname, long pesel, long phoneNumber, Adress* adress) {
    Employee* newEmployee = new Employee();
    newEmployee->name = name;
    newEmployee->surname = surname;
    newEmployee->pesel = pesel;
    newEmployee->adress = *adress;
    newEmployee->phoneNumber = phoneNumber;
    newEmployee->next = nullptr;
    newEmployee->prev = nullptr;

    newEmployee->ID = generateRandomID();

    if (head == nullptr) {
        head = newEmployee;
        lastAdded = newEmployee;
    } else {
        lastAdded->next = newEmployee;
        newEmployee->prev = lastAdded;
        lastAdded = newEmployee;
    }
}

void displayEmployees() {
    Employee* temp = head;
    if (temp == nullptr) {
        cout << "List is empty..." << endl;
    }
    
    int i = 1;
    while (temp != nullptr) {
        cout << "#" << i << ' ';
        cout << temp->ID << ' ';
        cout << temp->name << ' ';
        cout << temp->surname;
        cout << " Pesel: " << temp->pesel << endl;

        cout << "Adress: ";
        cout << temp->adress.street << ' ';
        cout << temp->adress.houseNumber << ' ';
        cout << temp->adress.city << ' ';
        cout << temp->adress.phoneNumber << endl;

        cout << temp->position << ' ';
        cout << temp->salary << endl;
        cout << "************************************" << endl;
        
        temp = temp->next;
        i++;
    }
}

int main() {
    addEmployee("John", "Pork", 123456789, 123123123, addAdress("main", 12, 12451, "somecity", 123123123));
    displayEmployees();

    return 0;
}
