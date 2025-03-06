#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverse_stack(string s) {
    stack<string> st;
    
    for (int i = 0; i < s.length(); i++) {
        string word = "";
        while (s[i] != ' ' && i < s.length()) {
            word += s[i];
            i++;
        }
        st.push(word);
    }
    
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int prefix_evaluation(string s) {
    stack<int> st;
    int l = s.length();
    
    for (int i = l - 1; i >= 0; i--) {
        if (s[i] >= '0' && s[i] <= '9') {
            st.push(s[i] - '0');
        } else if (s[i] == ' ') {
            continue;
        } else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            switch (s[i]) {
                case '+':
                    st.push(a + b);
                    break; 
                case '-':
                    st.push(a - b);
                    break;
                case '/':
                    st.push(a / b);
                    break;
                case '*':
                    st.push(a * b);
                    break;
            }
        }
    }
    return st.top();
}

int postfix_evaluation(string s) {
    stack<int> st1;
    int l = s.length();
    
    for (int i = 0; i < l; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            st1.push(s[i] - '0');
        } else if (s[i] == ' ') {
            continue;
        } else {
            int b = st1.top(); 
            st1.pop();
            int a = st1.top(); 
            st1.pop();
            switch (s[i]) {
                case '+':
                    st1.push(b + a);
                    break;
                case '-':
                    st1.push(b - a);
                    break;
                case '/':
                    st1.push(b / a);
                    break;
                case '*':
                    st1.push(b * a);
                    break;
            }
        }
    }
    return st1.top();
}

int pres(char a) {
    if (a == '^') {
        return 3;
    }
    else if (a == '/' || a == '*') {
        return 2;
    }
    else if (a == '+' || a == '-') {
        return 1;
    }
    return -1;
}

string infix_to_postfix(string s) {
    string res;
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        // Check for alphanumeric characters (letters and digits)
        if (isalnum(s[i])) {
            res += s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            } 
        }
        else { 
            while (!st.empty() && pres(st.top()) >= pres(s[i])) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]); 
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}
void reverse_string(string &s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        swap(s[i], s[n - i - 1]);
    }
}

string infix_to_prefix(string s) {
    string res;
    stack<char> st;
    int l = s.length();  

    for (int i = l - 1; i >= 0; i--) {
        if (isalnum(s[i])) {
            res += s[i];
        } else if (s[i] == ')') {
            st.push(s[i]);
        } else if (s[i] == '(') {
            while (!st.empty() && st.top() != ')') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();  // Pop the ')'
            }
        } else { // For operators
            while (!st.empty() && pres(st.top()) > pres(s[i])) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    
    reverse_string(res);
    
    return res;  
}

bool is_balance(string s){
    
    stack<char> st;
    
    for(int i=0;i<s.length();i++){
        
        if(s[i] == '(' or s[i] == '[' or s[i] == '{'){
            st.push(s[i]);
        }
        else if(!st.empty() && s[i] == ')'){
            if(st.top() == '('){
                st.pop();
            }
            else {
                return false;
            }
        }
        
        
         else if(!st.empty() && s[i] == '}'){
            if(st.top() == '{'){
                st.pop();
            }
            else {
                return false;
            }
        }
        
        
         else if(s[i] == ']'){
            if(!st.empty() && st.top() == '['){
                st.pop();
            }
            else {
                return false;
            }
        }
        
        
    }
    
    if(!st.empty()){
        
        return false;
        
    }
     return true;
    
}

int main() {
    string str = "* + 3 4 5";
    cout << "The answer of the prefix evaluation is given as " << prefix_evaluation(str) << endl;

    string str1 = "3 4 + 5 *"; 
    cout << "The answer of the postfix evaluation is given as " << postfix_evaluation(str1) << endl;
  string a="a+b/c";
  cout<<"The output for the infix to postfix is "<<infix_to_postfix(a)<<endl;
  
  cout<<"The output for the infix to prefix is "<<infix_to_prefix(a)<<endl;
  string s="({[]})";
  cout<<"The output for the valid paranthesis is given as "<<is_balance(s)<<endl;
  
    return 0;
}
