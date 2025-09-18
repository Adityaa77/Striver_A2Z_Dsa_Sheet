/*
 * Problem: Next Greater Element II
 * Platform: LeetCode
 * Description:
 *   Given a circular array nums, for each element return the next greater
 *   element. The next greater element of a number x is the first greater
 *   number to its right in traversal order (wrapping around). If it doesn't
 *   exist, return -1 for that position.
 *
 * Approaches:
 *   1. Brute Force
 *   2. Optimized (Monotonic Stack, simulate circular with 2*n traversal)
 */

/* ---------------- BRUTE FORCE ----------------
 * Time Complexity: O(n^2)
 *   - For each index, check up to n-1 elements (wrapping around).
 * Space Complexity: O(n)
 *   - Result vector only.
 */
class SolutionBrute {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);

        for (int i = 0; i < n; i++) {
            for (int k = 1; k < n; k++) {
                int j = (i + k) % n;
                if (nums[j] > nums[i]) {
                    res[i] = nums[j];
                    break;
                }
            }
        }
        return res;
    }
};

/* ---------------- OPTIMIZED ----------------
 * Time Complexity: O(n)
 *   - Each element is pushed and popped at most once from the stack.
 * Space Complexity: O(n)
 *   - Result vector + stack (worst case holds all elements).
 *
 * Notes:
 *   - Iterate i from 2*n - 1 down to 0.
 *   - Access element as nums[i % n].
 *   - Only record result when i < n.
 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; // monotonic decreasing stack

        for (int i = 2 * n - 1; i >= 0; i--) {
            int cur = nums[i % n];
            while (!st.empty() && st.top() <= cur) {
                st.pop();
            }
            if (i < n) {
                res[i] = st.empty() ? -1 : st.top();
            }
            st.push(cur);
        }
        return res;
    }
};
