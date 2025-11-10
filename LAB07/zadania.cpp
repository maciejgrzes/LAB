#include <iostream>
#include <string>
using namespace std; 

/*
    Zadanie1:

Code:
*/

void printChars(char c, int count) {
    if (count <= 0) return;
    cout << c;
    printChars(c, count - 1);
}

void drawLines(int row, int n) {
    if (row > n) return;                     
    int spaces = n - row;                  
    int stars  = 2 * row - 1;               

    printChars(' ', spaces);
    printChars('*', stars);
    cout << '\n';

    drawLines(row + 1, n);                  
}

int main() {
    drawLines(1, 10);

    return 0;
}
