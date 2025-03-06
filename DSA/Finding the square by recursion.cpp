 #include<iostream>
using namespace std;
int power(int n,int p){
        int ans;

    if(p==0){
        return 1;
    }
    ans=n*power(n,p-1);
    return ans;
}

int main(){
   cout<<"The answeris given as "<<endl;
   cout<<power(5,2)<<endl;
    return 0;
}
