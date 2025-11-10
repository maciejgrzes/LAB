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
*/

/*
    Zadanie3:

Code:


double temp1[10] = {0};
double temp2[10] = {0};
int idx = 0;

double calculate(double temp) {
    double tmp = temp + 273.15;
    return tmp;
}

bool saveToTable(double t1, double t2) {
    if (idx > 10) {
        cout << "No space!";
        return false;
    } else {
        temp1[idx] = t1;
        temp2[idx] = t2;
        idx++;
        return true;
    }
}

void print() {
    if (idx > 10) return;
    for (int i = 0; i < idx; i++) {
        cout << i << ':' << temp1[i] << " -> " << temp2[i] << endl;
    }
}


int main() {
    while (true) {
        double temp;
        cin >> temp;

        if (saveToTable(temp, calculate(temp))) {
            print();
        } else {
            cout << "no more space";
            return 0;
        }
    }
    return 0;
}
*/ 

