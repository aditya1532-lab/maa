#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to print original string followed by reversed string using stack
void printReversedString(const string& str) {
    // Print the original string
    cout << "Original string: " << str << endl;

    // Create a stack to store characters
    stack<char> s;

    // Push all characters of the string onto the stack
    for (char ch : str) {
        s.push(ch);
    }

    // Print the reversed string by popping characters from the stack
    cout << "Reversed string: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main() {
    // Example input string
    string str;
    cout << "Enter a string: ";
    getline(cin, str);  // Read the entire line of input

    // Call the function to print the original and reversed strings
    printReversedString(str);

    return 0;