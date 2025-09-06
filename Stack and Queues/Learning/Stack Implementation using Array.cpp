// 🚀 Stack Implementation using Array
// ----------------------------------------------
// 🔑 Key Notes:
// 1. Stack follows LIFO (Last In, First Out).
// 2. push(x): Insert element at the top. O(1)
// 3. pop(): Remove and return the top element. O(1)
// 4. If stack is empty, return -1 when popping.

// ------------------------------------------------
// 📌 Brute Force / Simple Approach: 
// Use a fixed-size array to simulate stack behavior.
// Maintain a variable 'i' to track the index of the top element.
// ------------------------------------------------

class MyStack {
    int oper[100];   // Array to hold elements
    int i = -1;      // Top pointer (index of stack top). -1 means stack is empty.

  public:
    // 👉 Push operation
    void push(int x) { 
        i++;              // Move top pointer up
        oper[i] = x;      // Place element at top
    }

    // 👉 Pop operation
    int pop() { 
        if (i == -1) return -1;  // If stack is empty, return -1

        int elem = oper[i];  // Save top element
        i--;                 // Move top pointer down (remove top logically)
        return elem;         // Return the popped element
    }
};

// ------------------------------------------------
// 📝 Example Dry Run:
//
// MyStack st;
// st.push(10);   // Stack: [10], top = 0
// st.push(20);   // Stack: [10, 20], top = 1
// st.push(30);   // Stack: [10, 20, 30], top = 2
//
// st.pop();      // Returns 30, stack: [10, 20], top = 1
// st.pop();      // Returns 20, stack: [10], top = 0
// st.pop();      // Returns 10, stack: [], top = -1
// st.pop();      // Returns -1 (stack empty)
//
// ------------------------------------------------
// ⏱️ Time Complexity:
// push() → O(1)
// pop()  → O(1)
//
// 💾 Space Complexity:
// O(N) for storing elements (here fixed at 100).
//
// ------------------------------------------------
// ✅ Further Optimizations:
// - Implement using dynamic array (vector) instead of fixed 100 size.
// - Implement using Linked List for unlimited size.
// - Can also use STL `stack<int>` in real-world scenarios.
// ------------------------------------------------
