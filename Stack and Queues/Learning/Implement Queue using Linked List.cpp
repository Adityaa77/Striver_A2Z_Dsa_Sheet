
// 📌 Problem: Implement Queue using Linked List
// 🔗 Similar Problem: https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/
//
// 📝 Problem Statement:
//   Implement a Queue data structure using a linked list.
//   The queue should support the following operations:
//   - push(x): Insert element x at the rear of the queue.
//   - pop(): Remove and return the front element of the queue. If queue is empty, return -1.
//
// 🧠 Approach (Linked List):
//   - Each node contains data and a pointer to the next node.
//   - Maintain two pointers: 'front' (head of queue) and 'rear' (tail of queue).
//   - push(x): Create new node, link at 'rear', update 'rear'.
//   - pop(): If queue empty, return -1. Otherwise, remove 'front' node, update 'front'.
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

// 🔹 Node definition for queue
struct QueueNode {
    int data;
    QueueNode* next;
    QueueNode(int x) : data(x), next(NULL) {}
};

// 🔹 Queue implementation using linked list
class MyQueue {
private:
    QueueNode* front; // pointer to front of queue
    QueueNode* rear;  // pointer to rear of queue

public:
    // Constructor
    MyQueue() {
        front = rear = NULL;
    }

    // Function to push an element into the queue
    void push(int x) {
        QueueNode* temp = new QueueNode(x);

        // If queue is empty, new node is both front and rear
        if (rear == NULL) {
            front = rear = temp;
        }
        else {
            rear->next = temp; // link new node at rear
            rear = temp;       // update rear pointer
        }
    }

    // Function to pop front element from the queue
    int pop() {
        if (front == NULL) return -1; // empty queue

        QueueNode* temp = front;   // store old front
        int data = temp->data;     // extract data
        front = front->next;       // move front forward

        // If queue becomes empty
        if (front == NULL) {
            rear = NULL;
        }

        delete temp;               // free memory
        return data;
    }

    // Utility: check if queue is empty
    bool empty() {
        return front == NULL;
    }
};

/*
Example usage:

int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.pop() << endl; // 10
    cout << q.pop() << endl; // 20
    cout << q.pop() << endl; // 30
    cout << q.pop() << endl; // -1 (empty)
    return 0;
}
*/
