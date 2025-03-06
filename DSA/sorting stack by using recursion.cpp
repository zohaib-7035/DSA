#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element into the sorted stack

void insertSorted(stack<int>& st,int ele){
    if(st.empty() or st.top()<ele){
        st.push(ele);
        return;
    }
    int element=st.top();
    st.pop();
    insertSorted(st,ele);
    st.push(element);
}


// Function to sort the stack using recursion
void sortStack(stack<int>& st) {
   if(st.empty()){
       return ;
   }
   int ele=st.top();
   
   st.pop();
   
    sortStack(st);
    
   insertSorted(st,ele);
}

int main() {
    stack<int> st;
    st.push(50);
    st.push(30);
    st.push(40);

    cout << "Original Stack:" << endl;
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStack(st);

    cout << "Sorted Stack:" << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
