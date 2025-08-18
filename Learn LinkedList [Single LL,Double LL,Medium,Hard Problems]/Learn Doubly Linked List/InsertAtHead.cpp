// 📁 Filename: InsertAtHead.cpp
// 📌 Problem: Insert a new node at the head of a doubly linked list.
// 🧠 Approach:
//    1. Create a new node with value `val`.
//    2. Link it before the current head.
//    3. Update head pointer.

#include "Node.h"

Node* insertaNodeatHead(Node* head, int val) {
    Node* NewNode = new Node{val, head, nullptr};
    if (head != nullptr) {
        head->prev = NewNode;
    }
    return NewNode;
}
