#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of N "<<endl;
    cin>>n;
    cout<<"Enter the values of the array "<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool array[n];
    for(int i=0;i<n;i++){
        array[i]=false;
    }
    for(int i=0;i<n;i++){
        if(array[arr[i]]==false && arr[i]>=0){
            array[arr[i]]=true;
        }
    }
    for(int i=0;i<n;i++){
        if(array[i]==false){
            cout<<"The answer is : ";
            cout<<i<<endl;
            break;
        }
    }
        
    

    return 0;
}