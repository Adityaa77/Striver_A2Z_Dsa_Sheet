// 🚀 Queue Implementation using Array
// Problem: Implement a queue (FIFO) with push and pop operations.
// Language: C++
// Author: Aditya
// ------------------------------------------------
// 🔑 Key Notes:
// 1. Queue follows FIFO (First In, First Out).
// 2. push(x): Insert element at the rear. O(1)
// 3. pop(): Remove element from the front. O(1)
// 4. If queue is empty → return -1 when popping.

// ------------------------------------------------
// 📌 Approach: 
// Use a fixed-size array to simulate queue behavior.
// Maintain two pointers:
// - `front` → index of first element
// - `rear` → index where next element is inserted
// ------------------------------------------------

class MyQueue {
private:
    int arr[100005];   // Array to hold elements
    int front;         // Front pointer
    int rear;          // Rear pointer

public:
    // 👉 Constructor to initialize
    MyQueue() {
        front = 0;
        rear = 0;
    }

    // 👉 Push operation
    void push(int x) {
        if (rear < 100005) {   // If space available
            arr[rear] = x;     // Place element at rear
            rear++;            // Move rear forward
        }
    }

    // 👉 Pop operation
    int pop() {
        if (front == rear) {   // If queue is empty
            return -1;
        }
        else {
            int d = arr[front];  // Get front element
            front++;             // Move front forward

            // If queue becomes empty, reset pointers
            if (front == rear) {
                front = 0;
                rear = 0;
            }
            return d;            // Return removed element
        }
    }
};

// ------------------------------------------------
// 📝 Example Dry Run:
//
// MyQueue q;
// q.push(10);   // Queue: [10], front=0, rear=1
// q.push(20);   // Queue: [10,20], front=0, rear=2
// q.push(30);   // Queue: [10,20,30], front=0, rear=3
//
// q.pop();      // Returns 10, Queue: [20,30], front=1, rear=3
// q.pop();      // Returns 20, Queue: [30], front=2, rear=3
// q.pop();      // Returns 30
