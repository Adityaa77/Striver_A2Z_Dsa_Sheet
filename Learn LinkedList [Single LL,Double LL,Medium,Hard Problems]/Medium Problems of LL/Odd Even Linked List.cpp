/**
 * LeetCode 328. Odd Even Linked List
 * Problem Link: https://leetcode.com/problems/odd-even-linked-list/
 *
 * Statement:
 *   Given the head of a singly linked list, group all the nodes with odd indices together
 *   followed by the nodes with even indices, and return the reordered list.
 *
 * Example:
 *   Input:  head = [1,2,3,4,5]
 *   Output: [1,3,5,2,4]
 *
 * Approaches:
 *   1. Brute Force (extra space using vector)
 *   2. Optimal (rearrange pointers in place)
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
 🟠 Brute Force Approach (using extra space)
   - Traverse odd nodes first, then even nodes
   - Store values in vector, rewrite them into list
   - Time: O(n), Space: O(n)
-------------------------------------------------------------*/
class SolutionBrute {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        vector<int> arr;
        ListNode* temp = head;

        // Collect odd indexed nodes
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp) arr.push_back(temp->val); // if odd length

        // Collect even indexed nodes
        temp = head->next;
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp) arr.push_back(temp->val); // if even length

        // Rewrite list from arr
        temp = head;
        int i = 0;
        while (temp) {
            temp->val = arr[i++];
            temp = temp->next;
        }
        return head;
    }
};

/*------------------------------------------------------------
 🟢 Optimal Approach (Pointer Manipulation, In-Place)
   - Maintain two pointers: odd and even
   - Rearrange next pointers such that all odd nodes connect together,
     and then link to even list
   - Time: O(n), Space: O(1)
-------------------------------------------------------------*/
class SolutionOptimal {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even; // store starting point of even list

        while (odd->next && even->next) {
            odd->next = even->next;      // link odd to next odd
            odd = odd->next;             // move odd forward

            even->next = odd->next;      // link even to next even
            even = even->next;           // move even forward
        }

        // join odd list end to even list head
        odd->next = evenHead;
        return head;
    }
};
