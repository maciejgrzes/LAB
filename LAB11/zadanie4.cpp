#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct personalData {
    string name;
    int age;
};

int main() {
    ofstream file("zadanie4.txt");

    if (!file) {
        cout << "No such file..." << endl;
        return 1;
    }

    personalData person1;
    personalData person2;
    string name;
    int age;
    cout << "person1 name: ";
    getline(cin, name);
    person1.name = name;

    cout << "person1 age: ";
    cin >> age;
    person1.age = age;
    cin.ignore();

    cout << "person2 name: ";
    getline(cin, name);
    person2.name = name;

    cout << "person2 age: ";
    cin >> age;
    person2.age = age;

    personalData array[2] = {person1, person2};

    file << "id;name;age;\n";

    for (int i = 0; i < 2; i++) {
        file << i << ';' << array[i].name << ';' << array[i].age << ";\n";
    }
    file.close();

    return 0;
}
