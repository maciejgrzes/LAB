#include "header.h"
#include <iostream>
#include <limits>
using namespace std;

// Check if the inputed temperature is not below absolute 0
bool check(double temp, char unit) {
    if (temp < 0 && unit == 'K') {
        return true; 
    } else if (temp < -273.15 && unit == 'C') {
        return true;
    } else if (temp < -459.67 && unit == 'F') {
        return true;
    } else {
        return false;
    }
}


// Helper input functions
double inputC() {
    double C;
    cout << "Podaj temperature do przeliczenia: ";
    cin >> C;

    if (check(C, 'C')) {
        return 0;
    }

    return C;
}

double inputF() {
    double F;
    cout << "Podaj temperature do przeliczenia: ";
    cin >> F;
    
    if (check(F, 'F')) {
        return 0;
    }

    return F;
}

double inputK() {
    double K;
    cout << "Podaj temperature do przeliczenia: ";
    cin >> K;

    if (check(K, 'K')) {
        return 0;
    }

    return K;
}


// Main conversion functions
double FtoC (double F) {return (F - 32.0) * 5.0/9.0;}

double FtoK (double F) {return (F + 459.67) * 5.0/9.0;}

double CtoF (double C) {return C * 9.0/5.0 + 32.0;}

double CtoK (double C) {return C + 273.15;}

double KtoC (double K) {return K - 273.15;}

double KtoF (double K) {return K * 9.0/5.0 - 459.67;}


// Menu display procedure
void showMenu() {
    cout << "1 - przelicz Fahr -> Celsius" << endl;
    cout << "2 - przelicz Fahr -> Kelwin" << endl;
    cout << "3 - przelicz Celsius -> Fah" << endl;
    cout << "4 - przelicz Celsius -> Kelwin" << endl;
    cout << "5 - przelicz Kelwin -> Celsius" << endl;
    cout << "6 - przelicz Kelwin -> Fahr" << endl;
    cout << "7 - pokaż historie" << endl;
    cout << "8 - zakończ działanie programu" << endl;
    cout << "Wybierz opcje: ";
}

// Out of range prosedure
bool outOfRange(double temp) {
    if (temp == 0) {
        cout << "Nie ma takiej temperatury" << endl;
        return true;
    }
    return false;
}

void pressEnter() {
    if (cin.peek() == '\n')
        cin.ignore();
    else
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Naciśnij Enter aby kontynuować...";
    cin.get();
}

void printVector(vector<string> data) {
    for (int i = 0; i < data.size(); i += 2) {
        cout << data[i] << " -> " << data[i+1] << endl;
    }
}
