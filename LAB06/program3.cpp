#include <iostream>
#include <vector>
#include <string>
#include "header.h"
using namespace std;


int main() {
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
        // Also checking if the inputed temperature is within range
        switch (option) {
            // F to C
            case 1:
                temp = inputF();

                if (outOfRange(temp)) {
                    pressEnter();
                    break;
                }

                tempAfter = FtoC(temp);

                history.push_back(to_string(temp) + "°F" + " -> " + to_string(tempAfter) + "°C");
                historyF.push_back(to_string(temp) + "°F" + " -> " + to_string(tempAfter) + "°C");
                
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

                history.push_back(to_string(temp) + "°F" + " -> " + to_string(tempAfter) + "K");
                historyF.push_back(to_string(temp) + "°F" + " -> " + to_string(tempAfter) + "K");
                
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

                history.push_back(to_string(temp) + "°C" + " -> " + to_string(tempAfter) + "°F");
                historyC.push_back(to_string(temp) + "°C" + " -> " + to_string(tempAfter) + "°F");
                
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

                history.push_back(to_string(temp) + "°C" + " -> " + to_string(tempAfter) + "K");
                historyC.push_back(to_string(temp) + "°C" + " -> " + to_string(tempAfter) + "K");
                
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

                history.push_back(to_string(temp) + "K" + " -> " + to_string(tempAfter) + "°C");
                historyK.push_back(to_string(temp) + "K" + " -> " + to_string(tempAfter) + "°C");
                
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

                history.push_back(to_string(temp) + "K" + " -> " + to_string(tempAfter) + "°F");
                historyK.push_back(to_string(temp) + "K" + " -> " + to_string(tempAfter) + "°F");
                
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

                    default:
                        break;
                }
                break;
            //case 8:
                // TODO: implement clearing history
        }
    }

}
