#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;

int main(){
   
    cout<<"Priority Queue"<<endl;
//priority queue 
   //max heap
   priority_queue<int>max;
   //min heap
   priority_queue<int,vector<int>,greater<int>>min;

   max.push(5);
   max.push(2);
   max.push(0);
   max.push(4);

   int n=max.size();
   cout<<"Size of max-->"<<n<<endl;
  
   for (int i=0;i<n;i++){
    cout<<max.top()<<" ";
    max.pop();
   }
   
   min.push(5);
   min.push(2);
   min.push(0);
   min.push(4);
   
   int mn=min.size();
   cout<<endl<<"Size of min-->"<<mn<<endl;
  
   for (int i=0;i<mn;i++){
    cout<<min.top()<<" ";
    min.pop();
   }

//set
cout<<endl<<"Set";
   set<int> s;

   s.insert(1);
   s.insert(2);
   s.insert(3);
   s.insert(4);

   cout<<endl<<"Size of the set-->"<<s.size()<<endl;
   for(int i:s){
    cout<<i<<" ";
   }
//s.erase used to erase element
//now to check if a number is present in the set
   cout<<endl<<"Is the number 5 present in set??"<<endl;
   int si=s.count(5);
   if(si==0){
    cout<<"Number is not Present";
   }
   else{
    cout<<"The Number is Present" ;
   }
//map
//this is example of an ordered map
cout<<endl<<"Map"<<endl;
    map<int, string> m;
    m[1]="my";
    m[2]="name";
    m[4]="aditya";
//using insert
    m.insert ( {3,"is" });

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}
