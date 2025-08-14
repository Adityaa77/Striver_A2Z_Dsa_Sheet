// 📁 Filename: ConvertArrayTo2DLL.cpp
// 📌 Problem: Convert an array into a doubly linked list.
// 🧠 Approach:
//    1. Create the head node from the first element.
//    2. Iteratively create new nodes and connect them using `next` and `prev`.
// 📅 Author: Aditya

#include "Node.h"
#include <vector>
using namespace std;

Node* Convertarrayto2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]); // First node
    Node* prev = head;

    // 🔄 Loop through remaining elements
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}
