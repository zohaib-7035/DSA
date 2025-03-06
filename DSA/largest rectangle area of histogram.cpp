#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> presmallerelement(vector<int>& arr, int n) {
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        while (st.top() != -1 && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> nextSmallerElement(vector<int>& arr, int n) {
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        while (st.top() != -1 && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestrectangulararea(vector<int>& height, int n) {
    vector<int> next = nextSmallerElement(height, n);
    vector<int> pre = presmallerelement(height, n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++) {
        int length = height[i];
        if (next[i] == -1) {
            next[i] = n;
        }
        int width = next[i] - pre[i] - 1;
        int newarea = length * width;
        area = max(area, newarea);
    }
    return area;
}

int main() {
    vector<int> height = {2, 1, 5, 6, 2, 3};
    int n = height.size();
    int max_area = largestrectangulararea(height, n);
    cout << "The largest rectangular area is: " << max_area << endl;
    return 0;
}
