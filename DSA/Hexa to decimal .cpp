#include<iostream>
using namespace std;
int main(){
    string n;
    cout<<"Enter the value "<<endl;
    cin>>n;
    int ans=0;
    int x=1;
    int s=n.size();
    
    for(int i=s-1;i>=0;i--){
        if(n[i]>='0' && n[i]<='9'){
        ans+=x*(n[i]-'0');  // for this  '3' - '0' = 51 - 48 = 3
//'7' - '0' = 55 - 48 = 7
        }  
        else if(n[i]>='A'&& n[i]<='F') {
            ans+=x*((n[i]-'A')+10);
        }
                x*=16;
    }
    cout<<"The answer is given below as "<<ans<<endl;
    return 0;
}