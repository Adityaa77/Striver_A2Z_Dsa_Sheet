// 📁 Filename: DeleteHead.cpp
// 📌 Problem: Delete the head node of a doubly linked list.
// 🧠 Approach:
//    1. If empty or single node → return NULL.
//    2. Move head to the next node.
//    3. Update `prev` pointer to NULL.
//    4. Free memory of the old head.

#include "Node.h"

Node* deleteNode(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    Node* prev = head;
    head = head->next;
    head->prev = nullptr;

    prev->next = nullptr;
    delete prev;

    return head;
}
