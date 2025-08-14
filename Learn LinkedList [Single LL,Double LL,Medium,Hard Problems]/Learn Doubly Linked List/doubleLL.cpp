// 📁 Filename: Node.h
// 📌 Description: Definition of the Node class for a doubly linked list.
// 🧠 Purpose: Represents a node with `data`, `next`, and `prev` pointers.
// 🔗 Reusability: This file can be included in multiple linked list programs.



class Node {
public:
    int data;       // 💾 Value stored in the node
    Node* next;     // 👉 Pointer to the next node
    Node* prev;     // 👈 Pointer to the previous node

    // 🛠 Constructor: Initialize node data and pointers
    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};
