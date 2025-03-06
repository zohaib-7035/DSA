#include<iostream>
using namespace std;
int Binarysearch(int array[],int n,int key){
    int s=0;
    int e=n;
    while(s<=e){
            int m=(s+e)/2;
        if(array[m]==key){
            return m;
        }
        else if(array[m]>key){
            e=m-1;
        }
        else {
            s=m+1;
        }
    }
            return -1;

}
int main(){
    
    int key,n;
    int array[n];
    cout<<"The length of the array "<<endl;
    cin>>n;
    cout<<"Enter the value of the array "<<endl;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<"Enter the key "<<endl;
    cin>>key;
    cout<<"The answer is  "<<Binarysearch(array,n,key)<<endl;
    return 0;
}