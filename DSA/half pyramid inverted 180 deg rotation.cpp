#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"Enter the number"<<endl;
    cin>>a;
   for(int i=a-1;i>0;i--){
       for(int j=i;j>0;j--){
           cout<<" ";
           
       }
       for(int k=i;k<a;k++){
           cout<<"*";
       }
       cout<<endl;
   }
   
    
    return 0;
}