#include <iostream>
using namespace std;

// Function to calculate factorial of a number using recursion
int factorial(int n) {
    if (n == 0) return 1;  // Base case: 0! = 1
    return n * factorial(n - 1);
}

int main() {
    int n;
    cin >> n;
    
    cout << "Factorial of " << n << " is: ";
    cout << factorial(n) << endl;

    return 0;
}
