/*
    Problem: Remove Duplicates from a Sorted Doubly Linked List
    -----------------------------------------------------------
    Given the head of a sorted doubly linked list, remove all duplicate nodes 
    such that only distinct numbers remain (i.e., keep one occurrence of each number).

    Example:
    Input:  1 <-> 1 <-> 2 <-> 3 <-> 3
    Output: 1 <-> 2 <-> 3

    Constraints:
    - 1 <= Number of nodes <= 10^5
    - The list is sorted in non-decreasing order
*/


/*
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
*/


class Solution {
public:
    /*
        Brute Force Approach (O(n^2)):
        --------------------------------
        - For each node, traverse forward and remove duplicates manually.
        - This requires nested traversal.

        Optimized Approach (O(n)):
        --------------------------
        - Since list is sorted, duplicates will always be adjacent.
        - Traverse once:
            * Compare current node with the next.
            * If equal, skip/delete duplicate nodes.
            * Otherwise, move forward.
    */

    Node* removeDuplicates(Node* head) {
        if (!head) return head;

        Node* temp = head;

        while (temp != NULL && temp->next != NULL) {
            Node* nextnode = temp->next;

            // Delete all consecutive duplicates
            while (nextnode != NULL && nextnode->data == temp->data) {
                Node* dup = nextnode;
                nextnode = nextnode->next;
                free(dup);  // ✅ delete duplicate node
            }

            // Reconnect temp with next distinct node
            temp->next = nextnode;
            if (nextnode != NULL) nextnode->prev = temp;

            // Move forward
            temp = temp->next;
        }

        return head;
    }
};


/*
    ✅ Time Complexity: O(n)
       (Each node is visited once)
    ✅ Space Complexity: O(1)
       (Only pointers used, no extra DS)
*/
