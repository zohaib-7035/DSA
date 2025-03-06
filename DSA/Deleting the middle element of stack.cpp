#include<iostream>
#include<stack>
#include<vector>
using namespace std;
stack<int> solve(stack<int> &st,int s){
    int c=0;
                vector<int> v;

    for(int i=0;i<s;i++){
        if(c==s/2){
            st.pop();
            break;
        } 
        else{
        v.push_back(st.top());
        st.pop();
        c++;
        }
    }
   while(!v.empty()){
        st.push(v.back());
        v.pop_back();
    }
    
    
    return st;
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    int s=st.size();
    solve(st,s);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}