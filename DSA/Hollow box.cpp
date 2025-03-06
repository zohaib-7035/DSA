#include<iostream>
using namespace std;
int main(){
    cout<<"Enter the lenght and the width"<<endl;
    int a;
    int b;
    cin >>a;
    cin>>b;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==1 || i==a || j==1 || j==b)
            cout<<"*";
            else 
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}