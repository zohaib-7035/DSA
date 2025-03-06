#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> nums = {1, 2, 3};

    // Sort the vector to start with the smallest permutation
    sort(nums.begin(), nums.end());

    cout << "All permutations of the array:" << std::endl;

    // Generate all permutations
    do {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << std::endl;
    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}
