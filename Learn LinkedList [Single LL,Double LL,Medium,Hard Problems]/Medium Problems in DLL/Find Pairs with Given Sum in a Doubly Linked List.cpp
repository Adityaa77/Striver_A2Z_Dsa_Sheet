/*
    Problem: Find Pairs with Given Sum in a Doubly Linked List
    -----------------------------------------------------------
    Given a sorted doubly linked list of distinct nodes and a target value,
    return all pairs of nodes whose sum equals the target.

    Example:
    Input:  DLL = 1 <-> 2 <-> 3 <-> 4 <-> 9, target = 5
    Output: (1,4), (2,3)

    Explanation:
    - 1 + 4 = 5
    - 2 + 3 = 5

    Constraints:
    - 1 <= Number of nodes <= 10^5
    - -10^6 <= Node value <= 10^6
    - The list is sorted in ascending order
*/


/* Doubly linked list node class
class Node {
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};
*/


class Solution {
public:

    /*
        Brute Force Approach (O(n^2)):
        --------------------------------
        - For every node, traverse the rest of the list and check if any pair forms the target sum.
        - Collect all valid pairs.
        - Very inefficient for large n.

        Optimized Approach (O(n)):
        --------------------------
        - Since the list is sorted, use two pointers:
            * left pointer at head
            * right pointer at tail
        - While left < right:
            * If sum == target → store pair, move both pointers
            * If sum < target → move left forward
            * If sum > target → move right backward
    */

    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;
        if (head == NULL) return ans;

        // Step 1: Find the tail node
        Node* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }

        // Step 2: Initialize two pointers
        Node* left = head;
        Node* right = tail;

        // Step 3: Two-pointer approach
        while (left->data < right->data) {
            int sum = left->data + right->data;

            if (sum == target) {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        return ans;
    }
};


/*
    ✅ Time Complexity: O(n) 
       - Each node is visited at most once by left or right pointer
    ✅ Space Complexity: O(1)
       - Only pointers used (excluding output vector)
*/
