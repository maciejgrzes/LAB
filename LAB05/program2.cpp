#include <iostream>
#include "header.h"
using namespace std;


int main() {
    double memory[100] = {0};
    int dataCounter = 0;


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
