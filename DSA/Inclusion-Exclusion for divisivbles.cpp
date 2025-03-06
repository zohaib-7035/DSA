#include<iostream>
using namespace std;
//It is basically used to find the divisible int by the given int between a certain limit
int divisible(int n,int a,int b){
    int c1=n/a;
    int c2=n/b;
    int c3=n/(a*b);
    return c1+c2-c3;
    //as inclusion-exclusion principal is a+b-comon
}
int main(){
    cout<<divisible(40,5,7)<<endl;
    return 0;
}