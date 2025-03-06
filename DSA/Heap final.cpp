#include <iostream>
using namespace std;

class heap {
private:
    int arr[100];
    int size;

public:
    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int d) {
        size++;
        int index = size;
        arr[index] = d;

        while (index > 1) {
            if (arr[index / 2] < arr[index]) {
                swap(arr[index / 2], arr[index]);
                index = index / 2;
            } else {
                return;
            }
        }
    }

    void printHeap() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletion() {
        if (size == 0) {
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest]) {
                largest = left;
            }
            if (right <= size && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }

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

    void buildHeap(int arr[], int n) {
        for (int i = n / 2; i >= 1; i--) {
            heapify(arr, n, i);
        }
    }
};

int main() {
    heap h;

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(15);
    h.insert(25);

    cout << "Heap elements after insertions: ";
    h.printHeap();

    h.deletion();
    cout << "Heap elements after one deletion: ";
    h.printHeap();

    int arr[7] = {-1, 40, 50, 30, 20, 25, 35}; // -1 is a placeholder for 1-based indexing
    int n = 6;

    h.buildHeap(arr, n);

    cout << "Heap elements after building heap from array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
