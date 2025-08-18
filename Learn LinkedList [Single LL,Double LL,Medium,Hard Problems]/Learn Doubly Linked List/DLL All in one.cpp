#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void setupIO() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* Convertarrayto2DLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev = head;
    for (int i=1;i<arr.size();i++){
        Node* temp=new Node{arr[i],nullptr,prev};
        prev->next=temp;
        prev=temp;
    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<' ';
        head=head->next;
    }
    cout<<endl;
}

Node* deleteNode(Node* head){
    if(  head==NULL || head->next==NULL  ){
        return NULL;
    }
        Node* prev=head;
        head=head->next;
        head->prev=nullptr;
        prev->next=nullptr;
        delete prev;
        return head;
    }

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL ) return NULL;
     Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* temp=tail->prev;
    temp->next=nullptr;
    tail->prev=nullptr;

    delete tail;
    return head;
}

Node* deletekelement(Node* head,int k){
    if(head==NULL  ) return NULL;

     
    int cnt =0;
    Node* temp=head;
    while (temp!=NULL){
        
        if(cnt==k) break;
        cnt++;
        temp=temp->next;
        
    }
    if (temp == NULL) return head; 
    Node* back=temp->prev;
    Node* front=temp->next;

    if (back == NULL && front == NULL) {
        return NULL;
    }
    else if (back == NULL) {
        return deleteNode(head);
    }
    else if (front == NULL) {
        return deleteTail(head);
    }

    back->next = front;
    front->prev = back;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

Node* insertaNodeatHead(Node* head,int val){
    Node* NewNode=new Node{val,head,nullptr};
    head->prev=NewNode;

    return NewNode;
}

Node* insertBeforeTail(Node* head, int val) {
    if (head == NULL) return new Node(val); 

    if(head->next == NULL) {
        return insertaNodeatHead(head, val);
    }

    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }

    Node* back = tail->prev;
    Node* newNode = new Node(val, tail, back);
    back->next = newNode;
    tail->prev = newNode;
    return head;
}

Node* insertBeforeKthElement(Node* head, int k, int val) {
    if (k == 1) {
        return insertaNodeatHead(head, val);
    }

    Node* temp = head;
    int cnt = 0;
    while (temp != NULL) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }

    Node* back = temp->prev;   
    Node* newNode = new Node(val, temp, back);
    back->next = newNode;     
    temp->prev = newNode;     
    return head;
}


int main(){
 setupIO();

   vector<int>arr={12,5,4,8,10};
   Node* head=Convertarrayto2DLL(arr);
   print(head);

   head=deleteNode(head);
   cout<<"After Deleting Head-";
   print(head);

   head=deleteTail(head);
   cout<<"After Deleting Tail-";
   print(head);

   int k=1;
   head=deletekelement(head,k);
   cout<<"After Deleting "<<k<<"th Position-";
   print(head);

   int val=12;
   head=insertaNodeatHead(head,val);
   cout<<"After Inserting Node at head Head-";
   print(head);

   head=insertBeforeTail(head,val);
   cout<<"After Inserting Node at Tail-";
   print(head);

   int kk=2;
   head=insertBeforeKthElement(head,4,2);
   cout<<"Inserting Before "<<kk<<"element-";
   print(head);
    return 0;
}
