#include <iostream>
#include <list>
#include<stack>
#include<queue>
using namespace std;
int main(){
//List
cout<<"List"<<endl;
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl<<"Size of the list-->"<<l.size()<<endl;
//Stack
cout<<endl;
cout<<"Stack(Lifo-Last in first out)"<<endl;
    stack<string> s;
    s.push("Striver");
    s.push("Dsa");
    s.push("A2Z Sheet");
    cout<<"Top Element of the Stack-->"<<s.top()<<endl;
    cout<<"Size of Stack-->"<<s.size()<<endl;
    
//Queue
cout<<endl;
cout<<"Queue(Fifo-First in FIrst out)"<<endl;
    queue<string> q;
    q.push("Striver");
    q.push("Dsa");
    q.push("A2Z Sheet");
    cout<<"First Element of the Stack-->"<<q.front()<<endl;
    cout<<"Size of the Stack-->"<<q.size()<<endl;
    q.pop();
    cout<<"Fitst Element after pop-->"<<q.front()<<endl;
    cout<<"Size of the Stack-->"<<q.size()<<endl;


    
    return 0;
}
