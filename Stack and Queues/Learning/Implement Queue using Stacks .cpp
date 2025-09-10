
// 📌 Problem: Implement Queue using Stacks (LeetCode 232)
// 🔗 Link: https://leetcode.com/problems/implement-queue-using-stacks/
//
// 📝 Problem Statement:
//   Implement a first-in-first-out (FIFO) queue using only two stacks.
//   The implemented queue should support standard operations:
//   - push(x): Add element x to the back of queue.
//   - pop(): Remove element from the front of queue and return it.
//   - peek(): Get the front element.
//   - empty(): Return whether the queue is empty.
//
// 🧠 Approach (Two-Stack Method):
//   - Maintain two stacks: in_stk (inbox), out_stk (outbox).
//   - push(x): Always push into in_stk.
//   - peek(): If out_stk is empty, transfer all elements from in_stk to out_stk.
//             The oldest element ends up on top of out_stk. Return out_stk.top().
//   - pop(): First call peek() to ensure out_stk has the front element,
//            then pop from out_stk.
//   - empty(): Return true if both in_stk and out_stk are empty.
//
// ⏱ Time Complexity:
//   - push: O(1)
//   - pop: Amortized O(1), worst-case O(n)
//   - peek: Amortized O(1), worst-case O(n)
//   - empty: O(1)
//
// 💾 Space Complexity:
//   O(n) for storing n elements across two stacks.
//

#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> in_stk;
    stack<int> out_stk;

public:
    MyQueue() {}

    // Push element x to the back of queue.
    void push(int x) {
        in_stk.push(x);
    }

    // Removes the element from in front of queue and returns that element.
    int pop() {
        peek(); // ensure out_stk has the front element
        int val = out_stk.top();
        out_stk.pop();
        return val;
    }

    // Get the front element.
    int peek() {
        if (out_stk.empty()) {
            while (!in_stk.empty()) {
                out_stk.push(in_stk.top());
                in_stk.pop();
            }
        }
        return out_stk.top();
    }

    // Return whether the queue is empty.
    bool empty() {
        return in_stk.empty() && out_stk.empty();
    }
};

/*
Example usage:

MyQueue* obj = new MyQueue();
obj->push(1);
obj->push(2);
int front = obj->peek();  // returns 1
int popped = obj->pop();  // returns 1
bool isEmpty = obj->empty(); // false
*/
