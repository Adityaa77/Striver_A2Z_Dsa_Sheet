// ✅ Custom Function: Insert Node at Given Position
// 📌 Description: Inserts a new node with given value `val` at the given 1-based position `pos`.
// 🧠 Input: Head pointer to the linked list, int val (value to insert), int pos (position to insert at)
// 🧠 Output: Head pointer after insertion
// 🗒️ Note: Code is untouched as per user's instruction — no changes to spacing, variable names, or logic.

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
