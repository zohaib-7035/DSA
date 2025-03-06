#include <iostream>
using namespace std;

class Heap {
public:
    int arr[100]; // Array to store heap elements
    int size;

    Heap() {
        arr[0] = -1; // Common practice to start indexing from 1
        size = 0;
    }

    void insert(int value) {
        size = size + 1; // Increment size
        int index = size; // Start at the new element's position
        arr[index] = value;

        // Heapify the tree by moving the inserted element up to its correct position
        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] < arr[index]) { // Compare parent and child values
                swap(arr[parent], arr[index]); // Swap parent and child
                index = parent; // Move up to the parent's position
            } else {
                break; // If the heap property is satisfied, stop
            }
        }
    }

    void print() {
        cout << "The printing function call: ";
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " "; // Print all heap elements
        }
        cout << endl;
    }

    void deleteFromHeap() {
        if (size == 0) {
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i <= size) {
            int left = i * 2;
            int right = i * 2 + 1;
            if (left <= size && arr[left] > arr[i]) {
                swap(arr[left], arr[i]);
                i = left;
            } else if (right <= size && arr[right] > arr[i]) {
                swap(arr[right], arr[i]);
                i = right;
            } else {
                return;
            }
        }
    }
};

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    int size = n;
    while (size > 1) {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main() {
    Heap maxHeap;
    maxHeap.insert(50);
    maxHeap.insert(55);
    maxHeap.insert(53);
    maxHeap.insert(52);
    maxHeap.insert(54);
    maxHeap.print();
    maxHeap.deleteFromHeap();
    maxHeap.print();

    int arr[] = {-1, 54, 53, 55, 52, 50}; // Example array, 1-based index
    int n = 5;

    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    cout << "The heapified array is given as: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);
    cout << "The sorted array is given as: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
