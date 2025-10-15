#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

bool isNumber(const string& str) {
    return !str.empty() && str.find_first_not_of("0123456789.") == string::npos;
}

bool isOperator(const string& str) {
    return str == "+" || str == "-" || str == "*" || str == "/";
}

double applyOperator(double a, double b, const string& op) {
    switch (op[0]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
        default: throw runtime_error("Invalid operator");
    }
}

int main() {
    stack<double> stack;
    string oper;

    while (getline(cin, oper)) {
        stringstream ss(oper);
        string token;

        while (ss >> token) {
            if (token == "exit") {
                return 0;
            }

            if (isOperator(token)) {
                if (stack.size() < 2) {
                    cerr << "Error: Not enough numbers for the specified operation" << endl;
                    return 1;
                }
                
                double num2 = stack.top(); stack.pop();
                double num1 = stack.top(); stack.pop();
                
                try {
                stack.push(applyOperator(num1, num2, token));
                } catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                    return 1;
                }

           } else if (isNumber(token)) {
               stack.push(stod(token));
           } else {
                cerr << "Error: Invalid input '" << token << "'" << endl;
                return 1;
           }
        }
        if (stack.empty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Result: " << stack.top() << endl;
        }
    }
    return 0;
}
