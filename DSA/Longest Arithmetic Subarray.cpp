#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the length "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the values "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pd=arr[1]-arr[0];
    int c=2;
    int ans=2;
    for(int i=0;i<n;i++){
        if(pd==(arr[i]-arr[i-1])){
            c++;
        }
        else {
            c=2;
            pd=arr[i]-arr[i-1];
        }
        ans=max(c,ans);
    }
    cout<<"The answer is given below "<<ans<<endl;
    return 0;
}