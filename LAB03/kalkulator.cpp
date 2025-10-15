#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

bool isNumer(const string& str) {
    return !str.empty() && str.find_first_not_of("0123456789.") == string::npos;
}

bool isOperator(const string& str) {
    return str == "+" || str == "-" || str == "*" || str == "/";
}

int main() {
    stack<double> stack;

    string oper;
    getline(cin, oper);   

    stringstream ss(oper);
    string token;

    while (ss >> token) {
        if (isOperator(token)) {
            if (stack.size() < 2) {
                cerr << "Error: Not enough numbers for the specified operation" << endl;
                return 1;
            }
            
            double num2 = stack.top();
            stack.pop();
            double num1 = stack.top();
            stack.pop();
            
            if (token == "+") {
                stack.push(num1 + num2);
            } else if (token == "-") {
                stack.push(num1 - num2);
            } else if (token == "*") {
                stack.push(num1 * num2);
            } else if (token == "/") {
                stack.push(num1 / num2);
            }

       } else {
            try {
                double num = stod(token);
                stack.push(num);
            } catch (const exception& e) {
                cerr << "Error: Invalid number '" << token << "'" << endl;
                return 1;
            }
        }
    }
    if (stack.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Result: " << stack.top() << endl;
    }
    return 0;
}
