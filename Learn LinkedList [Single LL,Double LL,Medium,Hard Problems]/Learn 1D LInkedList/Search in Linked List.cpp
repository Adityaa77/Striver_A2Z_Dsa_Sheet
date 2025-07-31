// ✅ GFG Problem: Search in Linked List
// 🔗 https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1

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

class Solution {
  public:
    // ✅ Function to search a key in a linked list
    // Input: 
    //   n    → total number of nodes (not used in logic)
    //   head → head pointer of the linked list
    //   key  → value to search for
    // Output:
    //   true if key exists in the list, false otherwise
    bool searchKey(int n, Node* head, int key) {
        Node* temp = head;

        // Traverse through the linked list
        while (temp) {
            if (temp->data == key) {
                return true; // Key found
            }
            temp = temp->next;
        }

        return false; // Key not found
    }
};
