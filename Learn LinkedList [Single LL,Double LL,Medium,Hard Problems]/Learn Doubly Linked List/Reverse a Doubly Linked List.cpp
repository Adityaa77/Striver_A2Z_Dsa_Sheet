/*
 * Problem: Reverse a Doubly Linked List
 * Source: GeeksforGeeks (GFG)
 * 
 * Description:
 * -------------
 * Given the head of a doubly linked list, the task is to reverse it in place
 * and return the new head of the reversed list.
 *
 * Example:
 * --------
 * Input:  1 <-> 2 <-> 3 <-> 4
 * Output: 4 <-> 3 <-> 2 <-> 1
 *
 * Approach:
 * ----------
 * - Traverse the list node by node.
 * - For each node:
 *      1. Save `prev` (backup).
 *      2. Swap `prev` and `next`.
 *      3. Move `current` forward using the updated `prev`.
 * - At the end, `preve->prev` will point to the new head.
 *
 * Time Complexity:  O(N), where N = number of nodes.
 * Space Complexity: O(1), in-place reversal.
 *
 * Notes:
 * -------
 * - Handles edge cases: empty list (NULL) or single node.
 * - `preve` stores the previous pointer while swapping.
 * - `return preve->prev;` gives the new head after traversal.
 */

/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // Base case: empty or single node
        }

        DLLNode* preve = nullptr;   // Temporary backup pointer
        DLLNode* current = head;    // Start from head
        
        while (current != NULL) {
            // Backup current->prev
            preve = current->prev;

            // Swap prev and next pointers
            current->prev = current->next;
            current->next = preve;

            // Move to the "next" node (which is prev after swap)
            current = current->prev;
        }

        // At the end, preve points to the previous of the last node.
        // So preve->prev is the new head.
        return preve->prev;
    }
};
