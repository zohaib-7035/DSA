#include <iostream>
#include <stack>
using namespace std;

void reversestring(string s) {
    stack<string> st;
    for (int i = 0; i < s.length(); i++) {
        string word = "";
        while (i < s.length() && s[i] != ' ') {
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

stack<int> reversestack(stack<int>& st) {
    stack<int> reversedStack;
    while (!st.empty()) {
        reversedStack.push(st.top());
        st.pop();
    }
    return reversedStack;
}

int main() {
    string s = "How are you?";
    reversestring(s);

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    stack<int> reversedSt = reversestack(st);

    cout << "Reversed stack elements: ";
    while (!reversedSt.empty()) {
        cout << reversedSt.top() << " ";
        reversedSt.pop();
    }
    cout << endl;

    return 0;
}
