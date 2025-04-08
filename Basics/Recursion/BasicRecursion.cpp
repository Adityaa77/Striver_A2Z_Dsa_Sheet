#include<iostream>
using namespace std;

void setupIO() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int cnt = 0;

void print() {
    if (cnt == 9) return;     // base case

    cout << cnt << endl;      // print current cnt
    cnt++;                    // increment cnt
    print();                  // recursive call
}

int main() {
    setupIO();
    print();  // call recursive function
    return 0;
}
