#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value "<<endl;
    cin>>n;
    cout<<"The pyramid is given below"<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<i;
        }
        cout<<endl;
    }
    return 0;
}