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
        case Unit::Rankine:    return "R"; 
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
    } else if (temp < 0 && unit == 'R') {
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
    }
}

double inputR() {
    double R;

    while (true) {
        cout << "Podaj temperature do przeliczenia: ";
        cin >> R;

        if (cin.fail()) {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Wpisz liczbe!! ";
        } else {
            if (check(R, 'R')) {
                return -999;
            } else {
                return R;
            }
        }
    }
}


// Main conversion functions
double FtoC (double F) {return (F - 32.0) * 5.0/9.0;}

double FtoK (double F) {return (F + 459.67) * 5.0/9.0;}

double CtoF (double C) {return C * 9.0/5.0 + 32.0;}

double CtoK (double C) {return C + 273.15;}

double KtoC (double K) {return K - 273.15;}

double KtoF (double K) {return K * 9.0/5.0 - 459.67;}

double CtoR (double C) {return CtoF(C) + 459.67;}

double FtoR (double F) {return F + 459.67;}

double KtoR (double K) {return K * 9.0/5.0;}

double RtoF (double R) {return R - 459.67;}

double RtoC (double R) {return FtoC(RtoF(R));}

double RtoK (double R) {return R * 5.0/9.0;}


// Menu display procedure
void showMenu() {
    cout << "1 - przelicz Fahr -> Celsius" << endl;
    cout << "2 - przelicz Fahr -> Kelwin" << endl;
    cout << "3 - przelicz Celsius -> Fahr" << endl;
    cout << "4 - przelicz Celsius -> Kelwin" << endl;
    cout << "5 - przelicz Kelwin -> Celsius" << endl;
    cout << "6 - przelicz Kelwin -> Fahr" << endl;
    cout << "7 - przelicz Celsius -> Rankine" << endl;
    cout << "8 - przelicz Fahr -> Rankine" << endl;
    cout << "9 - przelicz Kelwin -> Rankine" << endl;
    cout << "10 - przelicz Rankine -> Celsius" << endl;
    cout << "11 - przelicz Rankine -> Fahr" << endl;
    cout << "12 - przelicz Rankine -> Kelvin" << endl;
    cout << "13 - pokaż historie" << endl;
    cout << "14 - zakończ działanie programu" << endl;
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
    cout << "4 - Tylko R - > inne" << endl;
    cout << "5 - Cała historia" << endl;
    cout << "6 - Edytuj historie" << endl;
    cout << "7 - Zakończ" << endl;
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

    while (scale != 'C' && scale != 'F' && scale != 'K' && scale != 'c' && scale != 'f' && scale != 'k' && scale != 'R' && scale != 'r') {
        cout << "Podaj C lub F lub K lub R!" << endl;
        cout << "Spróbuj jeszcze raz: ";
        cin >> scale;
    }

    if (scale == 'c') return 'C';
    if (scale == 'f') return 'F';
    if (scale == 'k') return 'K';
    if (scale == 'r') return 'R';
    return scale;
}

char inputScaleToCalculate(char scale) {
    cout << "Skala do przeliczenia: ";
    char secondScale = inputScale();

    while (scale == secondScale) {
        cout << "Skale nie mogą być takie same smh!" << endl;
        cout << "Spróbuj jeszcze raz: ";
        secondScale = inputScale();
    }

    if (secondScale == 'c') return 'C';
    if (secondScale == 'f') return 'F';
    if (secondScale == 'k') return 'K';
    if (secondScale == 'r') return 'R';
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
    } else if (scale == 'K') {
        unitBefore = Unit::Kelvin;
    } else {
        unitBefore = Unit::Rankine;
    }

    double newTemp;
    if (unitBefore == Unit::Celsius) {
        newTemp = inputC();
    } else if (unitBefore == Unit::Fahrenheit) {
        newTemp = inputF();
    } else if (unitBefore == Unit::Kelvin) {
        newTemp = inputK();
    } else {
        newTemp = inputR();
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
    } else if (newScale == 'K') {
        unitAfter = Unit::Kelvin;
    } else {
        unitAfter = Unit::Rankine;
    }

    // Perform conversion
    double newTempAfter;
    if (unitBefore == Unit::Celsius) {
        if (unitAfter == Unit::Fahrenheit) {
            newTempAfter = CtoF(newTemp);
        } else if (unitAfter == Unit::Kelvin) {
            newTempAfter = CtoK(newTemp);
        } else {
            newTempAfter = CtoR(newTemp);
        }
    } else if (unitBefore == Unit::Fahrenheit) {
        if (unitAfter == Unit::Celsius) {
            newTempAfter = FtoC(newTemp);
        } else if (unitAfter == Unit::Kelvin) {
            newTempAfter = FtoK(newTemp);
        } else {
            newTempAfter = FtoR(newTemp);
        }
    } else if (unitBefore == Unit::Kelvin){
        if (unitAfter == Unit::Celsius) {
            newTempAfter = KtoC(newTemp);
        } else if (unitAfter == Unit::Fahrenheit) {
            newTempAfter = KtoF(newTemp);
        } else {
            newTempAfter = KtoR(newTemp);
        }
    } else {
        if (unitAfter == Unit::Celsius) {
            newTempAfter = RtoC(newTemp);
        } else if (unitAfter == Unit::Fahrenheit) {
            newTempAfter = RtoF(newTemp);
        } else {
            newTempAfter = RtoK(newTemp);
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

    uniform_int_distribution<int> chars(0, 3);        // for unit selection
    uniform_int_distribution<int> valuesC(-274, 727);
    uniform_int_distribution<int> valuesF(-460, 540);
    uniform_int_distribution<int> valuesK(0, 1000);
    uniform_int_distribution<int> valuesR(0, 500);

    char letters[] = {'C', 'F', 'K', 'R'};

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
        } else if (firstLetter == 'K') { 
            temp = valuesK(gen);
        } else {
            temp = valuesR(gen);
        }

        Entry entry;
        // Determine unitBefore
        if (firstLetter == 'C') {
            entry.unitBefore = Unit::Celsius;
        } else if (firstLetter == 'F') {
            entry.unitBefore = Unit::Fahrenheit;
        } else if (firstLetter == 'K') {
            entry.unitBefore = Unit::Kelvin;
        } else {
            entry.unitBefore = Unit::Rankine;
        }

        // Determine unitAfter
        if (secondLetter == 'C') {
            entry.unitAfter = Unit::Celsius;
        } else if (secondLetter == 'F') {
            entry.unitAfter = Unit::Fahrenheit;
        } else if (secondLetter == 'K') {
            entry.unitAfter = Unit::Kelvin;
        } else {
            entry.unitAfter = Unit::Rankine;
        }

        entry.before = temp;

        // Perform conversion
        if (entry.unitBefore == Unit::Celsius) {
            if (entry.unitAfter == Unit::Fahrenheit) {
                entry.after = CtoF(temp);
            } else if (entry.unitAfter == Unit::Kelvin) {
                entry.after = CtoK(temp);
            } else {
                entry.after = CtoR(temp);
            }
        } else if (entry.unitBefore == Unit::Fahrenheit) {
            if (entry.unitAfter == Unit::Celsius) {
                entry.after = FtoC(temp);
            } else if (entry.unitAfter == Unit::Kelvin){
                entry.after = FtoK(temp);
            } else {
                entry.after = FtoR(temp);
            }
        } else if (entry.unitBefore == Unit::Kelvin) {
            if (entry.unitAfter == Unit::Celsius) {
                entry.after = KtoC(temp);
            } else if (entry.unitAfter == Unit::Fahrenheit) {
                entry.after = KtoF(temp);
            } else {
                entry.after = KtoR(temp);
            }
        } else {
            if (entry.unitAfter == Unit::Celsius) {
                entry.after = RtoC(temp);
            } else if (entry.unitAfter == Unit::Fahrenheit) {
                entry.after = RtoF(temp);
            } else {
                entry.after = RtoK(temp);
            }
        }

        history.push_back(entry);
    }
}
