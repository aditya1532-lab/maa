#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to normalize the string (remove spaces and punctuation, convert to lowercase)
string normalizeString(const string& str) {
    string normalized = "";
    for (char ch : str) {
        if (isalnum(ch)) {  // Only consider alphanumeric characters
            normalized += tolower(ch);  // Convert to lowercase and add to the normalized string
        }
    }
    return normalized;
}

// Function to check whether the given string is a palindrome or not
bool isPalindrome(const string& str) {
    // Normalize the input string
    string normalized = normalizeString(str);
    
    // Compare the normalized string with its reverse
    int start = 0;
    int end = normalized.length() - 1;
    
    while (start < end) {
        if (normalized[start] != normalized[end]) {
            return false;  // If characters do not match, it is not a palindrome
        }
        start++;
        end--;
    }
    return true;  // If all characters matched, it is a palindrome
}

int main() {
    // Input string from the user
    string input;
    cout << "Enter a string: ";
    getline(cin, input);  // Read the entire line
    
    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        cout << "The given string is a palindrome!" << endl;
    } else {
        cout << "The given string is not a palindrome!" << endl;
    }
    
    return 0;
}