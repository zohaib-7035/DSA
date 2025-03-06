#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> a;
    a.push_back(8);
    a.push_back(7);
    a.push_front(6);
        a.push_front(5);

    for(auto i:a){
        cout<<i<<" "<<endl;
    }
    a.pop_back();
    a.pop_front();
    cout<<"After poping the deque "<<endl;
     for(auto i:a){
        cout<<i<<" "<<endl;
    }
    cout<<"The size of deque is "<<a.size()<<endl;
    return 0;
}