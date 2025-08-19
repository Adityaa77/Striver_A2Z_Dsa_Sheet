
/**
 * LeetCode 206. Reverse Linked List
 * Problem Link: https://leetcode.com/problems/reverse-linked-list/
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


#include <stack>
using namespace std;

// Base ListNode definition in Base_ListNode.cpp

class Solution_Brute {
public:
    // Approach 1: Brute Force using stack
    // Time: O(n), Space: O(n)
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;

        stack<int> st;
        ListNode* temp = head;

        // Push values into stack
        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Reassign values from stack
        temp = head;
        while (temp != NULL) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};

class Solution_Optimal {
public:
    // Approach 2: Iterative 3-pointer method
    // Time: O(n), Space: O(1)
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* front = temp->next; // store next node
            temp->next = prev;            // reverse link
            prev = temp;                  // move prev forward
            temp = front;                 // move temp forward
        }
        return prev; // new head after reversal
    }
};
