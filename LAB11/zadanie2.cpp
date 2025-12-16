#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream file("zadanie2.txt");

    if (!file) {
        cout << "No such file..." << endl;
        return 1;
    }

    int arr[10] = {0};
    int i = 0;

    while (file >> arr[i] && i < 10) {
        i++;
    }

    file.close();

    for (int num : arr) {
        cout << num << ' ';
    } cout << endl;

    return 0;
}
