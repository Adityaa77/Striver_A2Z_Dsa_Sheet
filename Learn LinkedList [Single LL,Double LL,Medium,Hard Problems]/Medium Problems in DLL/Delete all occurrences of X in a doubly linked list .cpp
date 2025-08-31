/*  
    Problem: Delete all occurrences of X in a doubly linked list  

    Node structure:  
    struct Node {  
        int data;  
        struct Node *next;  
        struct Node *prev;  
        Node(int x) {  
            data = x;  
            next = prev = NULL;  
        }  
    };  
*/

// ---------------- Brute Force ----------------
// Approach: Store all values except X in a vector, 
// then rebuild the DLL (not memory-efficient, but easy).
// Time: O(N)  |  Space: O(N)

class SolutionBrute {
public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        if (!head) return NULL;

        vector<int> arr;
        Node* temp = head;

        // Collect values except x
        while (temp) {
            if (temp->data != x) arr.push_back(temp->data);
            temp = temp->next;
        }

        // Rebuild DLL
        Node* newHead = NULL;
        Node* prev = NULL;
        for (int val : arr) {
            Node* newNode = new Node(val);
            if (!newHead) newHead = newNode;
            if (prev) {
                prev->next = newNode;
                newNode->prev = prev;
            }
            prev = newNode;
        }

        return newHead;
    }
};


// ---------------- Optimal Solution ----------------
// Approach: Traverse the DLL, delete nodes with value x in-place.
// Adjust prev and next pointers carefully.
// Time: O(N)  |  Space: O(1)

class SolutionOptimal {
public:
    void deleteAllOccurOfX(Node** head_ref, int x) {
        Node* temp = *head_ref;

        while (temp) {
            if (temp->data == x) {
                // If node to delete is head
                if (temp == *head_ref) {
                    *head_ref = temp->next;
                }

                Node* NextNode = temp->next;
                Node* PrevNode = temp->prev;

                if (NextNode) NextNode->prev = PrevNode;
                if (PrevNode) PrevNode->next = NextNode;

                free(temp);
                temp = NextNode;
            }
            else {
                temp = temp->next;
            }
        }
    }
};
