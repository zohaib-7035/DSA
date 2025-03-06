#include<iostream>
using namespace std;
int getbit(int x,int p){
    return ((x & (1<<p))!=0);
}
int setbit(int x,int p){
    return ( x | (1<<p) );
}
int clearbit(int x ,int p){
    return (x & ~(1<<p));
}
int update(int n,int pos,int i){
    n=(n & ~(1<<pos));
    return n | (i<<pos);
}
int main(){
    cout<<getbit(5,2)<<endl;
    cout<<setbit(5,1)<<endl;
    cout<<clearbit(5,2)<<endl;
    cout<<update(5,1,1);
    return 0;
}