#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "header.h"
using namespace std;


int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    vector<string> history;
    vector<string> historyC;
    vector<string> historyF;
    vector<string> historyK;
    double tempAfter;
    int option;
    double temp;
    
    while(true) {
        // Universal 'command' to clear the terminal since different operating systems use different commands
        // to clear the screen this ensures this program works on most* modern terminals
        cout << "\033[2J\033[1;1H";
        
        // Show the menu and get input from user
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

                if (history.size() < 100) {
                    history.push_back(to_string(temp) + "°F -> " + to_string(tempAfter) + "°C");
                    historyF.push_back(to_string(temp) + "°F -> " + to_string(tempAfter) + "°C");
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
                
                if (history.size() < 100) {
                    history.push_back(to_string(temp) + "°F -> " + to_string(tempAfter) + "K");
                    historyF.push_back(to_string(temp) + "°F -> " + to_string(tempAfter) + "K");
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

                if (history.size() < 100) {
                    history.push_back(to_string(temp) + "°C -> " + to_string(tempAfter) + "°F");
                    historyC.push_back(to_string(temp) + "°C -> " + to_string(tempAfter) + "°F");
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

                if (history.size() < 100) {
                    history.push_back(to_string(temp) + "°C -> " + to_string(tempAfter) + "K");
                    historyC.push_back(to_string(temp) + "°C -> " + to_string(tempAfter) + "K");
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

                if (history.size() < 100) {
                    history.push_back(to_string(temp) + "K -> " + to_string(tempAfter) + "°C");
                    historyK.push_back(to_string(temp) + "K -> " + to_string(tempAfter) + "°C");
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

                if (history.size() < 100) {
                    history.push_back(to_string(temp) + "K -> " + to_string(tempAfter) + "°F");
                    historyK.push_back(to_string(temp) + "K -> " + to_string(tempAfter) + "°F");
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
                    case 1:
                        printVector(historyC);
                        pressEnter();
                        break;
                    
                    case 2:
                        printVector(historyF);
                        pressEnter();
                        break;
                    
                    case 3:
                        printVector(historyK);
                        pressEnter();
                        break;
                    
                    case 4:
                        printVector(history);
                        pressEnter();
                        break;

                    case 5:
                        cout << "\033[2J\033[1;1H";

                        printVector(history);
                        
                        showHistoryEditMenu();
                        int editOption;
                        cin >> editOption;

                        switch (editOption) {
                            case 1:
                                history.clear();
                                historyC.clear();
                                historyF.clear();
                                historyK.clear();

                                break;

                            case 2: {
                                cout << "Który index usunąć? ";

                                int indexToRemove;
                                cin >> indexToRemove;
                                
                                string target = history[indexToRemove];

                                auto inC = find(historyC.begin(), historyC.end(), target);
                                auto inF = find(historyF.begin(), historyF.end(), target);
                                auto inK = find(historyK.begin(), historyK.end(), target);
                                
                                if (inC != historyC.end()) historyC.erase(inC);
                                if (inF != historyF.end()) historyF.erase(inF);
                                if (inK != historyK.end()) historyK.erase(inK);

                                history.erase(history.begin() + (indexToRemove--));
                                
                                break;
                            }

                            case 3: {
                                cout << "Który index zmienić? ";

                                int indexToEdit;
                                cin >> indexToEdit;
                                
                                cout << "Podaj nową skale: ";

                                char scale;
                                cin >> scale;
                                
                                double newTemp;
                                double newTempAfter;
                                char newScale;

                                if (scale == 'C') {
                                    newTemp = inputC();

                                    if (outOfRange(newTemp)) {
                                        pressEnter();
                                        break;
                                    }

                                    cout << "Skala do przeliczenia: ";
                                    cin >> newScale;

                                    if (newScale == 'F') {
                                        newTempAfter = CtoF(newTemp);
                                        cout << newTemp << "°C -> " << newTempAfter << "°F" << endl;
                                        history[indexToEdit-1] = to_string(newTemp) + "°C -> " + to_string(newTempAfter) + "°F";

                                    } else if (newScale == 'K') {
                                        newTempAfter = CtoK(newTemp);
                                        cout << newTemp << "°C -> " << newTempAfter << "K" << endl;
                                        history[indexToEdit-1] = to_string(newTemp) + "°C -> " + to_string(newTempAfter) + "K";

                                    }
                                } else if (scale == 'F') {
                                    newTemp = inputF();

                                    if (outOfRange(newTemp)) {
                                        pressEnter();
                                        break;
                                    }

                                    cout << "Skala do przeliczenia: ";
                                    cin >> newScale;

                                    if (newScale == 'C') {
                                        newTempAfter = FtoC(newTemp);
                                        cout << newTemp << "°F -> " << newTempAfter << "°C" << endl;
                                        history[indexToEdit-1] = to_string(newTemp) + "°F -> " + to_string(newTempAfter) + "°C";

                                    } else if (newScale == 'K') {
                                        newTempAfter = FtoK(newTemp);
                                        cout << newTemp << "°F -> " << newTempAfter << "K" << endl;
                                        history[indexToEdit-1] = to_string(newTemp) + "°F -> " + to_string(newTempAfter) + "K";

                                    }
                                } else if (scale == 'K') {
                                    newTemp = inputK();

                                    if (outOfRange(newTemp)) {
                                        pressEnter();
                                        break;
                                    }

                                    cout << "Skala do przeliczenia: ";
                                    cin >> newScale;

                                    if (newScale == 'F') {
                                        newTempAfter = CtoF(newTemp);
                                        cout << newTemp << "K -> " << newTempAfter << "°F" << endl;
                                        history[indexToEdit-1] = to_string(newTemp) + "K -> " + to_string(newTempAfter) + "°F";

                                    } else if (newScale == 'C') {
                                        newTempAfter = CtoK(newTemp);
                                        cout << newTemp << "K -> " << newTempAfter << "°C" << endl;
                                        history[indexToEdit-1] = to_string(newTemp) + "K -> " + to_string(newTempAfter) + "°C";

                                    }

                                } 



                                break;
                            }

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
