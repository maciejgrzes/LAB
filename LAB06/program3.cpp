#include <iostream>
#include <vector>
#include "header.h"
using namespace std;


int main() {
    vector<Entry> history;
    double tempAfter;
    int option;
    double temp;
    Entry entry;
    
    while(true) {
        // Universal 'command' to clear the terminal since different operating systems use different commands
        // to clear the screen, this ensures this program works on most* modern terminals
        cout << "\033[2J\033[1;1H";
        
        showMenu();
        cin >> option;

        if (option < 1 || option > 7) {
            return 0;
        }

        // Converting the input and printing it out based on the selected option than waiting for the user to press Enter for the loop to continue
        // Also checking if the inputed temperature is within range i.e. not below absolute zero
        switch (option) {
            // F to C
            case 1:
                temp = inputF();

                if (outOfRange(temp)) {
                    pressEnter();
                    break;
                }

                tempAfter = FtoC(temp);

                entry = {temp, Unit::Fahrenheit, tempAfter, Unit::Celsius};

                if (history.size() < 100) {
                    history.push_back(entry);
                } else {
                    cout << "Brak miejsca do zapisania w historii!" << endl;
                }
                
                cout << temp << "°F -> " << tempAfter << "°C" << endl;

                pressEnter();

                break;
            
            // F to K
            case 2:
                temp = inputF();
                
                if (outOfRange(temp)) {
                    pressEnter();
                    break;
                }

                tempAfter = FtoK(temp);
                
                entry = {temp, Unit::Fahrenheit, tempAfter, Unit::Kelvin};

                if (history.size() < 100) {
                    history.push_back(entry);
                } else {
                    cout << "Brak miejsca do zapisania w historii!" << endl;
                }

                cout << temp << "°F -> " << tempAfter << "K" << endl;

                pressEnter();

                break;

            // C to F
            case 3:
                temp = inputC();
                
                if (outOfRange(temp)) {
                    pressEnter();
                    break;
                }
                
                tempAfter = CtoF(temp);

                entry = {temp, Unit::Celsius, tempAfter, Unit::Fahrenheit};

                if (history.size() < 100) {
                    history.push_back(entry);
                } else {
                    cout << "Brak miejsca do zapisania w historii!" << endl;
                }

                cout << temp << "°C -> " << tempAfter << "°F" << endl;

                pressEnter();
                
                break;

            // C to K
            case 4:
                temp = inputC();
                
                if (outOfRange(temp)) {
                    pressEnter();
                    break;
                }
                
                tempAfter = CtoK(temp);

                entry = {temp, Unit::Celsius, tempAfter, Unit::Kelvin};

                if (history.size() < 100) {
                    history.push_back(entry);
                } else {
                    cout << "Brak miejsca do zapisania w historii!" << endl;
                }

                cout << temp << "°C -> " << tempAfter << "K" << endl;

                pressEnter();
                
                break;
            
            // K to C
            case 5:
                temp = inputK();
                
                if (outOfRange(temp)) {
                    pressEnter();
                    break;
                }
                
                tempAfter = KtoC(temp);

                entry = {temp, Unit::Kelvin, tempAfter, Unit::Celsius};

                if (history.size() < 100) {
                    history.push_back(entry);
                } else {
                    cout << "Brak miejsca do zapisania w historii!" << endl;
                }

                cout << temp << "K -> " << tempAfter << "°C" << endl;
                
                pressEnter();
                
                break;
            
            // K to F
            case 6:
                temp = inputK();

                if (outOfRange(temp)) {
                    pressEnter();
                    break;
                }
                
                tempAfter = KtoF(temp);

                entry = {temp, Unit::Kelvin, tempAfter, Unit::Fahrenheit};

                if (history.size() < 100) {
                    history.push_back(entry);
                } else {
                    cout << "Brak miejsca do zapisania w historii!" << endl;
                }

                cout << temp << "K -> " << tempAfter << "°F" << endl;
                
                pressEnter();
                
                break;
            
            // Printing conversion history
            case 7:
                cout << "\033[2J\033[1;1H";
                
                showHistoryMenu();

                int historyOption;
                cin >> historyOption;
    
                switch (historyOption) {
                    // Print only C -> something
                    case 1:
                        printVector(history, Unit::Celsius);
                        pressEnter();
                        break;
                    
                    // Print only F -> something
                    case 2:
                        printVector(history, Unit::Fahrenheit);
                        pressEnter();
                        break;
                    
                    // Print only K -> something
                    case 3:
                        printVector(history, Unit::Kelvin);
                        pressEnter();
                        break;
                    
                    // Print everything
                    case 4:
                        printVector(history);
                        pressEnter();
                        break;
                    
                    // Edit the history
                    case 5:
                        cout << "\033[2J\033[1;1H";

                        printVector(history);
                        
                        showHistoryEditMenu();
                        int editOption;
                        cin >> editOption;

                        switch (editOption) {
                            // Clear the entire history
                            case 1:
                                history.clear();

                                break;
                            
                            // Clear specified intex
                            case 2: {
                                cout << "Który index usunąć? ";

                                int indexToRemove;
                                cin >> indexToRemove;

                                // user counts from 1
                                indexToRemove--;

                                if (indexToRemove >= 0 && indexToRemove < history.size()) {
                                    history.erase(history.begin() + indexToRemove);
                                } else {
                                    cout << "Nieprawidłowy index!\n";
                                }
                                
                                break;
                            }
                            
                            // Edit a specified index
                            case 3:
                                calculateAndReplace(history);

                                break;
                            // Randomly fill the history
                            case 4:
                                generateRandomHistory(history);

                                break;

                            default:
                                break;
                        }

                    default:
                        break;
                }
                break;
        }
    }
}
