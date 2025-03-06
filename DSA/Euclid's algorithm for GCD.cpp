#include<iostream>
using namespace std;

int GCD(int a,int b){
    int c=0;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main(){
    cout<<"The greatest comon factor is given as "<<endl;
    cout<<GCD(42,24)<<endl;
    return 0;
}