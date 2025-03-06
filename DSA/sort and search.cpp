#include <iostream>
#include <algorithm> // For std::sort

using namespace std;

int main() {
    int numbers[6] = {1, 4, 2, 5, 3, 0}; // Initialize array with 6 elements

    // Sort the array
    sort(numbers, numbers + 6);

  if( binary_search(numbers,numbers+6,3)){
      cout<<"The number is found"<<endl;
  }
  else {
      cout<<"The number is not found "<<endl;
  }
    // Print the sorted array
    for (int i = 0; i < 6; i++) {
        cout << numbers[i] << endl;
    }

    return 0;
}
