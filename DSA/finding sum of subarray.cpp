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
    int sum;
    cout<<"Enter the sum "<<endl;
    cin>>sum;
    for(int i=0;i<n;i++){
        int curr=0;
        for(int j=i;j<n;j++){
            curr+=arr[j];
          if(curr==sum){
              cout<<"The answer is "<<i<<" "<<j<<endl;
              
          }  
          else if(curr>sum){
              break;
          }
        }
    }
   
        
    

    return 0;
}