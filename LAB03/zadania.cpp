#include <iostream>
using namespace std;

/*
    Zadanie1:

Code:


int main() {
    int a, b;
    cin >> a;
    cin >> b;

    if (a == b) {
        cout << a << " = " << b << endl;
    } else if (a < b) {
        cout << a << " < " << b << endl;
    } else if (a > b) {
        cout << a << " > " << b << endl;
    }

    return 0;
}
*/

int main() {
    int a, b;
    cin >> a;
    cin >> b;

    if (a != b) {
        if (a < b) {
            cout << a << " < " << b << endl;
        } else {
            cout << a << " > " << b << endl;
        }
    } else {
        cout << a << " = " << b << endl;
    }
        

    return 0;
}
