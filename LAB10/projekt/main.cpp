#include <iostream>
#include <string>
#include <random>
#include <limits>
using namespace std;

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

// List head and last added employee
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

void addEmployee(string name, string surname, long pesel, long phoneNumber, string position, int salary, Adress* adress) {
    Employee* newEmployee = new Employee();
    newEmployee->name = name;
    newEmployee->surname = surname;
    newEmployee->pesel = pesel;
    newEmployee->adress = *adress;
    newEmployee->phoneNumber = phoneNumber;
    newEmployee->position = position;
    newEmployee->salary = salary;
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

int main() {
    bool running = true;
    int option;

    while (running) {
        cout << "\033[2J\033[1;1H";
        displayMenu();
        cin >> option;

        if (option < 1 || option > 4) running = false;

        switch (option) {
            // Add employee
            case 1: {
                cout << "\033[2J\033[1;1H";
                string street, city;
                int houseNumber, postalCode, housePhoneNumber;
                cout << "Street: ";
                cin >> street;
                cout << "City: ";
                cin >> city;
                cout << "House Number: ";
                cin >> houseNumber;
                cout << "Postal Code: ";
                cin >> postalCode;
                cout << "House phone number: ";
                cin >> housePhoneNumber;
                Adress* newAdress = addAdress(street, houseNumber, postalCode, city, housePhoneNumber);

                string name, surname, position;
                long pesel, phoneNumber;
                int salary;
                cout << "Name: ";
                cin >> name;
                cout << "Surname: ";
                cin >> surname;
                cout << "Pesel: ";
                cin >> pesel;
                cout << "Phone number: ";
                cin >> phoneNumber;
                cout << "Position: ";
                cin >> position;
                cout << "Salary: ";
                cin >> salary;

                addEmployee(name, surname, pesel, phoneNumber, position, salary, newAdress);
                pressEnter();
                break;
            }

            // Search for employee
            case 2:
                break;
            
            // Remove employee
            case 3:
                break;
            
            // Display employees
            case 4:
                cout << "\033[2J\033[1;1H";
                displayEmployees();
                pressEnter();
                break;
        }
    }

    return 0;
}
