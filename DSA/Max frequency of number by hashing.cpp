#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxFrequency(vector<int> &arr, int n) {
    unordered_map<int, int> count;
    int maxFreq = 0;
    int maxElement = arr[0];

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;

        if (count[arr[i]] > maxFreq) {
            maxFreq = count[arr[i]];
            maxElement = arr[i];
        }
    }

    return maxElement; 
}

int main() {
    vector<int> arr = {1, 3, 2, 1, 4, 1, 2, 2, 2}; // Example input
    int n = arr.size();
    
    int result = maxFrequency(arr, n);
    cout << "Element with maximum frequency: " << result << endl;
    
    return 0;
}
