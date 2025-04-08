#include<iostream>
using namespace std;

void printname(int i, int n) {
    if(i > n) return;
    cout << "Aditya is Studying from Striver Sheet" << endl;
    printname(i + 1, n);
}

int main() {
    int n;
    cin >> n;
    printname(1, n);
    return 0;
}
