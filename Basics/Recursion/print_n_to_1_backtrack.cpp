#include<iostream>
using namespace std;

void printbacktrack2(int i, int n) {
    if(i > n) return;
    printbacktrack2(i + 1, n);
    cout << i << " ";
}

int main() {
    int n;
    cin >> n;
    printbacktrack2(1, n);
    return 0;
}
