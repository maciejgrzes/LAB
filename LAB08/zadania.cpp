#include <iostream>
using namespace std;

/*
    Zadanie1:

Code:


int main() {
    int x;
    int *ptr = &x;

    cin >> *ptr;
    
    cout << ptr << endl << *ptr << endl;
    
    return 0;
}
*/

/*
    Zadanie2:

Code:


int main() {
    int tab[10];
    int *ptr;

    ptr = &tab[0];

    for (int num : tab) {
        cout << num << ' ';
    } cout << endl;
    
    ptr += 7;
    *ptr = 77;

    for (int num : tab) {
        cout << num << ' ';
    } cout << endl;

    return 0;
}
*/

/*
    Zadanie2.1;
Code:


int main() {
    int tab[10] = {0};
    int *ptr;

    ptr = &tab[0];

    for (int num : tab) {
        cout << num << ' ';
    } cout << endl;

    for (int i = 0; i < 10; i++) {
        *ptr = 9;
        ptr++;
    }

    for (int num : tab) {
        cout << num << ' ';
    } cout << endl;

    return 0;
}
*/

/*
    Zadanie3:

Code:
*/

int main() {
    int size;
    cin >> size;
    
    float *arr = new float[size];
    float *ptr = &arr[size-1];
    
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    while (true) {
        cout << ptr << endl;
        cout << *ptr << endl;
        if (ptr == &arr[0]) {
            break;
        } else {
            ptr--;
        }
    }

    delete[] arr;
    return 0;
}
