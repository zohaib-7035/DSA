#include<iostream>
using namespace std;
int factorial(int n){
    int fact ;
    if(n==0){
        return 1;
    }
    
         fact=n*factorial(n-1);
    return fact;
}

int main(){
   cout<<"The factorial is given as "<<endl;
   cout<<factorial(5)<<endl;
    return 0;
}