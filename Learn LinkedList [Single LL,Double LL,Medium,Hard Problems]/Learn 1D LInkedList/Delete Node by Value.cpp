// ✅ Custom Function: Delete Node by Value
// 📌 Description: Deletes the first node in the linked list whose data equals 'm'.
// 🧠 Input: Head pointer to the linked list, int m (value to delete)
// 🧠 Output: Head pointer after deletion

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

Node* Deletekelement(Node* head, int m) {
    // 🛑 Case 1: Empty list
    if (!head) return NULL;

    // 🧹 Case 2: Head node has value m
    if (head->data == m) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // 🔍 Traverse to find the node with data m
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == m) {
            if (prev) prev->next = temp->next; // 🔗 Skip the node
            delete temp;                        // 🗑️ Free memory
            break;                              // ❌ Only delete first occurrence
        }

        // ⏭️ Move to next node
        prev = temp;
        temp = temp->next;
    }

    return head;
}
