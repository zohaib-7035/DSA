#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        arr[i] = -1;  // Initialize all elements to -1
    }
    
    int *array = new int[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int mini = INT_MAX;  // Initialize mini to the maximum possible integer value

    for(int i = 0; i < n; i++) {
        if(arr[array[i]] != -1) {  // Check if the index in arr is not -1
            mini = min(mini, arr[array[i]]);  // Update mini with the minimum value
        } else {
            arr[array[i]] = i;  // Set the index in arr to the current index
        }
    }

    if(mini == INT_MAX) {
        cout << "Your value is not found: -1" << endl;
    } else {
        cout << "The answer is " << mini + 1 << endl;
    }

    delete[] array;
    delete[] arr;

    return 0;
}
