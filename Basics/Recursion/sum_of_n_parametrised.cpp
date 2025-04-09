#include <iostream>
using namespace std;

void sumofn(int i, int sum) {
    if (i < 1) {
        cout << sum;
        return;
    } 
    sumofn(i - 1, sum + i);
}

int main() {
    int i;
    cin >> i;
    cout << "Sum of the first n numbers (recursion parameterised way)" << endl;
    cout << "n - " << i << endl;
    sumofn(i, 0);
    return 0;
}
