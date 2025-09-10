// Problem: Implement Stack using Queues (LeetCode 225)
// Link: https://leetcode.com/problems/implement-stack-using-queues/
//
// Description:
//   Implement a last-in-first-out (LIFO) stack using only one or more queues.
//   The implemented stack should support the following operations:
//   - push(x)
//   - pop()
//   - top()
//   - empty()
//
// Approach used in this file:
//   - Single queue, make push expensive: after pushing new element to back,
//     rotate the queue so that the new element becomes the front. Then
//     pop() and top() simply use queue.front() (O(1)).
//   - Tradeoff: push -> O(n), pop/top -> O(1).
//
// Time / Space Complexity:
//   push: O(n)   (n = current number of elements)
//   pop:  O(1)
//   top:  O(1)
//   empty: O(1)
//   Extra space: O(n) for underlying queue storage
//
// Notes:
//   - This is a standard single-queue solution for the problem.
//   - Alternative: two-queue approach (different trade-off).
//

#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    // Push element x onto stack.
    // O(n) due to rotation to make x the front.
    void push(int x) {
        q.push(x);
        // rotate previous elements behind the new element
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack and returns that element.
    // O(1)
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    // Get the top element.
    // O(1)
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    // O(1)
    bool empty() {
        return q.empty();
    }
};

/*
Example usage:
MyStack* obj = new MyStack();
obj->push(1);
obj->push(2);
int topVal = obj->top(); // 2
int popped = obj->pop(); // 2
bool isEmpty = obj->empty(); // false
*/
