#include "functions.h"
#include <iostream>
#include <string>
#include <random>
#include <limits>
using namespace std;

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

// generating random uniqe id number
bool idExists(long value) {
    Employee* temp = head;
    while (temp) {
        if (temp->ID == value) return true;
        temp = temp->next;
    }
    return false;
}

long generateRandomID() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> IDgen(1000,9999);

    long ID;

    do {
        ID = IDgen(gen);
    } while (idExists(ID));

    return ID;
}

bool peselExists(long pesel) {
    Employee* temp = head;
    while (temp) {
        if (temp->pesel == pesel) return true;
        temp = temp->next;
    }
    return false;
}

void addEmployee(string name, string surname, long pesel, long phoneNumber, string position, int salary, Adress* adress) {
    Employee* newEmployee = new Employee();
    newEmployee->name = name;
    newEmployee->surname = surname;
    newEmployee->adress = *adress;
    newEmployee->phoneNumber = phoneNumber;
    newEmployee->position = position;
    newEmployee->salary = salary;
    newEmployee->next = nullptr;
    newEmployee->prev = nullptr;

    newEmployee->ID = generateRandomID();
    while (peselExists) {
        cout << "This pesel is already in the list!\nEnter new pesel: ";
        cin << pesel;
    }
    newEmployee->pesel = pesel;

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
        cout << temp->adress.postalCode << ' ';
        cout << temp->adress.city << ' ';
        cout << temp->adress.phoneNumber << endl;

        cout << temp->position << ' ';
        cout << temp->salary << endl;
        cout << "************************************" << endl;
        
        temp = temp->next;
        i++;
    }
}

void displayEmployeesByName(string s) {
    Employee* temp = head;
    if (temp == nullptr) {
        cout << "List is empty..." << endl;
    }
    
    int i = 1;
    while (temp != nullptr) {
        if (temp->name == s) {
            cout << "#" << i << ' ';
            cout << temp->ID << ' ';
            cout << temp->name << ' ';
            cout << temp->surname;
            cout << " Pesel: " << temp->pesel << endl;

            cout << "Adress: ";
            cout << temp->adress.street << ' ';
            cout << temp->adress.houseNumber << ' ';
            cout << temp->adress.postalCode << ' ';
            cout << temp->adress.city << ' ';
            cout << temp->adress.phoneNumber << endl;

            cout << temp->position << ' ';
            cout << temp->salary << endl;
            cout << "************************************" << endl;
        }
        temp = temp->next;
        i++;
    }
}

void displayEmployeesBySurname(string s) {
    Employee* temp = head;
    if (temp == nullptr) {
        cout << "List is empty..." << endl;
    }
    
    int i = 1;
    while (temp != nullptr) {
        if (temp->surname == s) {
            cout << "#" << i << ' ';
            cout << temp->ID << ' ';
            cout << temp->name << ' ';
            cout << temp->surname;
            cout << " Pesel: " << temp->pesel << endl;

            cout << "Adress: ";
            cout << temp->adress.street << ' ';
            cout << temp->adress.houseNumber << ' ';
            cout << temp->adress.postalCode << ' ';
            cout << temp->adress.city << ' ';
            cout << temp->adress.phoneNumber << endl;

            cout << temp->position << ' ';
            cout << temp->salary << endl;
            cout << "************************************" << endl;
        }
        temp = temp->next;
        i++;
    }
}

void displayEmployeesByPesel(long p) {
    Employee* temp = head;
    if (temp == nullptr) {
        cout << "List is empty..." << endl;
    }
    
    int i = 1;
    while (temp != nullptr) {
        if (temp->pesel == p) {
            cout << "#" << i << ' ';
            cout << temp->ID << ' ';
            cout << temp->name << ' ';
            cout << temp->surname;
            cout << " Pesel: " << temp->pesel << endl;

            cout << "Adress: ";
            cout << temp->adress.street << ' ';
            cout << temp->adress.houseNumber << ' ';
            cout << temp->adress.postalCode << ' ';
            cout << temp->adress.city << ' ';
            cout << temp->adress.phoneNumber << endl;

            cout << temp->position << ' ';
            cout << temp->salary << endl;
            cout << "************************************" << endl;
        }
        temp = temp->next;
        i++;
    }
}

void displayEmployeesByPosition(string s) {
    Employee* temp = head;
    if (temp == nullptr) {
        cout << "List is empty..." << endl;
    }
    
    int i = 1;
    while (temp != nullptr) {
        if (temp->position == s) {
            cout << "#" << i << ' ';
            cout << temp->ID << ' ';
            cout << temp->name << ' ';
            cout << temp->surname;
            cout << " Pesel: " << temp->pesel << endl;

            cout << "Adress: ";
            cout << temp->adress.street << ' ';
            cout << temp->adress.houseNumber << ' ';
            cout << temp->adress.postalCode << ' ';
            cout << temp->adress.city << ' ';
            cout << temp->adress.phoneNumber << endl;

            cout << temp->position << ' ';
            cout << temp->salary << endl;
            cout << "************************************" << endl;
        }
        temp = temp->next;
        i++;
    }
}

void displayMenu() {
    cout << "1. Add employee" << endl;
    cout << "2. Search for employee" << endl;
    cout << "3. Remove employee" << endl;
    cout << "4. Show all employee" << endl;
    cout << "5. Exit" << endl;
    cout << "Select option: ";
}

void pressEnter() {
    if (cin.peek() == '\n')
        cin.ignore();
    else
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Press Enter to continue...";
    cin.get();
}



void removeEmployee(long n) {
    bool id = false;
    bool pesel = false;

    Employee* temp = head;

    // search by ID
    while (!id && temp != nullptr) {
        if (temp->ID == n) {
            id = true;
            break;
        }
        temp = temp->next;
    }

    // search by PESEL
    if (!id) {
        temp = head;
        while (!pesel && temp != nullptr) {
            if (temp->pesel == n) {
                pesel = true;
                break;
            }
            temp = temp->next;
        }
    }

    if (id || pesel) {
        if (temp == head && temp->next == nullptr) {
            delete head;
            head = nullptr;
            lastAdded = nullptr;
        } else if (temp == head && temp->next != nullptr) {
            Employee* newHead = head->next;
            delete head;
            head = newHead;
            head->prev = nullptr;
        } else if (temp->next == nullptr) {
            lastAdded = temp->prev;
            lastAdded->next = nullptr;
            delete temp;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    // NOT FOUND → treat as index
    else {
        temp = head;
        for (int i = 0; i < n && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) return;
        
        if (temp == head && temp->next == nullptr) {
            delete head;
            head = nullptr;
            lastAdded = nullptr;
        } else if (temp == head) {
            Employee* newHead = head->next;
            delete head;
            head = newHead;
            head->prev = nullptr;
        } else if (temp->next == nullptr) {
            lastAdded = temp->prev;
            lastAdded->next = nullptr;
            delete temp;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
}

bool listEmpty() {
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
}
