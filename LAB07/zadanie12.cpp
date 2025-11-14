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

int main() {
    double czas;
    clock_t start, koniec;

    start = clock();

    // drawLines(1, 50000); Czas dzialania = 69.6653 nice
    // 
    // string s = "asdyfaebhnkszhdgfkljhbaelkjhfgsaodfawhbdjnfeuyhaehfowuyh";
    // for (int i = 0; i < 1'000'000; i++) {
    //     reverse(s, size(s)-1);
    // } Czas dzialania = 7.4843 wow! 
    //
    // for (int i = 0; i < 100'000'000; i++) {
    //     sumR(1844674407370955161);
    // } Czas dzialania = 12.7338
    // 
    // for (int i = 0; i < 100'000'000; i++) {
    //     sumI(1844674407370955161, 19);
    // } Czas dzialania = 9.46461
    //
    // zabawne jest to ze aby policzic sume cyfr bliko maksymalnej liczbie która w c++ mozemy zastosowac 100 milionów razy 
    // zajmuje mniej niż 10 sekund

    koniec = clock();
    czas = (double)(koniec - start) / CLOCKS_PER_SEC;
    cout << endl << "Czas dzialania = " << czas << endl;

    return 0;
}
