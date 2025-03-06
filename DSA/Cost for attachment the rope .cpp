#include <iostream>
#include<queue>
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

int sum_till_k(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> q;
     for(int i=0;i<n;i++){
             int s=0;
         for(int j=i;j<n;j++){
             s+=arr[j];
             if(q.size() < k ){
                 q.push(s);
             }
             else {
                 if(s > q.top() ){
                       q.pop();
                       q.push(s);
                 }
             }
         }
     }
    
    return q.top();
    
}


int kthsamllest_element(int arr[],int n,int k){
    priority_queue<int> q;
    for(int i=0;i<k;i++){
        q.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(q.top() > arr[i]){
            q.pop();
            q.push(arr[i]);
        }
    }
    return q.top();
}


int ropeattachmentcost(int arr[],int n){
    int s=0;
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=0;i<n;i++){
        q.push(arr[i]);
    }
    
    while(q.size()>1){
        int a=q.top();
        q.pop();
         int b=q.top();
         q.pop();
         int c=a+b;
        s=s+c;
        q.push(c);
    }
    return s;
}




int main() {
    Heap maxHeap;
    maxHeap.insert(50);
    maxHeap.insert(55);
    maxHeap.insert(53);
    maxHeap.insert(52);
    maxHeap.insert(54);
    maxHeap.print();
  
   int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
cout<<"The sum till k is given as "<< sum_till_k(arr,n,4)<<endl;;

cout<<"The kth smallest element in the array is "<<kthsamllest_element(arr,n,3)<<endl;
int array[]={4,3,2,6};
 int m = sizeof(array) / sizeof(array[0]);
cout<<"The rope attaching function is given as "<<ropeattachmentcost(array,m)<<endl;
    return 0;
}