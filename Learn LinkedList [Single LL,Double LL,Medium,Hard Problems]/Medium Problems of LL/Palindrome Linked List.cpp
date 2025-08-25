/**
 * LeetCode 234. Palindrome Linked List
 * Problem Link: https://leetcode.com/problems/palindrome-linked-list/
 *
 * Statement:
 *   Given the head of a singly linked list, return true if it is a palindrome, or false otherwise.
 *
 * Example:
 *   Input:  head = [1,2,2,1]
 *   Output: true
 *
 * Approaches:
 *   1. Brute Force (store values in stack, then compare)
 *   2. Optimal (reverse second half & compare)  <-- TODO
 *
 * Complexity:
 *   Brute Force → Time: O(n), Space: O(n)
 *   Optimal     → Time: O(n), Space: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*------------------------------------------------------------
 🟠 Brute Force Approach
   - Push all values in a stack
   - Traverse again and check with stack top
   - If mismatch → false, else true
   - Time: O(n), Space: O(n)
-------------------------------------------------------------*/
class SolutionBrute {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        // Step 1: Push all nodes into stack
        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Step 2: Traverse again & compare
        temp = head;
        while (temp != NULL) {
            if (temp->val != st.top()) return false;
            temp = temp->next;
            st.pop();
        }

        return true;
    }
};

/*------------------------------------------------------------
 🟢 Optimal Approach (Two Pointers + Reverse Half)
   - Find middle using slow/fast
   - Reverse second half of LL
   - Compare first half & second half
   - Restore list (optional)
   - Time: O(n), Space: O(1)
-------------------------------------------------------------*/
class SolutionOptimal {
public:
    bool isPalindrome(ListNode* head) {
        // TODO: Implement Optimal Solution
        return false;
    }
};
