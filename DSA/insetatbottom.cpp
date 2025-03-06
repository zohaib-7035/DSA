#include<iostream>
#include <stack>
using namespace std;

stack<int> insertatbottom(stack<int> &st, int x){
    stack<int> s;
    while(!st.empty()){
        s.push(st.top());
        st.pop();
    }
    st.push(x);
    while(!s.empty()){
        st.push(s.top());
        s.pop();
    }
    
    return st;
    
}

int main() {
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    insertatbottom(s,0);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
