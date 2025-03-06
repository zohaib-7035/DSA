#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
for(auto i:s){
    cout<<i<<endl;
}
cout<<"2nd way to print is given below "<<endl;
for(auto i=s.begin();i!=s.end();i++){
    cout<<*i<<endl;
}

return 0;
}