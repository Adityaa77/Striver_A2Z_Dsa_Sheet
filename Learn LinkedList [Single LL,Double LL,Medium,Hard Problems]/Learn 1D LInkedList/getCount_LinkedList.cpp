// File: getCount_LinkedList.cpp
//Problem-https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list
// Description: Counts the number of nodes in a singly linked list.
//
// ----------------------------------------------------
// Node structure definition:
//
// class Node {
//   public:
//     int data;        // value stored in node
//     Node *next;      // pointer to next node
//
//     Node(int x) {    // constructor to initialize node
//         data = x;
//         next = NULL;
//     }
// };
//
// ----------------------------------------------------

class Solution {
  public:
    // Function to count number of nodes in a singly linked list.
    int getCount(Node* head) {
        int count = 0;              // Initialize counter
        Node* temp = head;          // Start traversal from head

        while (temp != nullptr) {   // Traverse until the end of the list
            count++;                // Increment count for each node
            temp = temp->next;      // Move to the next node
        }

        return count;               // Return the final count
    }
};
