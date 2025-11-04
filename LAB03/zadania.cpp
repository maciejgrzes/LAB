#include <iostream>
#include <math.h>
using namespace std;

/*
    Zadanie1:

Code:


int main() {
    int a, b;
    cin >> a;
    cin >> b;

    if (a == b) {
        cout << a << " = " << b << endl;
    } else if (a < b) {
        cout << a << " < " << b << endl;
    } else if (a > b) {
        cout << a << " > " << b << endl;
    }

    return 0;
}
*/

/*
    Zadanie2:

Code:


int main() {
    int a, b;
    cin >> a;
    cin >> b;

    if (a != b) {
        if (a < b) {
            cout << a << " < " << b << endl;
        } else {
            cout << a << " > " << b << endl;
        }
    } else {
        cout << a << " = " << b << endl;
    }
        

    return 0;
}
*/

/*
    Zadanie3:

Code:


int main () {
    double r;
    cin >> r;

    if (r >= 0.7 && r <= 1) {
        cout << "Bardzo silna" << endl;
    } else if (r >= 0.5) {
        cout << "Silna" << endl;
    } else if (r >= 0.3) {
        cout << "Umiarkowana" << endl;
    } else if (r >= 0.2) {
        cout << "Słaba" << endl;
    } else if (r >= 0) {
        cout << "Brak" << endl;
    }
    return 0;
}
*/

/*
    Zadanie5:

Code:


int main() {  
    int i = 0;
    while (true) {
        cout << i << endl;
        i++;
    }
    return 0;
}
*/

/*
    Zadanie7:

Code:

int main() {
    int i = 0;
    while (true) {
        if (i % 2 != 0) {
            cout << i << endl;
        }
        i++;
        if (i == 200) {break;}
    }

    return 0;
}
*/


/*
    Zadanie8:

Code:


int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
*/
