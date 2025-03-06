#include<iostream>
using namespace std;
void swap(int &a,int &b){
    int temp=move(a);
    a=move(b);
    b=move(temp);
}
string printme(){
    return "I am printed";
}
int main(){
    int a=3;
    int b=4;
    swap(a,b);
    cout<<"The A is "<<a<<endl;
    cout<<"The B is "<<b<<endl;
    
    string s=printme();
    string && ss= printme();
    cout<<s<<endl;;
    cout<<ss<<endl<<endl;
    cout<<"<<<<<<<<<<<"<<endl<<endl;;
    
    string s2 = printme();
    cout<<s2<<endl;
    string ss2 = move(s2);
    cout<<">>>>>>>>>>>>>>"<<endl;
    cout <<"<<<=+=>>>"<< s2 << endl;  // s2 is now null as the move statment has perfomed its working 
    cout << ss2 << endl;
    
    
    
    return 0;
}
