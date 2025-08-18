// 📁 Filename: InsertBeforeKthElement.cpp
// 📌 Problem: Insert a new node before the K-th element of a doubly linked list.
// 🧠 Approach:
//    1. If K=1 → insert at head.
//    2. Traverse until position K.
//    3. Insert new node between `temp->prev` and `temp`.

#include "Node.h"

Node* insertBeforeKthElement(Node* head, int k, int val) {
    if (k == 1) {
        return insertaNodeatHead(head, val);
    }

    Node* temp = head;
    int cnt = 0;

    while (temp != NULL) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }

    Node* back = temp->prev;   
    Node* newNode = new Node(val, temp, back);
    back->next = newNode;     
    temp->prev = newNode;     

    return head;
}
