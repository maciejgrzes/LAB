#include <iostream>
using namespace std;

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
