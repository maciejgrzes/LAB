#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string fileName;
    cin >> fileName;

    ifstream file(fileName);

    if (!file) {
        cout << "No such file..." << endl;
        return 1;
    }

    string fileContents;
    file >> fileContents;

    cout << fileContents << endl;

    return 0;
}
