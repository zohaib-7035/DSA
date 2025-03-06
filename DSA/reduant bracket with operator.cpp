#include <iostream>
#include <stack>
using namespace std;

bool isvalid(string s) {
    int l = s.length();
    stack<char> st; // Use stack of char

    for (int i = 0; i < l; i++) {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            bool hasOperator = false;
            if (st.empty()) {
                return false; 
            }
           
           
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    hasOperator = true;
                }
                st.pop();
            }
            if (st.empty()) {
                return false; 
            }
            st.pop(); 
            if (!hasOperator) {
                return false; 
            }
        }
    }
    return st.empty();
}

int main() {
    string s = "(a+b)";
    cout << "The answer is " << (isvalid(s) ? "true" : "false") << endl;
    return 0;
}

