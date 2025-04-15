#include <bits/stdc++.h>
using namespace std;

int main(){
    setupIO();  // Custom input/output setup (your own function)

    string r;
    cin >> r;

    cout << "The String Given is -- " << r << endl;

    // Step 1: Precompute character frequencies using hashing
    int hash[26] = {0};  // For lowercase English letters 'a' to 'z'

    for(int i = 0; i < r.size(); i++){
        // Increase count for character by mapping to 0-25 using (r[i] - 'a')
        hash[r[i] - 'a']++;
    }

    // Step 2: Handle queries
    int q;
    cin >> q;
    cout << "Numbers of queries you asked for is - " << q << endl;

    while(q--){
        char c;
        cin >> c;
        // Print how many times character 'c' occurred in the string
        cout << "This is how many times " << c << " is in the string - " << hash[c - 'a'] << endl;
    }

    return 0;
}
