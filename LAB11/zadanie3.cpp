#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream inFile("zadanie2.txt");
    ofstream outFile("zadanie3.txt");

    if (!inFile) {
        cout << "No such file..." << endl;
        return 1;
    }

    if (!outFile) {
        cout << "No such file..." << endl;
        return 1;
    }

    
    int arr[10] = {0};
    int i = 0;

    while (inFile >> arr[i] && i < 10) {
        i++;
    }

    for (int j = 0; j < 10; j++) {
        if (arr[j] % 2 == 0) {
            outFile << arr[j] << ' ';
        }
    }
    inFile.close();
    outFile.close();

    return 0;
}
