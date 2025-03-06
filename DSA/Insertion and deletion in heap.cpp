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
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " "; // Print all heap elements
        }
        cout << endl;
    }
    void deletefromheap(){
        if(size==0){
            return ;
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<=size){
            int left=i*2;
            int right=i*2+1;
            if(left<size && arr[left]>arr[i]){
                swap(arr[left],arr[i]);
                i=left;
            }
            else if(right<size && arr[right]>arr[i]){
                swap(arr[right],arr[i]);
                i=right;
            }
            else {
                return;
            }
        }
    }
};

int main() {
    Heap maxHeap;
    maxHeap.insert(50);
    maxHeap.insert(55);
    maxHeap.insert(53);
    maxHeap.insert(52);
    maxHeap.insert(54);
    maxHeap.print();
    maxHeap.deletefromheap();
    maxHeap.print();

    return 0;
}
