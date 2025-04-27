#include <bits/stdc++.h>
using namespace std;
// Problem: Find the Second Largest Element in an Array
// Link: https://takeuforward.org/plus/dsa/problems/second-largest-element

// Function to find the second largest element in the array
int secondLargestElement(vector<int>& nums) {
    int largest = nums[0];  // Initialize the largest element with the first element
    int slargest = -1;       // Initialize the second largest element as -1 (or any value that doesn't exist in the array)

    // Loop through the array to find the largest and second largest elements
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > largest) {  
            largest = nums[i];  // Update the largest element
        }
        if (nums[i] > slargest && nums[i] != largest) {
            slargest = nums[i];  // Update the second largest element, ensuring it's not equal to the largest element
        }
    }

    return slargest;  // Return the second largest element
}

int main() {
    int n; 
    cin >> n;  // Input the size of the array

    vector<int> nums(n);  // Declare a vector to hold the array elements
    for (int i = 0; i < n; i++) {
        cin >> nums[i];  // Input each element of the array
    }

    cout << secondLargestElement(nums) << endl;  // Output the second largest element

    return 0;
}

/*
⏳ Time Complexity:
- O(N), where N is the size of the array.
- We iterate through the array once, performing constant-time operations for each element.

🛢️ Space Complexity:
- O(1)
- We only use a constant amount of extra space for the variables `largest` and `slargest`.
*/
