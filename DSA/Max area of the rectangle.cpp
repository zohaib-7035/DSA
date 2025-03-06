#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> presmallerelement(const vector<int>& arr) {
    stack<int> st;
    st.push(-1);
    vector<int> ans(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        while (st.top() != -1 && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> nextSmallerElement(const vector<int>& arr) {
    stack<int> st;
    st.push(-1);
    vector<int> ans(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--) {
        while (st.top() != -1 && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestrectangulararea(const vector<int>& height) {
    vector<int> next = nextSmallerElement(height);
    vector<int> pre = presmallerelement(height);
    int area = INT_MIN;
    
    for (int i = 0; i < height.size(); i++) {
        int length = height[i];
        if (next[i] == -1) {
            next[i] = height.size();
        }
        int width = next[i] - pre[i] - 1;
        int newarea = length * width;
        area = max(area, newarea);
    }
    return area;
}

int maxarea(const vector<vector<int>>& M) {
    if (M.empty()) return 0;
    
    int n = M.size();
    int m = M[0].size();
    int area = largestrectangulararea(M[0]);
    
    vector<vector<int>> height = M;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j] != 0) {
                height[i][j] += height[i-1][j];
            } else {
                height[i][j] = 0;
            }
        }
        area = max(area, largestrectangulararea(height[i]));
    }
    return area;
}

int main() {
    // Define the matrix
    vector<vector<int>> M = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 0}
    };

    // Find the maximum area
    int result = maxarea(M);

    // Print the result
    cout << "The maximum rectangular area is " << result << endl;

    return 0;
}
