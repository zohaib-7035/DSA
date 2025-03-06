#include <iostream>
#include <stack>
using namespace std;

int isvalid(string s){
    if(s.length()%2==1){
        return -1;
    }
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{'){
            st.push(s[i]);
        }
        else if(!st.empty() and st.top()=='{'){
            st.pop();
        }
        else {
            st.push('}');
        }
    }
    int a=0,b=0;
    while(!st.empty()){
        if(st.top()=='{'){
            a++;
        }
        else{
            b++;
        }
        st.pop();
        }
    return (a+1)/2 + (b+1)/2;
}

int main() {
    string s = "{{{{{{{{";
    cout << "The answer is " << isvalid(s)<< endl;
    return 0;
}

