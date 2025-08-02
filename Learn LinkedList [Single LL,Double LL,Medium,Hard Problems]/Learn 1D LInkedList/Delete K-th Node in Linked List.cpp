// ✅ Custom Function: Delete K-th Node in Linked List
// 📌 Description: Deletes the node at the K-th position (1-based index) from the linked list.
// 🧠 Input: Head pointer to the linked list, position K
// 🧠 Output: Updated head pointer after deletion

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

Node* Deletek(Node* head, int k) {
    // 🛑 Case 1: Empty list
    if (head == NULL) return NULL;

    // 🛑 Case 2: Deleting the first node
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // ⚙️ General case: Delete K-th node (K > 1)
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;

    while (temp != NULL) {
        cnt++;

        // 🎯 Found K-th node
        if (cnt == k) {
            prev->next = temp->next; // Skip the K-th node
            delete temp;
            break;
        }

        // ⏩ Move to next node
        prev = temp;
        temp = temp->next;
    }

    return head;
}
