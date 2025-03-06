#include<iostream>
using namespace std;
int main(){
    int sum=0;
    int c=0;
    int arr[]={-1,4,-6,7,-4};
    for(int i=0;i<5;i++){
       c+=arr[i];
       if(c<0){
           c=0;
       }
        sum=max(c,sum);
    }
    cout<<"The Maximum sum is given as "<<sum<<endl;
    return 0;
}