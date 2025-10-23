#include <iostream>
using namespace std;

/*
    Zadanie1:

Code:
*/

int main() {
    int table[10];
    int tmp;
    for (int i = 0; i < 10; i++) {
        cin >> tmp;
        table[i] = tmp;
    }

    for (int i = 9; i >= 0; i--) {
        cout << table[i] << endl;
    }

    return 0;
}
