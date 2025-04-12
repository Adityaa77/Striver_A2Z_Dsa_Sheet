#include <iostream>
using namespace std;

// Function to check if the string is a palindrome using recursion
bool f(int i, string s) {
    // Base case: if index crosses half of the string, it's a palindrome
    if (i >= s.size() / 2) return true;

    // If mismatch found at any index, not a palindrome
    if (s[i] != s[s.size() - i - 1]) return false;

    // Recursive call with next index
    return f(i + 1, s);
}

int main() {
    string s;
    cin >> s;

    cout << "String is-- " << s << endl;

    // Check if the string is a palindrome
    if (f(0, s) == true) {
        cout << "is a palindrome";
    } else {
        cout << "not a palindrome";
    }

    return 0;
}
