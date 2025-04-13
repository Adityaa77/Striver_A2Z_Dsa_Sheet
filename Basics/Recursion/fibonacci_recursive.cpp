#include <iostream>
using namespace std;

// Function to return nth Fibonacci number using recursion
// Base Case: if n is 0 or 1, return n directly
// Recursive Case: f(n) = f(n-1) + f(n-2)
int fibonacci(int n){
    if (n <= 1) return n;

    int last = fibonacci(n - 1);     // f(n-1)
    int slast = fibonacci(n - 2);    // f(n-2)
    return last + slast;
}

int main(){
    int n;
    cin >> n;

    cout << "The value of n -- " << n << endl;
    cout << "The Fibonacci for n is -- " << fibonacci(n);

    return 0;
}
