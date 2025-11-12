#include <iostream>
#include <limits>
using namespace std;

const int rows = 10;
const int cols = 10;

void printMatrix(int matrix[rows][cols]) {
    cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
    for (int i = 0; i < rows; i++) {
        cout << i << ' ';
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                cout << matrix[i][j] << ' ';
            } else {
                cout << '*' << ' ';
            }
        }
        cout << endl;
    }
}

bool validPosition(int matrix[rows][cols], int x, int y, int h, int w) {
    if (x + h > rows || y + w > cols)
        return false;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (matrix[x + i][y + j] != 0)
                return false;
        }
    }

    return true;
}

void placeShip(int matrix[rows][cols], int x, int y, int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            matrix[x + i][y + j] = 1;
        }
    }
}

void removeShip(int matrix[rows][cols], int x, int y) {
    if (x < 0 || y < 0 || x >= rows || y >= cols) return;

    if (matrix[x][y] == 0) return;

    matrix[x][y] = 0;

    removeShip(matrix, x + 1, y);
    removeShip(matrix, x - 1, y);
    removeShip(matrix, x, y + 1);
    removeShip(matrix, x, y - 1);
}

void pressEnter() {
    if (cin.peek() == '\n')
        cin.ignore();
    else
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Press enter to continue...";
    cin.get();
}

void didItHit(int x, int y, int arr[rows][cols]) {
    if (arr[x][y] == 1) {
        cout << "HIT!!" << endl;
        removeShip(arr, x, y);
    } else {
        cout << "MISS!!" << endl;
    }
}

bool isEmpty(int arr[rows][cols]) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            count++;
        }
    }

    if (count == 0) return true;
    else return false;
}

int main() {
    int pole1[rows][cols] = {0};
    int pole2[rows][cols] = {0};

    int w, h;
    int x, y;

    // Player 1
    for (int i = 0; i < 4; i++) {
        cout << "\033[2J\033[1;1H";
        
        printMatrix(pole1);
        cout << endl;
        cout << "Player 1!" << endl;

        switch (i) {
            case 0:
                cout << "Choose the position of the 2x2 ship:" << endl;
                w = 2;
                h = 2;
                break;
            case 1:
                cout << "Choose the position of the 2x3 ship:" << endl;
                w = 3;
                h = 2;
                break;
            case 2:
                cout << "Choose the position of the 1x4 ship:" << endl;
                w = 4;
                h = 1;
                break;
            case 3:
                cout << "Choose the position of the 1x5 ship:" << endl;
                w = 5;
                h = 1;
                break;
        }

        char orientation;
        cout << "Enter orientation (H for horizontal, V for vertical): ";
        cin >> orientation;

        // Swap width and height for vertical placement
        if (orientation == 'V' || orientation == 'v') {
            int temp = w;
            w = h;
            h = temp;
        }

        cout << "Enter top-left position: " << endl;
        cout << "Row: ";
        cin >> x; 
        cout << "Column: ";
        cin >> y;

        if (validPosition(pole1, x, y, h, w)) {
            placeShip(pole1, x, y, h, w);
            cout << endl << "Ship placed successfully." << endl;
        } else {
            cout << endl << "Error: Ship does not fit or collides with another shape." << endl;
            return 0;
        }

        printMatrix(pole1);
        pressEnter();
    }

    // Player 2
    for (int i = 0; i < 4; i++) {
        cout << "\033[2J\033[1;1H";

        printMatrix(pole2);
        cout << endl;

        cout << "Player 2!" << endl;

        switch (i) {
            case 0:
                cout << "Choose the position of the 2x2 ship:" << endl;
                w = 2;
                h = 2;
                break;
            case 1:
                cout << "Choose the position of the 2x3 ship:" << endl;
                w = 3;
                h = 2;
                break;
            case 2:
                cout << "Choose the position of the 1x4 ship:" << endl;
                w = 4;
                h = 1;
                break;
            case 3:
                cout << "Choose the position of the 1x5 ship:" << endl;
                w = 5;
                h = 1;
                break;
        }

        char orientation;
        cout << "Enter orientation (H for horizontal, V for vertical): ";
        cin >> orientation;

        if (orientation == 'V' || orientation == 'v') {
            int temp = w;
            w = h;
            h = temp;
        }

        cout << "Enter top-left position: " << endl;
        cout << "Row: ";
        cin >> x; 
        cout << "Column: ";
        cin >> y;

        if (validPosition(pole2, x, y, h, w)) {
            placeShip(pole2, x, y, h, w);
            cout << endl << "Ship placed successfully." << endl;
        } else {
            cout << endl << "Error: Ship does not fit or collides with another shape." << endl;
            return 0;
        }

        printMatrix(pole2);
        pressEnter();
    }

    while (true) {
        cout << "\033[2J\033[1;1H";
        printMatrix(pole1);
        cout << endl;
        cout << "Player 1!" << endl;
        cout << "Where do you shoot?" << endl;
        cin >> x >> y;

        didItHit(x, y, pole2);
        if (isEmpty(pole2)) {
            cout << "Player 1 wins!!" << endl;
            pressEnter();
            break;
        }
        pressEnter();

        cout << "\033[2J\033[1;1H";
        printMatrix(pole2);
        cout << endl;
        cout << "Player 1!" << endl;
        cout << "Where do you shoot?" << endl;
        cin >> x >> y;

        didItHit(x, y, pole1);
        if (isEmpty(pole1)) {
            cout << "Player 2 wins!!" << endl;
            pressEnter();
            break;
        }
        pressEnter();
    }

    return 0;
}
