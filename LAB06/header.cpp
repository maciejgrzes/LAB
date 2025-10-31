#include "header.h"
#include <iostream>
#include <limits>
#include <random>
#include <string>
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

// Prosedure to replace a history entry with user input
void calculateAndReplace(vector<string>& vec) {
    int indexToEdit;
    
    do {
        cout << "Który index zmienić? ";
        cin >> indexToEdit;
    } while (indexToEdit < 0 || indexToEdit > vec.size());

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

// Generating random numbers to put into history
void generateRandomHistory(vector<string>& history, vector<string>& historyC, vector<string>& historyF, vector<string>& historyK) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> chars(0,2);
    uniform_int_distribution<int> valuesK(0, 1000);
    uniform_int_distribution<int> valuesC(-274, 727);
    uniform_int_distribution<int> valuesF(-460, 540);

    char letters[] = {'C', 'F', 'K'};

    int firstLetter = chars(gen);
    int secondLetter;

    do {
        secondLetter = chars(gen);
    } while (secondLetter == firstLetter);

    double temp = valuesC(gen);

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

    char option;

    if (count + history.size() > 100) {
        cout << "Zamało miejsca! Chcesz wypełnić historie " << count - ( ( count + history.size() ) - 100 ) << " elementami? (Y/n) ";
        cin >> option;

        if (option == 'Y' || option == 'y') {
            count = count - ( ( count + history.size() ) - 100 );
        } else {
            return;
        }
    }

    for (int i = 0; i < count; i++) {
        int firstIndex = chars(gen);
        int secondIndex;

        do {
            secondLetter = chars(gen);
        } while (secondLetter == firstLetter);

        double temp = valuesC(gen);

        char firstLetter = letters[firstIndex];
        char secondLetter = letters[secondIndex];

        switch (firstLetter) {
            case 'C': {
                if (secondLetter == 'F') {
                    double newTemp = CtoF(temp);
                    history.push_back(to_string(temp) + "°C -> " + to_string(newTemp) + "°F");
                    historyC.push_back(to_string(temp) + "°C -> " + to_string(newTemp) + "°F");
                } else {
                    double newTemp = CtoK(temp);
                    history.push_back(to_string(temp) + "°C -> " + to_string(newTemp) + "K");
                    historyC.push_back(to_string(temp) + "°C -> " + to_string(newTemp) + "K");
                }

                break; 
            }
            
            case 'F': {
                if (secondLetter == 'C') {
                    double newTemp = FtoC(temp);
                    history.push_back(to_string(temp) + "°F -> " + to_string(newTemp) + "°C");
                    historyF.push_back(to_string(temp) + "°F -> " + to_string(newTemp) + "°C");
                } else {
                    double newTemp = FtoK(temp);
                    history.push_back(to_string(temp) + "°F -> " + to_string(newTemp) + "K");
                    historyF.push_back(to_string(temp) + "°F -> " + to_string(newTemp) + "K");
                }

                break; 
            }

            case 'K': {
                if (secondLetter == 'F') {
                    double newTemp = KtoF(temp);
                    history.push_back(to_string(temp) + "K -> " + to_string(newTemp) + "°F");
                    historyK.push_back(to_string(temp) + "K -> " + to_string(newTemp) + "°F");
                } else {
                    double newTemp = KtoC(temp);
                    history.push_back(to_string(temp) + "K -> " + to_string(newTemp) + "°C");
                    historyK.push_back(to_string(temp) + "K -> " + to_string(newTemp) + "°C");
                }

                break; 
            }      
        }
    }
}
