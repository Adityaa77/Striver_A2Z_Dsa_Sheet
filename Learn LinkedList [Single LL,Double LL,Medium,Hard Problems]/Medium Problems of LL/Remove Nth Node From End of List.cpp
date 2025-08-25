/**
 * LeetCode 19. Remove Nth Node From End of List
 * Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Statement:
 *   Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *
 * Example:
 *   Input:  head = [1,2,3,4,5], n = 2
 *   Output: [1,2,3,5]
 *
 * Approaches:
 *   1. Brute Force (count length, then remove node)
 *   2. Optimal (two-pointer fast & slow)
 *
 * Complexity:
 *   Brute Force → Time: O(n), Space: O(1)
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
   - Count total length of list
   - Find (len - n)th node from start
   - Delete its next node
   - Time: O(n), Space: O(1)
-------------------------------------------------------------*/
class SolutionBrute {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        int length = 0;
        ListNode* temp = head;

        // Step 1: Count total nodes
        while (temp) {
            length++;
            temp = temp->next;
        }

        // Step 2: If head needs to be removed
        if (n == length) {
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }

        // Step 3: Move to (length-n-1)th node
        temp = head;
        for (int i = 1; i < length - n; i++) {
            temp = temp->next;
        }

        // Step 4: Delete target node
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};

/*------------------------------------------------------------
 🟢 Optimal Approach (Two Pointers)
   - Move fast pointer `n` steps ahead
   - Move both fast & slow until fast reaches end
   - Slow will be before node to delete
   - Time: O(n), Space: O(1)
-------------------------------------------------------------*/
class SolutionOptimal {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast reached NULL, delete head
        if (fast == NULL) {
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }

        // Move both pointers
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node from end
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};
