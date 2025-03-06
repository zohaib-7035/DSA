#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number to check"<<endl;
    cin>>n;
    bool a=true;
    if (n <= 1) {
        cout << "It is not a prime number" << endl;
        return 0;
    }

    for(int i=2; i<n/2;i++){
        if(n%i==0){
            a=false;
            break;
    }
    }
    if(a){
        cout<<"It is prime number "<<endl;
    }
    else
    {
    cout<<"It is not the prime number"<<endl;
    }
    return 0;
}