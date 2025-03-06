#include<iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number "<<endl;
    cin>>n;
    int originalnumber=n;
int sum=0;
while(n>0){
    int lastdigit=n%10;
    sum+=pow(lastdigit,3);
    n=n/10;
}
if(sum==originalnumber){
    cout<<"The number is the armstrong"<<endl;
}
else 
cout<<"The number is not the armstrong"<<endl;
    return 0;
}