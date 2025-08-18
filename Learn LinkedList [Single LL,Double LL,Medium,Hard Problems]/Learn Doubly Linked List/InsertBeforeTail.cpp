// 📁 Filename: InsertBeforeTail.cpp
// 📌 Problem: Insert a new node just before the tail of a doubly linked list.
// 🧠 Approach:
//    1. Handle empty list and single-node list.
//    2. Traverse to the tail.
//    3. Insert new node between `tail->prev` and `tail`.

#include "Node.h"

Node* insertBeforeTail(Node* head, int val) {
    if (head == NULL) return new Node(val); 

    if (head->next == NULL) {
        return insertaNodeatHead(head, val);
    }

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node* back = tail->prev;
    Node* newNode = new Node(val, tail, back);
    back->next = newNode;
    tail->prev = newNode;

    return head;
}
