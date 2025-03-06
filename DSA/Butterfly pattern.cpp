#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value "<<endl;
    cin>>n;
    cout<<"The pyramid is given below"<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        for(int k=i;k<n;k++){
            cout<<" ";
        }
        for(int k=i;k<n;k++){
            cout<<" ";
        }
        for(int k=0;k<i;k++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<=n;i++){
        for(int k=i;k<n;k++){
            cout<<"*";
        }
        for(int k=0;k<i;k++){
            cout<<" ";
        }
        for(int k=0;k<i;k++){
            cout<<" ";
        }
        for(int k=i;k<n;k++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}