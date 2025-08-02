// ✅ Custom Function: Delete Tail Node of a Linked List
// 📌 Description: Deletes the last node (tail) of a singly linked list.
// ❗ Assumes a singly linked list with no dummy head node.
// 🧠 Input: Head pointer to the linked list
// 🧠 Output: New head pointer after tail deletion

/*
    Definition for singly-linked list node:

    class Node {
    public:
        int data;
        Node* next;
        Node(int data1, Node* next1 = nullptr) {
            data = data1;
            next = next1;
        }
    };
*/

Node* deleteTail(Node* head) {
    // 🛑 Case 1: Empty list or single-node list
    if (head == NULL || head->next == NULL)
        return NULL;

    // 🧭 Traverse to the second-last node
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // 🗑️ Delete the last node
    delete temp->next;
    temp->next = nullptr;

    return head;
}
