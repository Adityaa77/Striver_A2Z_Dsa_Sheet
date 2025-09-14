/*
 * Problem: Next Greater Element I
 * Platform: LeetCode
 * Description:
 *   Given two arrays nums1 and nums2 where nums1 is a subset of nums2,
 *   find the next greater element for each element of nums1 in nums2.
 *   If no greater element exists, return -1.
 *
 * Approaches:
 *   1. Brute Force
 *   2. Optimized (Monotonic Stack + HashMap)
 */

/* ---------------- BRUTE FORCE ----------------
 * Time Complexity: O(n1 * n2)
 *   - For each element in nums1, we scan nums2 to find its next greater.
 * Space Complexity: O(1)
 *   - No extra data structures used apart from result vector.
 */
class SolutionBrute {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (int num : nums1) {
            int nextGreater = -1;
            // Find num in nums2
            for (int i = 0; i < nums2.size(); i++) {
                if (nums2[i] == num) {
                    // Look to the right for next greater element
                    for (int j = i + 1; j < nums2.size(); j++) {
                        if (nums2[j] > num) {
                            nextGreater = nums2[j];
                            break;
                        }
                    }
                    break;
                }
            }
            res.push_back(nextGreater);
        }
        return res;
    }
};

/* ---------------- OPTIMIZED ----------------
 * Time Complexity: O(n2 + n1)
 *   - Each element in nums2 is pushed and popped at most once from the stack.
 *   - Lookup for nums1 is O(1) per element.
 * Space Complexity: O(n2)
 *   - HashMap to store next greater for each element.
 *   - Stack in worst case stores all elements of nums2.
 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next; // map value -> next greater element
        stack<int> s;                 // monotonic decreasing stack

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            // Remove elements smaller or equal to current
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }

            // If stack empty -> no greater element to right
            next[nums2[i]] = s.empty() ? -1 : s.top();

            // Push current element
            s.push(nums2[i]);
        }

        // Build result for nums1
        vector<int> res;
        for (int num : nums1) {
            res.push_back(next[num]);
        }
        return res;
    }
};
