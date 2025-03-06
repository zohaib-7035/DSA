#include <iostream>
#include <stack>
#include<cmath>
using namespace std;
int postfixexp(string s){
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else {
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            switch(s[i]){
                case '+':
                   st.push(op2+op1);
                   break;
                   case '-':
                   st.push(op2-op1);
                   break;
                   case '*':
                   st.push(op2*op1);
                   break;
                   case '/':
                   st.push(op2/op1);
                   break;
                   default:
                   cout<<"error in the data "<<endl;
                   return -1;
            }
        }
    }
    return st.top();
}
int main(){
    string st="46+2/5*7+";
    int a=postfixexp(st);
    cout<<"The answer is given as "<<a<<endl;
    return 0;
}

