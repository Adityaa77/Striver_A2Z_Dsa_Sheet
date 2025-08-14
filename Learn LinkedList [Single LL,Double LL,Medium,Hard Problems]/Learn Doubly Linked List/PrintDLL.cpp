// 📁 Filename: PrintDLL.cpp
// 📌 Problem: Print elements of a doubly linked list in order.
// 🧠 Approach: Traverse from head until NULL, printing each data value.

#include "Node.h"
#include <iostream>
using namespace std;

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}
