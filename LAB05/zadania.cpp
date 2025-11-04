#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
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
*/


/*
    Zadanie4:

Code:


int main() {
    int w, h;
    cin >> w;
    cin >> h;
    
    int table[h][w];

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << table[i][j] << " ";
        if (j == w-1)
            cout << endl;
        }
    }

    return 0;
}
*/

/*
    Zadanie5:

Code:


int main() {
    int tab[10] = {0};
    int n;

    for (int i = 0; i < 10; i++) {
        cin >> n;
        if (n >= 0 && n <= 10) {
            tab[i] = n;
        }
    }

    for (int num : tab) {
        cout << num << ' ';
    }
    cout << endl;

    int min = tab[0];
    int max = tab[0];
    double avg = 0;

    int count = 0;

    for (int i = 0; i < 10; i++) {
        if (tab[i] < min) {
            min = tab[i];
        } 
        if (tab[i] > max) {
            max = tab[i];
        }
        avg += tab[i];
        if (tab[i] != 0) {
            count += 1;
        }
    }

    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
    cout << "avg: " << avg/count << endl;

    return 0;
}
*/

/*
    Zadanie6:

Code:


int main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dist(0,10);

    int tab[10] = {0};

    for (int i = 0; i < 10; i++) {
        tab[i] = dist(gen);
    }
    
    int luckyNum = dist(gen);
    int count;

    for (int num : tab) {
        if (num == luckyNum) {
            count++;
        }
    }

    for (int num : tab) {
        cout << num << ' ';
    }
    cout << endl;
    cout << luckyNum << endl;
    cout << count << endl;

    return 0;
}
*/


/*
    Zadanie7 i 8:

Code:
*/

void printTable(int width, int height, int arr[3][3]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << arr[i][j] << " ";
        if (j == width-1)
            cout << endl;
        }
    }
}

int sumRow(int arr[3][3], int w, int target) {
    int res = 0;
    for (int i = 0; i < w; i++) {
        res += arr[target][i];
    }
    return res;
}

int sumColumn(int arr[3][3], int h, int target) {
    int res = 0;
    for (int i = 0; i < h; i++) {
        res += arr[i][target];
    }
    return res;
}

int main() {
    const int w = 3;
    const int h = 3;
    
    int tab1[w][h] = {0};
    int tab2[w][h] = {0};

    int add[w][h] = {0};
    int mul[w][h] = {0};
    
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dist(1,9);

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            tab1[i][j] = dist(gen);
            tab2[i][j] = dist(gen);
        }
    }

    // addition
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            add[i][j] = tab1[i][j] + tab2[i][j];
        }
    }

    // multiplication
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            mul[i][j] = sumRow(tab1, w, i) + sumColumn(tab2, h, j);
        }
    }
    
    // tab1
    printTable(w, h, tab1);

    cout << '+' << endl;

    // tab2
    printTable(w, h, tab2);

    cout << '=' << endl;

    // add
    printTable(w, h, add);

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    // tab1
    printTable(w, h, tab1);

    cout << '*' << endl;

    // tab2
    printTable(w, h, tab2);

    cout << '=' << endl;

    // mul
    printTable(w, h, mul);
    return 0;
}
