#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

// Function for checking if token is a valid number
bool isNumber(const string& str) {
    try {
        size_t pos;
        stod(str, &pos);
        return pos == str.length();
    } catch (...) {
        return false;
    }
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
    stack<double> numbers;
    string oper;

    // Start of the main loop for inputs
    while (getline(cin, oper)) {
        stringstream ss(oper);
        string token;

        while (ss >> token) {
            // Exiting when the 'exit' command is invoked
            if (token == "exit") {
                return 0;
            }

            if (isOperator(token)) {
                if (numbers.size() < 2) {
                    cerr << "error: not enough numbers for the specified operation" << endl;
                    return 1;
                }

                // evaluating the anwser per operator used
                double num2 = numbers.top(); numbers.pop();
                double num1 = numbers.top(); numbers.pop();
                
                try {
                numbers.push(applyOperator(num1, num2, token));
                } catch (const exception& e) {
                    cerr << "error: " << e.what() << endl;
                    return 1;
                }

           // checking for a valid number before adding to stack
           } else if (isNumber(token)) {
                try {
                    numbers.push(stod(token));
                } catch (const out_of_range& e) {
                    cerr << "Error: Number out of range '" << token << "'" << endl;
                    return 1;
                }
           } else {
                cerr << "Error: Invalid input '" << token << "'" << endl;
                return 1;
           }
        }
        // Printing the result
        cout << (numbers.empty() ? "Stack is empty" : "Result: " + to_string(numbers.top())) << endl;
    }
    return 0;
}
