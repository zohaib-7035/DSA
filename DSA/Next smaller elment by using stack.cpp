#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(vector<int>& arr, int n) {
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        while (st.top() >= arr[i]) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    int n = arr.size();
    vector<int> ans = nextSmallerElement(arr, n);

    cout << "Next smaller elements are: ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
