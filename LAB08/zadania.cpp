#include <iostream>
#include <random>
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


int main() {
    int size;
    cin >> size;
    
    double *arr = new double[size];
    double *ptr = &arr[size-1];
    
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
*/

/*
    Zadanie4:

Code:


void printArr(int size, int *arr) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    } cout << endl;
}

double avg(int *arr, int size) {
    double res = 0;
    for (int i = 0; i < size; i++) {
        res += arr[i];
    }
    return res / size;
}

int main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> num(0,10);
    
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = num(gen);
    }

    printArr(size, arr);
    cout << "Avg: " << avg(arr, size) << endl;

    delete[] arr; 
    return 0;
}
*/
/*
    Zadanie5:

Code:


int max(int *arr, int size) {
    int res = arr[0];
    for (int i = 0; i < size; i++) {
        if (res < arr[i]) {
            res = arr[i];
        }
    }
    return res;
}

int min(int *arr, int size) {
    int res = arr[0];
    for (int i = 0; i < size; i++) {
        if (res > arr[i]) {
            res = arr[i];
        }
    }
    return res;
}

int main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> num(0,10);
    
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = num(gen);
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    } cout << endl;

    int x, y;
    cin >> x >> y;


    cout << arr[x] + arr[y] << endl;
    cout << arr[x] * arr[y] << endl;
    cout << max(arr, size) - min(arr, size) << endl;
    
    delete[] arr;
    return 0;
}
*/
