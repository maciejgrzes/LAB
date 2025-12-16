#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string fileName;
    cin >> fileName;

    ifstream file(fileName);

    string fileContents;

    file >> fileContents;

    cout << fileContents << endl;

    return 0;
}
