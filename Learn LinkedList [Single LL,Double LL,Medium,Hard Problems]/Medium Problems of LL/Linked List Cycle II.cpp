/**
 * LeetCode 142. Linked List Cycle II
 * Problem Link: https://leetcode.com/problems/linked-list-cycle-ii/
 *
 * Approaches:
 *  1. Brute Force (using Hashing / Set)
 *  2. Optimal (Floyd's Cycle Detection - Tortoise and Hare)
 *
 * Example:
 *   Input: head = [3,2,0,-4], pos = 1
 *   Output: Node with value 2
 */

#include <bits/stdc++.h>
using namespace std;

// Base ListNode definition in Base_ListNode.cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*------------------------------------------------------------
 🟠 Brute Force Approach
   - Use unordered_set to store visited nodes
   - First repeated node = start of cycle
   - Time Complexity: O(n)
   - Space Complexity: O(n)
-------------------------------------------------------------*/
class SolutionBrute {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        ListNode* temp = head;
        while (temp != NULL) {
            // If we already saw this node => cycle starts here
            if (visited.find(temp) != visited.end()) {
                return temp;
            }
            visited.insert(temp);
            temp = temp->next;
        }
        return NULL; // No cycle
    }
};

/*------------------------------------------------------------
 🟢 Optimal Approach (Floyd's Tortoise & Hare)
   - Step 1: Detect cycle using slow & fast pointers
   - Step 2: Reset slow to head, move both one step at a time
   - Step 3: First meeting point = start of cycle
   - Time Complexity: O(n)
   - Space Complexity: O(1)
-------------------------------------------------------------*/
class SolutionOptimal {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Step 1: Detect if cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Cycle detected
                // Step 2: Reset slow to head
                slow = head;
                // Step 3: Move both one step until they meet
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Start of cycle
            }
        }
        return NULL; // No cycle
    }
};
