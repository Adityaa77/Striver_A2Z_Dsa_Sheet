// Leetcode 88. Merge Sorted Array
// ✅ Approach: Brute Force (Extra Space)
// Time Complexity: O((m+n) * log(m+n))
// Space Complexity: O(m + n)
// We're creating a new array 'ans', pushing first m elements of nums1 and all of nums2,
// then sorting and assigning back to nums1.
// ⚠️ Not in-place. Acceptable in Leetcode but not optimal for interviews.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;

        // Push first m elements from nums1 (ignoring trailing 0s)
        for (int i = 0; i < m; i++) {
            ans.push_back(nums1[i]);
        }

        // Push all elements from nums2
        for (int i = 0; i < n; i++) {
            ans.push_back(nums2[i]);
        }

        // Sort the combined array
        sort(ans.begin(), ans.end());

        // Replace nums1 with the sorted result
        nums1 = ans;
    }
};


// ✅ Approach: Two Pointers from the End (Optimal)
// Time Complexity: O(m + n)
// Space Complexity: O(1)
// We fill nums1 from the back using two pointers — one at end of valid nums1 and one at end of nums2.
// This avoids extra space and keeps it in-place.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;         // pointer for nums1's last valid element
        int j = n - 1;         // pointer for nums2's last element
        int k = m + n - 1;     // pointer for the last position in nums1

        // Place the largest of nums1[i] and nums2[j] at the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy any remaining elements from nums2 (if any)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }

        // Remaining elements in nums1 are already in place (no need to copy i's part)
    }
};
