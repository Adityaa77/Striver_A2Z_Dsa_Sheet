#include<iostream>
using namespace std;

void printnto1(int i, int n) {
    if(i > n) return;
    cout << n << " ";
    printnto1(i, n - 1);
}

int main() {
    int n;
    cin >> n;
    printnto1(1, n);
    return 0;
}
