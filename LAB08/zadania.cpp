#include <iostream>
using namespace std;


int main() {
    int x;
    int *ptr = &x;

    cin >> *ptr;
    
    cout << ptr << endl << *ptr << endl;
    
    return 0;
}
