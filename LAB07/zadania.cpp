#include <iostream>
#include <string>
#include <cmath>
#include <vector>
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
    reverse(str, str.size()-1);
    cout << gstr << endl;
    return 0;
}
*/

/*
    Zadanie4:

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
    reverse(str, str.size()-1);

    cout << str << endl;
    cout << gstr << endl;

    if (str == gstr) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
*/

/*
    Zadanie5:

Code:


int maxI(int arr[], int size) {
    int res = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > res) {
            res = arr[i];
        }
    }
    return res;
}

int maxR(int arr[], int index) {
    if (index < 0) return INT_MIN;

    int sub = maxR(arr, index - 1);
    return max(arr[index], sub);
}


int main() {
    int n, size;
    cin >> size;
    
    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> n;
        arr[i] = n;
    }

    for (int num : arr) {
        cout << num << ' ';
    } cout << endl;

    cout << maxI(arr, size) << endl;
    cout << maxR(arr, size - 1) << endl;
    return 0;
}
*/

/*
    Zadanie6:

Code:


vector<int> fibarr = {0, 1};

void fibI(int n) {
    while ((int)fibarr.size() <= n) {
        int s = fibarr.size();
        fibarr.push_back(fibarr[s - 1] + fibarr[s - 2]);
    }
}

void fibR(int n) {
    int s = fibarr.size();
    if (s > n) return; // done
    fibarr.push_back(fibarr[s - 1] + fibarr[s - 2]);
    fibR(n);
}


int main() {
    int n;
    cin >> n;

    char c;
    cin >> c;

    if (c != 'r') fibI(n);
    else fibR(n);

    cout << fibarr.back() << endl;

    return 0;
}
*/


/*
    Zadanie7:

Code:


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
    cout << powI(3, 8) << endl;
    cout << powR(3, 8) << endl;
    return 0;
}
*/

/*
    Zadanie8:

Code:


int factI(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

int factR(int n) {
    if (n == 0) return 1;
    return n * factR(n-1);
}

int main() {
    cout << factI(6) << endl;
    cout << factR(6) << endl;

    return 0;
}
*/

/*
    Zadanie9:

Code:
*/

int sumI(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res += i;
    }
    return res;
}

int sumR(int n) {
    if (n == 0) return 0;
    return n + sumR(n-1);
}

int main() {
    int n;
    cin >> n;

    cout << sumI(n) << endl;
    cout << sumR(n) << endl;

    return 0;
}
