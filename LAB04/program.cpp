#include <iostream>
using std::cout;
using std::endl;

double FtoC (double F) {return (F - 32.0) * 5.0/9.0;}

double FtoK (double F) {return (F + 459.67) * 5.0/9.0;}

double CtoF (double C) {return C * 9.0/5.0 + 32.0;}

double CtoK (double C) {return C + 273.15;}

double KtoC (double K) {return K - 273.15;}

double KtoF (double K) {return K * 9.0/5.0 - 459.67;}



int main() {
    int n = 25;

    cout << FtoC(n) << endl;
    cout << FtoK(n) << endl;
    cout << CtoF(n) << endl;
    cout << CtoK(n) << endl;
    cout << KtoC(n) << endl;
    cout << KtoF(n) << endl;
        

    return 0;
}
