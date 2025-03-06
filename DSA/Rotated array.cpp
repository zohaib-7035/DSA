#include<iostream>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int arr1[6];
    int k = 2; // Number of positions to rotate

    // Perform rotation
    for(int i = 0; i < n; i++) {
        arr1[(i + k) % n] = arr[i];
    }

    // Copy the rotated array back to the original array
    for(int i = 0; i < n; i++) {
        arr[i] = arr1[i];
    }

    // Print the rotated array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
