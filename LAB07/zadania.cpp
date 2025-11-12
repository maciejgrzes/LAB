#include <iostream>
#include <string>
#include <cmath>
using namespace std; 

/*
    Zadanie1:

Code:


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
*/

/*
    Zadanie2:

Code:


int sumI(int n, int digits) {
    int res = 0;
    for (int i = 0; i < digits; i++) {
        res += n % 10;
        n = floor(n / 10);
    }
    return res;
}


int res = 0;

void sumR(int n) {
    if (n == 0) return;
    res += n % 10;
    sumR(floor(n / 10));
}

int main() {
    cout << sumI(55, 2) << endl;
    sumR(55);
    cout << res << endl;

    return 0;
}
*/ 

/*
    Zadanie3:

Code:


string gstr = "";

void reverse(string str, int index) {
    if (index < 0) return;
    gstr += str[index];
    reverse(str, index-1);
} 

int main() {
    string str;
    getline(cin, str);
    reverse(str, str.size());
    cout << gstr << endl;
    return 0;
}
*/

