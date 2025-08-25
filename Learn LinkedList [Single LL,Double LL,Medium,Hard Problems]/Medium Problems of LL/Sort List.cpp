/**
 * LeetCode 148. Sort List
 * Problem Link: https://leetcode.com/problems/sort-list/
 *
 * Statement:
 *   Given the head of a linked list, return the list after sorting it in ascending order.
 *
 * Example:
 *   Input:  head = [4,2,1,3]
 *   Output: [1,2,3,4]
 *
 * Approaches:
 *   1. Brute Force (store values in array, sort, then put back)
 *   2. Optimal (Merge Sort on Linked List) <-- TODO
 *
 * Complexity:
 *   Brute Force → Time: O(n log n), Space: O(n)
 *   Optimal     → Time: O(n log n), Space: O(1)
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
   - Copy all values into a vector
   - Sort vector
   - Copy values back into linked list
   - Time: O(n log n), Space: O(n)
-------------------------------------------------------------*/
class SolutionBrute {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;

        // Step 1: Copy values
        vector<int> arr;
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Sort
        sort(arr.begin(), arr.end());

        // Step 3: Put back values
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};

/*------------------------------------------------------------
 🟢 Optimal Approach (Merge Sort on Linked List)
   - Find middle node using slow/fast
   - Recursively sort left and right halves
   - Merge two sorted lists
   - Time: O(n log n), Space: O(1)
-------------------------------------------------------------*/
class SolutionOptimal {
public:
    ListNode* sortList(ListNode* head) {
        // TODO: Implement Merge Sort on Linked List
        return head;
    }
};
