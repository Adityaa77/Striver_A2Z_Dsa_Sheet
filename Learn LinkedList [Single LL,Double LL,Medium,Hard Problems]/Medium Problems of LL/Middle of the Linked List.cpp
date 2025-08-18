/*
 * Problem: Middle of the Linked List
 * Source: LeetCode (Problem #876)
 *
 * Description:
 * -------------
 * Given the head of a singly linked list, return the middle node of the linked list.
 * - If there are two middle nodes, return the second middle node.
 *
 * Example:
 * --------
 * Input:  [1,2,3,4,5]
 * Output: [3,4,5]
 *
 * Input:  [1,2,3,4,5,6]
 * Output: [4,5,6]
 *
 * Approaches:
 * ------------
 * 1. Brute Force Method:
 *    - Traverse the list once to count total nodes (N).
 *    - Traverse again to reach the (N/2)-th node.
 *    - Return that node.
 *    - Time: O(N) + O(N) = O(2N) ~ O(N)
 *    - Space: O(1)
 *
 * 2. Tortoise and Hare Method (Optimal):
 *    - Use two pointers: slow and fast.
 *    - Move slow by 1 step, fast by 2 steps.
 *    - When fast reaches the end, slow will be at the middle.
 *    - Time: O(N)
 *    - Space: O(1)
 *
 * Note:
 * -----
 * - Handles edge cases: empty list or single node.
 * - For even-length lists, slow pointer naturally lands on the second middle node.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // ✅ Optimal Solution (Tortoise & Hare Method)
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast by 2 and slow by 1
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // Middle node
    }

    // ✅ Brute Force Method
    ListNode* middleNodeBrute(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        // Step 1: Count the number of nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Step 2: Move to (count/2)-th node
        temp = head;
        int mid = count / 2;
        while (mid--) {
            temp = temp->next;
        }

        return temp; // Middle node
    }
};
