#include<iostream>
using namespace std;

void setupIO() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
/*int cnt = 0;

void print() {
    if (cnt == 9) return;     // base case

    cout << cnt << endl;      // print current cnt
    cnt++;                    // increment cnt
    print();                  // recursive call
}

int main() {
    setupIO();
    print();  // call recursive function
    return 0;
}*/

//Basic Recursion Problems
//Print name 5 times
/*int num=0;

void name(){
    if(num==5)return;
    cout<<"Aditya"<<endl;
    num++;
    name();
}
int main(){
    setupIO();
    cout<<"Printing Name 5 TImes-"<<endl;
    name();
    return 0;
}*/
//Now printing number 1 to n
/*int num=1;
void printnum(int n){

    if(num>n)return;
    cout<<num<<endl;
    num++;
  
    printnum(n);
    
}
int main(){
    setupIO();
    int n;
    cout<<"printing number 1 to n(so give input n)"<<endl;
    cin>>n;
    printnum(n);
    return 0;
}*/
int num=0;
void printnum(int n){

    if(num>=n)return;
    cout<<n-num<<endl;
    num++;
  
    printnum(n);
    
}
int main(){
    setupIO();
    int n;
    cout<<"printing number n to 1"<<endl;
    cin>>n;
    printnum(n);
    return 0;
}
