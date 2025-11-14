#include <climits>
#include <vector>
#include <iostream> 
#include <stdlib.h>
#include <string>
#include <time.h>
#include <cmath>
using namespace std;


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

int sumI(long long n, int digits) {
    int res = 0;
    for (int i = 0; i < digits; i++) {
        res += n % 10;
        n = floor(n / 10);
    }
    return res;
}

int res = 0;

void sumR(unsigned long long n) {
    if (n == 0) return;
    res += n % 10;
    sumR(floor(n / 10));
}

string gstr = "";

void reverse(string str, int index) {
    if (index < 0) return;
    gstr += str[index];
    reverse(str, index-1);
} 

vector<int> fibarr = {0, 1};
void fibI(int n) {
    while ((int)fibarr.size() <= n) {
        int s = fibarr.size();
        fibarr.push_back(fibarr[s - 1] + fibarr[s - 2]);
    }
}

void fibR(int n) {
    int s = fibarr.size();
    if (s > n) return;
    fibarr.push_back(fibarr[s - 1] + fibarr[s - 2]);
    fibR(n);
}

int powI(int base, int exponent) {
    int res = base;
    for (int i = 1; i < exponent; i++) {
        res *= base;
    }
    return res;
}

int powR(int base, int exponent) {
    if (exponent == 0) return 1;
    return base * powR(base, exponent- 1);
}

int main() {
    double czas;
    clock_t start, koniec;

    start = clock();

    // drawLines(1, 50000); Czas dzialania = 69.6653 nice
    // 
    //
    //
    // string s = "asdyfaebhnkszhdgfkljhbaelkjhfgsaodfawhbdjnfeuyhaehfowuyh";
    // for (int i = 0; i < 1'000'000; i++) {
    //     reverse(s, size(s)-1);
    // } Czas dzialania = 7.4843 wow! 
    //
    //
    //
    // for (int i = 0; i < 100'000'000; i++) {
    //     sumR(ULLONG_MAX);
    // } Czas dzialania = 16.3731
    // 
    //
    //
    // for (int i = 0; i < 100'000'000; i++) {
    //     sumI(ULLONG_MAX, 20);
    // } Czas dzialania = 10.6727
    //
    //
    // fibI(200'000'000); Czas dzialania = 5.91978
    //
    // fibR(1000); recursion depth limit moment
    //
    //
    // powI i powR so mega szybkie nawet dla 2^127 ok 2e-06

    koniec = clock();
    czas = (double)(koniec - start) / CLOCKS_PER_SEC;
    cout << endl << "Czas dzialania = " << czas << endl;

    return 0;
}
