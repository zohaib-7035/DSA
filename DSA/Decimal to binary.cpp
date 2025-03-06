#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value "<<endl;
    cin>>n;
    int binary[32];
    int i=0;
    while(n>0){
        binary[i]=n%2;
        n=n/2;
        i++;
    }
    int s=sizeof(binary)/sizeof(binary[0]);
     for (int j = i - 1; j >= 0; j--) {
        cout << binary[j] << " ";
    }
    return 0;
}