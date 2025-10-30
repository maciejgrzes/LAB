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
        return -999.0;
    }

    return C;
}

double inputF() {
    double F;
    cout << "Podaj temperature do przeliczenia: ";
    cin >> F;
    
    if (check(F, 'F')) {
        return -999;
    }

    return F;
}

double inputK() {
    double K;
    cout << "Podaj temperature do przeliczenia: ";
    cin >> K;

    if (check(K, 'K')) {
        return -999;
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
    if (temp == -999.0) {
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
    if (data.empty()) {
        cout << "Nie ma historii!" << endl;
    }
    for (int i = 0; i < data.size(); i++) {
        cout << i+1 << ": " << data[i] << endl;
    }
}

void showHistoryMenu() {
    cout << "1 - Tylko C - > inne" << endl;
    cout << "2 - Tylko F - > inne" << endl;
    cout << "3 - Tylko K - > inne" << endl;
    cout << "4 - Cała historia" << endl;
    cout << "5 - Edytuj historie" << endl;
    cout << "Wybierz opcje: ";
}

void showHistoryEditMenu() {
    cout << "1 - Wyczyść całą historie" << endl;
    cout << "2 - Wybierz element do usunięcia" << endl;
    cout << "3 - Edytuj wpis" << endl;
    cout << "4 - Wypełnij historie losowymi numerami" << endl;
    cout << "5 - Zakończ" << endl;
    cout << "Wybierz opcje: ";
}

char inputScale() {
    cout << "Podaj skale: ";
    char scale;
    cin >> scale;

    while (scale != 'C' && scale != 'F' && scale != 'K' && scale != 'c' && scale != 'f' && scale != 'k') {
        cout << "Podaj C lub F lub K!" << endl;
        cout << "Spróbuj jeszcze raz: ";
        cin >> scale;
    }

    if (scale == 'c') return 'C';
    if (scale == 'f') return 'F';
    if (scale == 'k') return 'K';
    return scale;
}

char inputScaleToCalculate(char scale) {
    cout << "Skala do przeliczenia: ";
    char secondScale;
    cin >> secondScale;

    while (scale == secondScale) {
        cout << "Skale nie mogą być takie same smh!" << endl;
        cout << "Spróbuj jeszcze raz: ";
        cin >> secondScale;
    }

    if (secondScale == 'c') return 'C';
    if (secondScale == 'f') return 'F';
    if (secondScale == 'k') return 'K';
    return secondScale;
}

void calculateAndReplace(vector<string>& vec) {
    cout << "Który index zmienić? ";
    int indexToEdit;
    cin >> indexToEdit;

    char scale = inputScale();
 
    double newTemp;
    double newTempAfter;

    if (scale == 'C') {
        newTemp = inputC();

        if (outOfRange(newTemp)) {
            pressEnter();
            return;
        }

        char newScale = inputScaleToCalculate(scale);

        if (newScale == 'F') {
            newTempAfter = CtoF(newTemp);
            cout << newTemp << "°C -> " << newTempAfter << "°F" << endl;
            vec[indexToEdit-1] = to_string(newTemp) + "°C -> " + to_string(newTempAfter) + "°F";

        } else if (newScale == 'K') {
            newTempAfter = CtoK(newTemp);
            cout << newTemp << "°C -> " << newTempAfter << "K" << endl;
            vec[indexToEdit-1] = to_string(newTemp) + "°C -> " + to_string(newTempAfter) + "K";
        }

    } else if (scale == 'F') {
        newTemp = inputF();

        if (outOfRange(newTemp)) {
            pressEnter();
            return;
        }

        char newScale = inputScaleToCalculate(scale);

        if (newScale == 'C') {
            newTempAfter = FtoC(newTemp);
            cout << newTemp << "°F -> " << newTempAfter << "°C" << endl;
            vec[indexToEdit-1] = to_string(newTemp) + "°F -> " + to_string(newTempAfter) + "°C";

        } else if (newScale == 'K') {
            newTempAfter = FtoK(newTemp);
            cout << newTemp << "°F -> " << newTempAfter << "K" << endl;
            vec[indexToEdit-1] = to_string(newTemp) + "°F -> " + to_string(newTempAfter) + "K";
        }

    } else if (scale == 'K') {
        newTemp = inputK();

        if (outOfRange(newTemp)) {
            pressEnter();
            return;
        }

        char newScale = inputScaleToCalculate(scale);

        if (newScale == 'F') {
            newTempAfter = CtoF(newTemp);
            cout << newTemp << "K -> " << newTempAfter << "°F" << endl;
            vec[indexToEdit-1] = to_string(newTemp) + "K -> " + to_string(newTempAfter) + "°F";

        } else if (newScale == 'C') {
            newTempAfter = CtoK(newTemp);
            cout << newTemp << "K -> " << newTempAfter << "°C" << endl;
            vec[indexToEdit-1] = to_string(newTemp) + "K -> " + to_string(newTempAfter) + "°C";
        }

    }
}
