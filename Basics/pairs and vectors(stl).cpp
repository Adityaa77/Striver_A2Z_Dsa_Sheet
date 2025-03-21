#include <iostream>
#include <vector>
using namespace std;
//Pairs in c++(can also use arr[] to make more pairs)
void explainpair(){
    pair<int, int> p = {8,3};
    cout<<p.first;
}
//
int main() {
    setupIO();

    //checking if the first number gets printed from pair
    cout<<"ELement in first pair-";
    explainpair();

    //vectors 
    vector<int> v;
    cout<<endl<<"size-"<<v.capacity();
    v.push_back(1);
    cout<<endl<<"assigned size-"<<v.capacity();
    v.push_back(2);
    cout<<endl<<"assigned size-"<<v.capacity();
    v.push_back(9);
    cout<<endl<<"assigned size-"<<v.capacity();
    cout<<endl<<"Actual size-"<<v.size();
    cout<<endl<<"Front Element-"<<v.front();
    cout<<endl<<"Back Element-"<<v.back();
 
 
return 0;
}
