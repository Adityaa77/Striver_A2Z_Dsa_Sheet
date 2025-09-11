
// 📌 Problem: Implement Stack using Linked List
// 🔗 Similar Problem: https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/
//
// 📝 Problem Statement:
//   Implement a Stack data structure using a linked list.
//   The stack should support the following operations:
//   - push(x): Insert element x onto the stack.
//   - pop(): Remove and return the top element of the stack. If stack is empty, return -1.
//
// 🧠 Approach (Linked List):
//   - Each node contains data and a pointer to the next node.
//   - The 'top' pointer points to the current top of the stack.
//   - push(x): Create a new node, make its next = top, update top = new node.
//   - pop(): If stack is empty, return -1. Otherwise, remove top node, update top to next node, return old data.
//
// ⏱ Time Complexity:
//   - push: O(1)
//   - pop: O(1)
//
// 💾 Space Complexity:
//   O(n) for storing n elements in linked nodes.
//

#include <bits/stdc++.h>
using namespace std;

// 🔹 StackNode definition
struct StackNode {
    int data;
    StackNode* next;
    StackNode(int x) : data(x), next(NULL) {}
};

// 🔹 Stack implementation using linked list
class MyStack {
private:
    StackNode* top; // pointer to the top of the stack
    int size;       // track current size (optional)

public:
    // Constructor
    MyStack() {
        top = NULL;
        size = 0;
    }

    // Push element onto stack
    void push(int x) {
        StackNode* temp = new StackNode(x); // create new node
        temp->next = top;                   // link new node to current top
        top = temp;                         // update top
        size++;
    }

    // Pop top element from stack and return it
    int pop() {
        if (top == NULL) return -1; // stack empty

        int res = top->data;        // store top value
        StackNode* temp = top;      // temp pointer to delete
        top = top->next;            // move top to next
        delete temp;                // free memory
        size--;
        return res;
    }

    // Utility: check if stack is empty
    bool empty() {
        return top == NULL;
    }

    // Utility: get current size
    int getSize() {
        return size;
    }
};

/*
Example usage:

int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.pop() << endl; // 30
    cout << st.pop() << endl; // 20
    cout << st.pop() << endl; // 10
    cout << st.pop() << endl; // -1 (empty)
    return 0;
}
*/
