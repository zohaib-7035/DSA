#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number that u want to process"<<endl;
    cin>>n;
char ans[50];
int j=0;
int r=0;
    while(n>0){
        r=n%16;
        if(r<10){
          ans[j++]=48+r;  
        }
    else {
        ans[j++]=55+r;
    }
    n=n/16;
    }
    for(int i=j-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    return 0;
}