#include <iostream>
using namespace std;

/*
    Zadanie1:

Code:


void fun1(int a, int b) {
    if (a < b) {
       cout << b << endl;
    } else {
       cout << a << endl;
    }
}

int fun2(int a, int b) {
    if (a < b) {
        return b;
    } else {
        return a;
    } 
}

int main() {
    int a, b;
    cin >> a;
    cin >> b;

    fun1(a, b);
    fun2(a, b);
        
    return 0;
}
*/

/*
    Zadanie2:

Code:


void fun(int n) {
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            cout << i << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;

    fun(n);

    return 0;
}
*/

//Zadanie 3 jest w pliku LAB/LAB03/kalkulator.cpp 

/*
    Zadanie4:

Code:


int fun(int a, int b) {
    int tmp = 1;
    for (int i = 0; i < b; i++) {
        tmp *= a;
    }
    return tmp;
}

int main() {
    int a, b;
    cin >> a;
    cin >> b;

    cout << fun(a, b) << endl;

    return 0;
}
*/


