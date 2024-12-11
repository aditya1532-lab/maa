#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Function to apply operator to operands
int applyOperator(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Function to convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;  // Add operand to postfix expression
        } else if (ch == '(') {
            operators.push(ch);  // Push '(' onto stack
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();  // Pop operator to postfix
                operators.pop();
            }
            operators.pop();  // Pop '(' from stack
        } else {  // Operator encountered
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();  // Pop operators with higher or equal precedence
                operators.pop();
            }
            operators.push(ch);  // Push the current operator onto the stack
        }
    }

    // Pop all remaining operators from the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> values;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            values.push(ch - '0');  // Push operand to stack (convert char to integer)
        } else {  // Operator encountered
            int val2 = values.top(); values.pop();  // Pop top two operands
            int val1 = values.top(); values.pop();
            int result = applyOperator(val1, val2, ch);  // Apply the operator
            values.push(result);  // Push result back to stack
        }
    }

    return values.top();  // Final result will be the last value in the stack
}

int main() {
    string infix;
    cout << "Enter infix expression (single character operands): ";
    getline(cin, infix);

    // Convert infix to postfix
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    // Evaluate postfix expression
    int result = evaluatePostfix(postfix);
    cout << "Result of evaluation: " << result << endl;

    return 0;
}