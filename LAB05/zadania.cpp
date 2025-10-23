#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

/*
    Zadanie1:

Code:


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
*/


/*
    Zadanie2:

Code:


void fibonacci(int fib[],int size) {
    for (int i = 2; i <= size; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main() {
    int size;
    cin >> size;

    int fib[size];
    fib[0] = 0;
    fib[1] = 1;

    fibonacci(fib, size);

    for (int num : fib) {
        cout << num << endl;
    }

    return 0;
}
*/

/*
    Zadanie3:

Code:
*/

int min(int table[]) {
    int tmp = table[0];

    for (int i = 1; i < 10; i++) {
        if (tmp > table[i]) tmp = table[i];
    }
    return tmp;
}

int max(int table[]) {
    int tmp = table[0];

    for (int i = 1; i < 10; i++) {
        if (tmp < table[i]) tmp = table[i];
    }
    return tmp;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int table[10];

    for (int i = 0; i < 10; i++) {
        table[i] = rand() % 100 + 1;
    }

    double avg = 0;

    for (int num : table) {
        avg += num;
    }
    avg /= 10;

    int lessCount = 0;
    int moreCount = 0;

    for (int num : table) {
        if (num < avg) {
            lessCount++;
        } else {
            moreCount++;
        }
    }


    cout << "Lowest value: " << min(table) << endl;
    cout << "Highest value: " << max(table) << endl;
    cout << "Average: " << avg << endl;
    cout << "Less than average: " << lessCount << endl;
    cout << "More than average: " << moreCount << endl;

    return 0;
}
