#include<iostream>
using namespace std;
int main(){
    //It is only applicable when the array is sorted
    int sum=0;
    int c=0;
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int low=0;
    int high=n-1;
    int k=17;
    while(low<high){
    if(arr[low]+arr[high]==k){
        cout<<low<<" "<<high<<endl;
    }
    if(arr[low]+arr[high]<k){
        low++;
    }
    else{
        high++;
    }
        
    }
    return 0;
}