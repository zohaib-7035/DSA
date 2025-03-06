#include<iostream>
using namespace std;

int main(){
    
    int n;
    cout<<"The length of the array "<<endl;
    cin>>n;
        int array[n];
    cout<<"Enter the value of the array "<<endl;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    for(int i=0;i<n-1;i++){//as the in this type of sorting loop run till n-1
    for(int j=0;j<n-i;j++){
        if(array[j]>array[j+1]){
            swap(array[j],array[j+1]);
        }
    }
    }
        cout<<"The answer is given below "<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<endl;
    }
    return 0;
}