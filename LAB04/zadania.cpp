#include <cstdlib>
#include <ctime>
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

/*
    Zadanie5:

Code:


int fun(int n) {
    int tmp = 1;
    for (int i = 1 ; i <= n; i++) {
        tmp *= i;
    }
    return tmp;
}

int main() {
    int n;
    cin >> n;

    cout << fun(n) << endl;

    return 0;
}
*/

/*
    Zadanie6:

Code:


int fun(int n) {
    int tmp = 1;
    for (int i = 0; i < n; i++) {
        tmp *= 2;
    }
    return tmp;
}

int main() {
    int n;
    cin >> n;

    cout << fun(n) << endl;

    return 0;
}
*/

/*
    Zadanie7:

Code:


void fun(int n) {
    srand(static_cast<unsigned>(time(nullptr)));

    int tmp;
    int count = 0;
    for (int i = 1; i <= 10; i++) {
        int temp = rand() % 9 + 1;
        if (temp == n) {
            count++;
        }
    }

    cout << count << endl;
    cout << count * 10 << '%' <<endl;
}

int main() {
    int n;
    cin >> n;
    if (n < 1 || n > 10) {
        cout << "Przedzial to 1-10!!" << endl;
        return 1;
    }
8
    fun(n);

    return 0;
}
*/

/*
    Zadanie8:

Code:


int fun1(int n) {
    return n/2;
}

int fun2(int n) {
    return (n-1)/2;
}

int main() {
    
    for (int n = 0; n <= 100; n++) {
        if (n % 2 == 0) {
            cout << fun1(n) << endl;
        } else {
            cout << fun1(n) << endl;
        }
    }

    return 0;
}
*/

