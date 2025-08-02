// ✅ Custom Function: Insert Node at Tail  
// 📌 Description: Inserts a new node with the given value at the end of the linked list.  
// 🧠 Input: Node* head (head of the linked list), int val (value to insert)  
// 🧠 Output: Node* (head pointer after insertion)

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

Node* InsertNodeattail(Node* head, int val) {
    // 🛑 Case 1: If the list is empty
    if (head == NULL) return new Node(val);

    // 🔁 Traverse to the last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // ➕ Create and insert the new node at the end
    Node* newNode = new Node(val);
    temp->next = newNode;

    return head;
}

// 🧪 Example Usage:
int val = 100;
head = InsertNodeattail(head, val);
cout << "After Inserting Number " << val << " at tail we have-";
temp = head;
while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
}
cout << endl;
