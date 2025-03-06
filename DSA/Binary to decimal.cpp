#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number "<<endl;
    cin>>n;
    int ans=0;
    int x=1;
    while(n>0){
        int y=n%10;
        ans+=x*y;
        x*=2;//to change for the octal we have to use 8 or further for other 
        n=n/10;
        
        
    }
    cout<<"The binary of the given number is given below "<<ans<<endl;
    
    return 0;
}