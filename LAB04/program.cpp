#include <iostream>
using namespace std;

/*
double FtoC (double F) {return (F - 32.0) * 5.0/9.0;}

double FtoK (double F) {return (F + 459.67) * 5.0/9.0;}

double CtoF (double C) {return C * 9.0/5.0 + 32.0;}

double CtoK (double C) {return C + 273.15;}

double KtoC (double K) {return K - 273.15;}

double KtoF (double K) {return K * 9.0/5.0 - 459.67;}
*/

void showMenu() {
    cout << "1 - przelicz Fahr -> Celsius" << endl;
    cout << "2 - przelicz Fahr -> Kelwin" << endl;
    cout << "3 - przelicz Celsius -> Fah" << endl;
    cout << "4 - przelicz Celsius -> Kelwin" << endl;
    cout << "5 - przelicz Kelwin -> Celsius" << endl;
    cout << "6 - przelicz Kelwin -> Fahr" << endl;
    cout << "7 - zakończ działanie programu" << endl;
}

double convert(int i, double n) {
    switch(i) {
    case 1: // FtoC
        return (n - 32.0) * 5.0/9.0;
    case 2: // FtoK
        return (n + 459.67) * 5.0/9.0;
    case 3: // CtoF
        return n * 9.0/5.0 + 32.0;
    case 4: // CtoK
        return n + 273.15;
    case 5: // KtoC
        return n - 273.15;
    case 6: // KtoF
        return n * 9.0/5.0 - 459.67;
    default:
        return 0;
    }
}


int main() {
    showMenu();
    

    return 0;
}
