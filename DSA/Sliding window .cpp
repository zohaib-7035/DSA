#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;

    // Initialize the deque for the first window
    for (int i = 0; i < k; ++i) {
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    result.push_back(arr[dq.front()]);

    // Process the rest of the array
    for (int i = k; i < arr.size(); ++i) {
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
        result.push_back(arr[dq.front()]);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(arr, k);
    cout << "Sliding window maximums are: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
