#include<iostream>
using namespace std;
int main(){
    cout<<"Enter the lenght and the width"<<endl;
    int a;
    int b;
    cin >>a;
    cin>>b;
   for (int i=a;i>=0;i--){
       for(int j=1;j<=i;j++){
           cout<<"*";
       }
       cout<<endl;
   }
    return 0;
}