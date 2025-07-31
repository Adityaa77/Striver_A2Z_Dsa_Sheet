// ✅ GFG Problem: Print Linked List Elements
// 🔗 https://www.geeksforgeeks.org/problems/print-linked-list-elements/1

/*
    Structure of Node:

    struct Node {
        int data;
        struct Node* next;

        Node(int x) {
            data = x;
            next = nullptr;
        }
    };
*/

class Solution {
  public:
    // ✅ Function to print elements of a linked list
    // Input: head node of the linked list
    // Output: prints data of each node in a single line
    void printList(Node *head) {
        Node* temp = head;

        // Traverse until the end of the list
        while (temp) {
            cout << temp->data << " ";  // Print current node's data
            temp = temp->next;          // Move to next node
        }
    }
};
