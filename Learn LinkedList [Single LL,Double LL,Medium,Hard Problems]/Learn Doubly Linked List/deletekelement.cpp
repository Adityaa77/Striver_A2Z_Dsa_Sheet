// 📁 Filename: DeleteKthElement.cpp
// 📌 Problem: Delete the K-th node (0-indexed) from a doubly linked list.
// 🧠 Approach:
//    1. Traverse to the K-th node.
//    2. Handle 3 cases: head, tail, or middle.
//    3. Update pointers and free memory.

#include "Node.h"

Node* deletekelement(Node* head, int k) {
    if (head == NULL) return NULL;

    int cnt = 0;
    Node* temp = head;

    while (temp != NULL) {
        if (cnt == k) break;
        cnt++;
        temp = temp->next;
    }

    if (temp == NULL) return head; 

    Node* back = temp->prev;
    Node* front = temp->next;

    if (back == NULL && front == NULL) {
        return NULL;
    }
    else if (back == NULL) {
        return deleteNode(head);  // delete head
    }
    else if (front == NULL) {
        return deleteTail(head);  // delete tail
    }

    back->next = front;
    front->prev = back;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;

    return head;
}
