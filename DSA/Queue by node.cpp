#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node(int d) {  // Constructor to accept data as a parameter
        data = d;
        next = NULL;
    }
};

class queue {
    node *front;
    node *back;
public:
    queue() {
        front = NULL;
        back = NULL;
    }

    void enqueue(int data) {
        node *newnode = new node(data);  // Create a new node with the data
        if (front == NULL) {
            front = newnode;
            back = newnode;
        } else {
            back->next = newnode;
            back = newnode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }
        node *td = front;  // Corrected variable name
        front = front->next;
        delete td;  // Corrected deletion of node
    }

    bool is_empty() {
        return front == NULL;
    }

    int peak() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return -1;  // Return -1 if queue is empty
        }
        return front->data;
    }
};

int main() {
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peak() << endl;  // Outputs 10

    q.dequeue();
    cout << "Front element after dequeue: " << q.peak() << endl;  // Outputs 20

    q.dequeue();
    q.dequeue();
    cout << "Queue empty: " << (q.is_empty() ? "Yes" : "No") << endl;  // Outputs Yes

    return 0;
}
