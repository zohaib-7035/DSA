#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value "<<endl;
    cin>>n;
    cout<<"The pyramid is given below"<<endl;
    int k=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++,k++){
            cout<<k;
        }
        cout<<endl;
    }
    return 0;
}