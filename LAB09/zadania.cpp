#include <iostream> 
using namespace std;

/*
    Zadanie1:

Code:


struct Point {
    int x;
    int y;
};

int main() {
    Point point = {2, 5};

    cout << point.x << endl; 
    cout << point.y << endl;

    return 0;
}
*/

/*
    Zadanie2:

Code:


struct Rect {
    int a;
    int b;
};

int area(Rect rect) {
    return rect.a * rect.b;
}

int main() {
    Rect rect = {5, 5};

    cout << area(rect) << endl;
    return 0;
}
*/

/*
    Zadanie3:

Code:

struct Triangle {
    int a;  
    int b;  
    int c;  
};

void fun(Triangle one, Triangle* two) {
    two->a = one.a;
    two->b = one.b;
    two->c = one.c;
}

int main() {
    Triangle one = {5, 5, 5};
    Triangle two = {1, 1, 1};
    
    fun(one, &two);

    cout << two.a << endl;
    cout << two.b << endl;
    cout << two.c << endl;
    
    return 0;
}
*/
