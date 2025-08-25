/**
 * LeetCode 2095. Delete the Middle Node of a Linked List
 * Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
 *
 * Statement:
 *   You are given the head of a linked list. Delete the middle node, and return the head.
 *   If the list has an even number of nodes, delete the second middle node.
 *
 * Example:
 *   Input:  head = [1,3,4,7,1,2,6]
 *   Output: [1,3,4,1,2,6]
 *
 * Approaches:
 *   1. Brute Force (count length, then delete middle)
 *   2. Optimal (two-pointer slow & fast)
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
   - Find middle index (len/2)
   - Traverse again to delete that node
   - Time: O(n), Space: O(1)
-------------------------------------------------------------*/
class SolutionBrute {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;

        // Step 1: Count nodes
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }

        // Step 2: Find middle index
        int mid = length / 2;

        // Step 3: Traverse again to (mid-1)th node
        temp = head;
        for (int i = 1; i < mid; i++) {
            temp = temp->next;
        }

        // Step 4: Delete middle node
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};

/*------------------------------------------------------------
 🟢 Optimal Approach (Two Pointers)
   - Use slow & fast pointers
   - Fast moves 2 steps, slow moves 1 step
   - When fast reaches end, slow is just before middle
   - Delete slow->next
   - Time: O(n), Space: O(1)
-------------------------------------------------------------*/
class SolutionOptimal {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        // Move until fast reaches end
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};
