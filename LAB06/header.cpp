#include "header.h"
#include <optional>
#include <iostream>
#include <limits>
#include <random>
#include <string>
using namespace std;

// Convert Unit enum to string 
string unitToString(Unit u) {
    switch (u) {
        case Unit::Kelvin:     return "K";
        case Unit::Celsius:    return "°C";
        case Unit::Fahrenheit: return "°F";
    }
    return "";
}

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

    while (true) {
        cout << "Podaj temperature do przeliczenia: ";
        cin >> C;

        if (cin.fail()) {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Wpisz liczbe!! ";
        } else {
            if (check(C, 'C')) {
                return -999;
            } else {
                return C;
            }
        }
    }
}

double inputF() {
    double F;

    while (true) {
        cout << "Podaj temperature do przeliczenia: ";
        cin >> F;

        if (cin.fail()) {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Wpisz liczbe!! ";
        } else {
            if (check(F, 'F')) {
                return -999;
            } else {
                return F;
            }
        }
    }
}

double inputK() {
    double K;

    while (true) {
        cout << "Podaj temperature do przeliczenia: ";
        cin >> K;

        if (cin.fail()) {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Wpisz liczbe!! ";
        } else {
            if (check(K, 'K')) {
                return -999;
            } else {
                return K;
            }
        }
    }}


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


void printVector(const vector<Entry>& history, optional<Unit> filter) {
    for (const auto& e : history) {
        if (filter && e.unitBefore != *filter)  // skip if filter is set and doesn't match
            continue;

        cout << e.before << " " << unitToString(e.unitBefore)
            << " -> " << e.after << " " << unitToString(e.unitAfter) << endl;
    }
}

void showHistoryMenu() {
    cout << "1 - Tylko C - > inne" << endl;
    cout << "2 - Tylko F - > inne" << endl;
    cout << "3 - Tylko K - > inne" << endl;
    cout << "4 - Cała historia" << endl;
    cout << "5 - Edytuj historie" << endl;
    cout << "6 - Zakończ" << endl;
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

// Safety checking for the correct scale
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

// Procedure to replace a history entry with user input
void calculateAndReplace(vector<Entry>& history) {
    int indexToEdit;

    do {
        cout << "Który index zmienić? ";
        cin >> indexToEdit;
    } while (indexToEdit < 1 || indexToEdit > history.size());

    Entry& entry = history[indexToEdit - 1]; // reference to the entry

    char scale = inputScale();
    Unit unitBefore;

    if (scale == 'C') {
        unitBefore = Unit::Celsius;
    } else if (scale == 'F') {
        unitBefore = Unit::Fahrenheit;
    } else {
        unitBefore = Unit::Kelvin;
    }

    double newTemp;
    if (unitBefore == Unit::Celsius) {
        newTemp = inputC();
    } else if (unitBefore == Unit::Fahrenheit) {
        newTemp = inputF();
    } else {
        newTemp = inputK();
    }

    if (outOfRange(newTemp)) {
        pressEnter();
        return;
    }

    char newScale = inputScaleToCalculate(scale);
    Unit unitAfter;
    if (newScale == 'C') {
        unitAfter = Unit::Celsius;
    } else if (newScale == 'F') {
        unitAfter = Unit::Fahrenheit;
    } else {
        unitAfter = Unit::Kelvin;
    }

    // Perform conversion
    double newTempAfter;
    if (unitBefore == Unit::Celsius) {
        if (unitAfter == Unit::Fahrenheit) {
            newTempAfter = CtoF(newTemp);
        } else { // Unit::Kelvin
            newTempAfter = CtoK(newTemp);
        }
    } else if (unitBefore == Unit::Fahrenheit) {
        if (unitAfter == Unit::Celsius) {
            newTempAfter = FtoC(newTemp);
        } else { // Unit::Kelvin
            newTempAfter = FtoK(newTemp);
        }
    } else {
        if (unitAfter == Unit::Celsius) {
            newTempAfter = KtoC(newTemp);
        } else { // Unit::Fahrenheit
            newTempAfter = KtoF(newTemp);
        } 
    }

    entry.before = newTemp;
    entry.unitBefore = unitBefore;
    entry.after = newTempAfter;
    entry.unitAfter = unitAfter;

    cout << entry.before << unitToString(entry.unitBefore)
         << " -> " << entry.after << unitToString(entry.unitAfter) << endl;
}

// Generating random numbers to put into history
void generateRandomHistory(vector<Entry>& history) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> chars(0, 2);        // for unit selection
    uniform_int_distribution<int> valuesC(-274, 727);
    uniform_int_distribution<int> valuesF(-460, 540);
    uniform_int_distribution<int> valuesK(0, 1000);

    char letters[] = {'C', 'F', 'K'};

    int count;

    while (true) {
        cout << "Ile losowych liczb wpisać? ";
        cin >> count;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wpisz liczbe!! ";
        } else {
            break;
        }
    }

    if (count + history.size() > 100) {
        char option;
        int allowed = 100 - history.size();
        cout << "Zamało miejsca! Chcesz wypełnić historie " << allowed << " elementami? (Y/n) ";
        cin >> option;
        if (option == 'Y' || option == 'y') {
            count = allowed;
        } else {
            return;
        }
    }

    // Generate random entries
    for (int i = 0; i < count; i++) {
        int firstIndex = chars(gen);
        int secondIndex;
        do {
            secondIndex = chars(gen);
        } while (secondIndex == firstIndex);

        char firstLetter = letters[firstIndex];
        char secondLetter = letters[secondIndex];

        double temp;

        if (firstLetter == 'C') {
            temp = valuesC(gen);
        } else if (firstLetter == 'F') {
            temp = valuesF(gen);
        } else { // 'K'
            temp = valuesK(gen);
        }

        Entry entry;
        // Determine unitBefore
        if (firstLetter == 'C') {
            entry.unitBefore = Unit::Celsius;
        } else if (firstLetter == 'F') {
            entry.unitBefore = Unit::Fahrenheit;
        } else {
            entry.unitBefore = Unit::Kelvin;
        }

        // Determine unitAfter
        if (secondLetter == 'C') {
            entry.unitAfter = Unit::Celsius;
        } else if (secondLetter == 'F') {
            entry.unitAfter = Unit::Fahrenheit;
        } else {
            entry.unitAfter = Unit::Kelvin;
        }

        entry.before = temp;

        // Perform conversion
        if (entry.unitBefore == Unit::Celsius) {
            if (entry.unitAfter == Unit::Fahrenheit) entry.after = CtoF(temp);
            else entry.after = CtoK(temp);
        } else if (entry.unitBefore == Unit::Fahrenheit) {
            if (entry.unitAfter == Unit::Celsius) entry.after = FtoC(temp);
            else entry.after = FtoK(temp);
        } else { // Unit::Kelvin
            if (entry.unitAfter == Unit::Celsius) entry.after = KtoC(temp);
            else entry.after = KtoF(temp);
        }

        history.push_back(entry);
    }
}
