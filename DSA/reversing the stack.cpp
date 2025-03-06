#include <iostream>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int>& st, int ele) {
    if (st.empty()) {
        st.push(ele);
        return;
    }
    int e = st.top();
    st.pop();
    insert_at_bottom(st, ele);
    st.push(e);
}

void reverse(stack<int>& st) {
    if (st.empty()) {
        return;
    }
    int t = st.top();
    st.pop();
    reverse(st);
    insert_at_bottom(st, t);
}

void print_stack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original Stack: ";
    print_stack(st);

    reverse(st);

    cout << "Reversed Stack: ";
    print_stack(st);

    return 0;
}
