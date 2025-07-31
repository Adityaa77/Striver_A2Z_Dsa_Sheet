// ✅ GFG Problem: Delete Head of Linked List
// 🔗 https://www.geeksforgeeks.org/problems/delete-head-of-linked-list/1

/*
    Structure of Node:

    struct Node {
        int data;
        Node* next;
        Node(int x) {
            data = x;
            next = NULL;
        }
    };
*/

Node* deleteHead(Node* head) {
    // ✅ Function to delete the head node of a linked list
    // Input: 
    //   head → head pointer of the linked list
    // Output:
    //   returns the new head after deleting the first node

    if (head == NULL) return head; // Empty list check

    Node* temp = head;     // Store the current head
    head = head->next;     // Move head to the next node
    delete temp;           // Delete the old head

    return head;           // Return the new head
}
