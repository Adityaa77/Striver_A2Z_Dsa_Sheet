/**
 * LeetCode 141. Linked List Cycle
 * Problem Link: https://leetcode.com/problems/linked-list-cycle/
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


#include <unordered_set>
using namespace std;

// Base ListNode definition in Base_ListNode.cpp

class Solution_Brute {
public:
    // Approach 1: Brute Force using hash set
    // Time: O(n), Space: O(n)
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visited;
        ListNode* temp = head;

        while (temp != NULL) {
            if (visited.find(temp) != visited.end()) {
                return true; // already visited
            }
            visited.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};

class Solution_Optimal {
public:
    // Approach 2: Floyd’s Cycle Detection (Tortoise & Hare)
    // Time: O(n), Space: O(1)
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // move by 1
            fast = fast->next->next;     // move by 2
            if (slow == fast) return true;
        }
        return false;
    }
};
