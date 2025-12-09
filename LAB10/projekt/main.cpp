#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

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
            case 2: {
                cout << "\033[2J\033[1;1H";
                int sOption;
                cout << "Search by?" << endl;
                cout << "1. name" << endl;
                cout << "2. surname" << endl;
                cout << "3. pesel" << endl;
                cout << "4. position" << endl;
                cout << "Select option:";
                cin >> sOption;
                string s;
                int p;
                switch (sOption) {
                case 1:
                    cin >> s;
                    cout << "\033[2J\033[1;1H";
                    displayEmployeesByName(s);
                    pressEnter();
                    break;
                case 2:
                    cin >> s;
                    cout << "\033[2J\033[1;1H";
                    displayEmployeesBySurname(s);
                    pressEnter();
                    break;
                case 3:
                    cin >> p;
                    cout << "\033[2J\033[1;1H";
                    displayEmployeesByPesel(p);
                    pressEnter();
                    break;
                case 4:
                    cin >> s;
                    cout << "\033[2J\033[1;1H";
                    displayEmployeesByPosition(s);
                    pressEnter();
                    break;
                default:
                    break;
                }

                break;
            }
            
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
