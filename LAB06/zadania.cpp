#include <iostream>
using namespace std;

/*
    Zadanie1:

Code:


const int a = 20;
const int b = 10;

int sum(int x, int y) {
    return x + y;
}

int main () {

    cout << sum(a, b) << endl;

    int a = 1;
    int b = 1;

    cout << sum(a, b) << endl;

    return 0;
}
*/ 

/*
    zadanie2:

Code:
*/

int tab[10] = {0};
int rozmiar = 10;

void printTab() {
    for (int num : tab) {
        cout << num << ' ';
    }
    cout << endl;
}

void deleteIndex(int index) {
    if (index > rozmiar-1) {
        cout << "Out of range!";
        return;
    }
    for (int i = index; i < rozmiar; i++) {
        tab[i] = tab[i+1];
    }
    tab[rozmiar-1] = 0;
    rozmiar--;
}

int main() {
    int v;
    for (int i = 0; i < rozmiar; i++) {
        cin >> v;
        tab[i] = v;
    }


    printTab();

    int index;
    cin >> index;
    deleteIndex(index);

    printTab();
    return 0;
}
