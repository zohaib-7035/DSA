#include<iostream>
using namespace std;
#define n 20

class queue {
    int *arr;
    int front;
    int back;
public:
    queue() {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enqueue(int d) {
        if (back == n - 1) {
            cout << "Queue overflow!" << endl;
            return;
        }
        back++;
        arr[back] = d;
        if (front == -1) {
            front++;
        }
    }

    void dequeue() {
        if (front == -1 || front > back) { // Correcting condition
            cout << "Queue underflow!" << endl;
            return;
        }
        front++;
        if (front > back) { // Queue becomes empty
            front = -1;
            back = -1;
        }
    }

    bool isempty() {
        return front == -1;
    }

    int peek() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    ~queue() {
        delete[] arr; // Freeing allocated memory
    }
};

int main() {
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();
    cout << "Queue empty: " << (q.isempty() ? "Yes" : "No") << endl;

    return 0;
}
