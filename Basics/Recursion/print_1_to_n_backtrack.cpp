#include<iostream>
using namespace std;

void printbacktrack1(int i) {
    if(i < 1) return;
    printbacktrack1(i - 1);
    cout << i << " ";
}

int main() {
    int n;
    cin >> n;
    printbacktrack1(n);
    return 0;
}
