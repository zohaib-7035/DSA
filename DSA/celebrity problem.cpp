#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool know(vector<vector<int>>& M, int a, int b) {
    return M[a][b] == 1;
}

int celebrityproblem(vector<vector<int>>& M, int n) {
    stack<int> st;

    // Push all candidates to the stack
    for (int i = 0; i < n; i++) {
        st.push(i);
    }
    
    // Determine the potential celebrity
    while (st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        
        if (know(M, a, b)) {
            // a knows b, so a cannot be a celebrity
            st.push(b);
        } else {
            // a does not know b, so b cannot be a celebrity
            st.push(a);
        }
    }
    
    if (st.empty()) return -1; // No candidates left
    
    int ans = st.top();
    
    // Verify if the candidate is actually a celebrity
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (M[ans][i] == 0) {
            c1++;
        }
    }
    
    if (c1 != n) return -1; // Not everyone knows the celebrity
    
    for (int i = 0; i < n; i++) {
        if (M[i][ans] != 0) {
            c2++;
        }
    }
    
    if (c2 != n - 1) return -1; // Celebrity must be known by everyone else
    
    return ans;
}

int main() {
    // Define the number of people
    int n = 4;

    // Initialize the matrix
    vector<vector<int>> M = {
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0}
    };

    // Find the celebrity
    int celebrity = celebrityproblem(M, n);

    // Print the result
    if (celebrity == -1) {
        cout << "No celebrity found" << endl;
    } else {
        cout << "The celebrity is person " << celebrity << endl;
    }

    return 0;
}
