#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the length of the array "<<endl;
    cin>>n;
    cout<<"Enter the values of the array"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The answer is given below "<<endl;
    for(int i=0;i<n;i++){
        int c=0;
        if(i==n-1){
         for(int j=i-1;j>=0;j--){
             if(arr[i]>arr[j]){
                 c++;
             }
         }   
         if(i==c){
             cout<<arr[i]<<endl;
         }
        }
       else if(arr[i]>arr[i+1] && i>0 && i!=n){
            for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j]){
                    c++;
                }
                else {
                    break;
                }
            }
            if(c==i){
                cout<<arr[i]<<endl;
            }
        }
    }
    return 0;
}