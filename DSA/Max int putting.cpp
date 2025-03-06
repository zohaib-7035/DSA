#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int c=-199999;
    for(int i=0;i<n;i++){
        if(arr[i]>c){
            c=arr[i];
        }
        else {
            arr[i]=c;
        }
    }
    cout<<"The answer is given below "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}