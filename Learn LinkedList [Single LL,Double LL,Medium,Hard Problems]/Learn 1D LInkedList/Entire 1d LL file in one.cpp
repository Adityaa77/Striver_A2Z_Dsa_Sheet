#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Node {
public:
   int data;
   Node *next;
   Node(int data1 ,Node* next1 = nullptr){
    data =data1;
    next=next1;
   }
};

Node* convertarr2ll(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }
    return head;
};

int LengthofLL(Node* head){
    int count=0;
    Node* temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}

int Checkifpresent(Node* head, int value){
    Node* temp=head;
    while(temp){
        if(temp->data==value)return 1;
        temp=temp->next;
    }
    return 0;
}

Node* Deletetail(Node* head){
    if (head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
     temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}

Node* Deletek(Node* head, int k) {
    if (head == NULL || k <= 0)
        return head;

    if (k == 1) {  // delete head
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 1;
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (cnt == k) {
            if (prev) prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    return head;
}


Node* Deletekelement(Node* head, int m) {
    if (!head) return NULL;
    if (head->data == m) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == m) {
            if (prev) prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* InsertNodeathead(Node* head,int val){
    return new Node(val,head);
}

Node* InsertNodeattail(Node* head,int val){
    if(head==NULL)return new Node(val);
     Node* temp=head;
     while(temp->next!=NULL){
     temp=temp->next;
    }
    Node* newNode=new Node(val);
    temp->next=newNode;
    return head;
}

Node* InsertPosition(Node* head,int val,int pos){
 if(pos==1){
    return new Node(val,head);
 }
 int cnt=0;
 Node* temp=head;
 while(temp!=NULL){
    cnt++;
    if(cnt==(pos-1)){
        Node* posi=new Node(val,temp->next);
        temp->next=posi;
        break;
    }
    temp=temp->next;
 }
 return head;
}

int main(){

    //to get the node of the pointer
    vector<int> arr={222,4,5,7}; 
    Node* y=new Node(arr[0],nullptr);
    cout<<y->data<<endl;


    //head of the arr
    Node* head=convertarr2ll(arr);
    cout<<"the Head of the arr is-"<<head->data;

    //traverse in the node 
    cout<<endl<<"Array is-";
    Node* temp=head;
    while(temp){
        cout<<temp->data;
        temp=temp->next;
    }

    //length of the node
    cout<<endl<<"Length is-"<<LengthofLL(head);

    //Check if Number is Present
    cout<<endl<<Checkifpresent(head,222)<<" (For this 1 is true and 0 is false)";

    //Delete the tail of the array
    head=Deletetail(head);
    cout<<endl<<"After deleting Tail-";
    // After: head = Deletetail(head);
    temp = head;
    while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
    }

    //Remove the k position element
    int k=0;
    head=Deletek(head , k);
    cout<<endl<<"After Deleting "<<k<<" Position-";
    temp = head;
    while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
    }

     //Remove the m  element
    int m=5;
    head=Deletekelement(head , m);
    cout<<endl<<"After Deleting Number "<<m<<" we have-";
    temp = head;
    while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
    }
    cout << endl;

    //Inserting Node at Head
    int val=100;
    head=InsertNodeathead(head,val);
    cout<<"After Inserting Number "<<val<<" at head we have-";
    temp = head;
    while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
    }
    cout << endl;

    //Inserting Node at the Tail
    head=InsertNodeattail(head,val);
    cout<<"After Inserting Number "<<val<<" at tail we have-";
    temp = head;
    while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
    }
    cout << endl;

    //Inserting Node at Position 
    int pos=3;
    head=InsertPosition(head,val,pos);
    cout<<"After Inserting Number "<<val<<" at "<<pos<<" we have-";
    temp = head;
    while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
    }
    cout << endl;

}
