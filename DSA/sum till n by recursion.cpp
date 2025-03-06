 #include<iostream>
using namespace std;
int sum(int n){
    int s=0 ;
    if(n==0){
        return 0;
    }
    
         s=n+sum(n-1);
    return s;
}

int main(){
   cout<<"The Sum is given as "<<endl;
   cout<<sum(4)<<endl;
    return 0;
}
