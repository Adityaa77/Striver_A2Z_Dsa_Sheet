#include<iostream>
using namespace std;

void print1ton(int i, int n) {
    if(i > n) return;
    cout << i << " ";
    print1ton(i + 1, n);
}

int main() {
    int n;
    cin >> n;
    print1ton(1, n);
    return 0;
}
