#include <string>
using namespace std;

#ifndef HEADER_INCLUDE

#define HEADER_INCLUDE

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

Adress* addAdress(string street, int houseNumber, int postalCode, string city, int phoneNumber);

bool idExists(long value);

long generateRandomID();

void addEmployee(string name, string surname, long pesel, long phoneNumber, string position, int salary, Adress* adress);

void displayEmployees();

void displayEmployeesByName(string s);

void displayEmployeesBySurname(string s);

void displayEmployeesByPesel(long p);

void displayEmployeesByPosition(string s);

void displayMenu();

void pressEnter();

void removeEmployee(long n);

bool listEmpty();

void saveToFile();
#endif
