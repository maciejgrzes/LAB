#include <cstdlib>
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

/*
    Zadanie7:

Code:

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
*/

/*
    Zadanie8:
Output:

0
2
4
6
8
10
12
14
16
18
20
22
24
26
28
30
32
34
36
38
40
42
44
46
48
50
52
54
56
58
60
62
64
66
68
70
72
74
76
78
80
82
84
86
88
90
92
94
96
98
100

Code:

int main() {
    for (int i = 0; i <= 100; i++) {
        if (i % 2 == 0) {
            cout << i << endl;
        }
    }

    return 0;
}
*/


/*
    Zadanie9:

Code:

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= 100; i++) {
        if (i % n == 0) {
            cout << i << endl;
        }
    }
    return 0;
}
*/

/*
    Zadanie10:

Code:

int main() {
    int n;
    cin >> n;

    int count = 0;

    for (int i = 0; i <= 100; i++) {
        if (i % n == 0) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
*/

/*
    Zadanie11:

Code:

int main() {
    int a, b;
    cin >> a;
    cin >> b;

    if (a > b) {
        for (int i = b; i <= a; i++) {
            if (i % 3 == 0) {
                cout << i << endl;
            }
        }
    } else {
        for (int i = a; i <= b; i++) {
            if (i % 3 == 0) {
                cout << i << endl;
            }
        }
    }
}
*/

/*
    Zadanie12:

Code:

int main() {
    int n;
    cin >> n;

    int sum = 0;

    for (int i = 0; i <= n; i++) {
        sum += i;
    }

    cout << sum / n << endl;
    return 0;
}
*/

/*
    Zadanie 13:
Output:

100
99
98
97
96
95
94
93
92
91
90
89
88
87
86
85
84
83
82
81
80
79
78
77
76
75
74
73
72
71
70
69
68
67
66
65
64
63
62
61
60
59
58
57
56
55
54
53
52
51
50
49
48
47
46
45
44
43
42
41
40
39
38
37
36
35
34
33
32
31
30
29
28
27
26
25
24
23
22
21
20
19
18
17
16
15
14
13
12
11
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
    for (int i = 100; i >= 0; i--) {
        cout << i << endl;
    }
        
    return 0;
}
*/

/*
    Zadanie14

Code:

int main() {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    if (a < b && a < c) {
        cout << a << endl;
    } else if (b < a && b < c) {
        cout << a << endl;
    } else if (c < b && c < a) {
        cout << c << endl;
    }
    return 0;
}
*/

/*
    Zadanie15:

Code:

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++) {
        cout << rand() % (m+1) << endl;
    }
    return 0;
}
*/

/*
    Zadanie 16:

Code:
*/
int main() {
    int l;
    cout << "Podaj liczbe w przedziale 1-10: " << endl;
    cin >> l;
    if (l < 1 || l > 10) {
        cout << "Przedzial to 1-10!!" << endl;
        return 1;
    }
    int temp;
    int count = 0;
    for (int i = 1; i <= 10; i++) {
        int temp = rand() % 10 + 1;
        if (temp == l) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
