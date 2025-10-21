#include <iostream>
using namespace std;

/*
    Zadanie1:

Code:
*/

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
