#include <iostream>
using namespace std;

/*
    Zadanie1:
Output:

5
6
7

5
6

0
2
4
6
8
10

10
9
8
7
6
5
4
3
2
1
0

Code:

int main() {
    for (int i = 5; i <= 7; i++) {
       cout << i << endl;
    }

cout << endl;

    for (int i = 5; i < 7; i++) {
       cout << i << endl;
    }

    cout << endl;

    for (int i = 0; i <= 10; i += 2) {
       cout << i << endl;
    }

    cout << endl;
    
    for (int i = 10; i >= 0; i--) {
       cout << i << endl;
    }

    return 0;
}
*/

/*
    Zadanie6:

Code:

int main() { 
    int fahr, celsius; 
    int start, limit, krok; 

    start = 0; 

    cin >> limit;
    cin >> krok;

    fahr = start; 
    for(fahr = 0.0; fahr <= limit; fahr = fahr + krok) { 
        float celsius = (5.0/9.0)*(fahr - 32.0); 
        cout << fahr << "\t" << celsius << endl;
    }  
}
*/


int main() {

    int x;
    for (int i = 0; i <= 10; i++) {
        cin >> x;
        if (x > -1) {
            cout << x << endl;
        }
    }


    return 0;
}
