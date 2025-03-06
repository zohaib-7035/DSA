#include<iostream>
using namespace std;
int main(){
    int sum=0;
    int c=0;
    int arr[4]={1,2,3,4};
    for(int i=0;i<4;i++){
        for(int j=i;j<4;j++){
            sum=0;
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<" ";
                sum+=arr[k];
            }
          c=max(sum,c);
          
            cout<<endl;
        }
    }
    cout<<"The Maximum sum is given as "<<c<<endl;
    return 0;
}