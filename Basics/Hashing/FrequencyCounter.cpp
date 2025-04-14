#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    
    int num;
    cin >> num;

    int arr[n];
    cout << "The size of Array is: " << n << endl;

    // Taking input for array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Printing the array
    cout << "The array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Hash array to store frequency of numbers from 0 to 12
    int hash[13] = {0};
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    cout << "The number " << num << " appears this many times: ";
    cout << hash[num] << endl;

    return 0;
}
