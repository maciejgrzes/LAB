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
    cout << "7 - zakończ działanie programu" << endl;
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


// Wait for the user to press Enter before continuing
void pressEnter() {
    if (cin.peek() == '\n')
        cin.ignore();
    else
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Naciśnij Enter aby kontynuować...";
    cin.get();
}


int main() {
    while(true) {
        // Universal 'command' to clear the terminal since different operating systems use different commands
        // to clear the screen this ensures this program works on most* modern terminals
        cout << "\033[2J\033[1;1H";
        

        // Show the menu and get input from user
        showMenu();

        int option;
        cin >> option;

        double temp;

        if (option < 1 || option > 6) {
            return 0;
        }

        // Converting the input and printing it out based on the selected option than waiting for the user to press Enter for the loop to continue
        // Also checking if the inputed temperature is within range
        switch (option) {
            case 1:
                temp = inputF();

                if (outOfRange(temp)) {
                    pressEnter();
                    break;
                }

                cout << temp << "°F -> " << FtoC(temp) << "°C" << endl;
                
                pressEnter();

                break;

            case 2:
                temp = inputF();
                
                if (outOfRange(temp)) {
                    pressEnter();
                    break;
                }

                cout << temp << "°F -> " << FtoK(temp) << "K" << endl;

                pressEnter();

                break;

            case 3:
                temp = inputC();
                
                if (outOfRange(temp)) {
                    pressEnter();
                    break;
                }
                
                cout << temp << "°C -> " << CtoF(temp) << "°F" << endl;

                pressEnter();
                
                break;

            case 4:
                temp = inputC();
                
                if (outOfRange(temp)) {
                    pressEnter();
                    break;
                }
                
                cout << temp << "°C -> " << CtoK(temp) << "K" << endl;

                pressEnter();
                
                break;

            case 5:
                temp = inputK();
                
                if (outOfRange(temp)) {
                    pressEnter();
                    break;
                }
                
                cout << temp << "K -> " << KtoC(temp) << "°C" << endl;
                
                pressEnter();
                
                break;

            case 6:
                temp = inputK();

                if (outOfRange(temp)) {
                    pressEnter();
                    break;
                }
                
                cout << temp << "K -> " << KtoF(temp) << "°F" << endl;
                
                pressEnter();
                
                break;
        }
    }

}
