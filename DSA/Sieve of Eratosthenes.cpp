#include<iostream>
using namespace std;
int main(){
    int prime[100]={0};
    int n;
    cout<<"Enter the limit "<<endl;
    cin>>n;
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=1;
            }
        }
    }
    cout<<"The prime no. are given below "<<endl;
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            cout<<i<<" ";
        }
    }
    return 0;
}