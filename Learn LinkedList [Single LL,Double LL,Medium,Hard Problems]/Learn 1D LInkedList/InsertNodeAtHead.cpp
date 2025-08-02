// 📁 Filename: InsertNodeAtHead.cpp
// 📌 Problem Statement: Implement a function to insert a node at the head of a singly linked list.
// 🔗 No specific online problem link — utility function from a custom linked list setup.

// 🧠 Approach:
// - Create a new node with the given value.
// - Point its `next` to the current head.
// - Return the new node as the new head.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// 🚀 Function: Insert a node at the head of the linked list
Node* InsertNodeathead(Node* head, int val) {
    return new Node(val, head);
}

// 🧪 Example Usage
int main() {
    vector<int> arr = {10, 20, 30};
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }

    // Inserting at head
    int val = 100;
    head = InsertNodeathead(head, val);

    // Printing the list after insertion
    Node* temp = head;
    cout << "List after inserting " << val << " at head: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
