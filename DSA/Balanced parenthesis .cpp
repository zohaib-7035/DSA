#include<iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (!st.empty()) {
               
            char top = st.top();
            if ((s[i] == ')' && top == '(') ||
                (s[i] == ']' && top == '[') ||
                (s[i] == '}' && top == '{')) {
                st.pop();
            }
            else{
                return false;
            }
        }
        else {
            return false;
        }
    }
    }
    return st.empty();
}

int main() {
    string s = "[{()}]";
    //string s = "{[(}])";
    cout << "The function answer is: " << (isValid(s) ? "true" : "false") << endl;
    return 0;
}
