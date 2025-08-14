// 📁 Filename: DeleteTail.cpp
// 📌 Problem: Delete the last node of a doubly linked list.
// 🧠 Approach:
//    1. Traverse to the last node.
//    2. Disconnect it from the previous node.
//    3. Free memory of the last node.

#include "Node.h"

Node* deleteTail(Node* head) {
    if (head == NULL || head->next == NULL) return NULL;

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node* temp = tail->prev;
    temp->next = nullptr;
    tail->prev = nullptr;

    delete tail;
    return head;
}
