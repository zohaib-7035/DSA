#include<iostream>
#include<stack>
using namespace std;

class queue {
    stack<int> s1;
    stack<int> s2;
    
public:
    // Enqueue an element into the queue
    void enqueue(int d) {
        s1.push(d);
    }
    
    // Dequeue an element from the queue
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        // Move elements from s1 to s2 if s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();  // Remove the front element
    }
    
    // Return the front element of the queue
    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;  // Return -1 if queue is empty
        }
        
        // Move elements from s1 to s2 if s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();  // Return the top element of s2, which is the front of the queue
    }
    
    // Check if the queue is empty
    bool is_empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;  // Outputs 10
    q.dequeue();
    
    cout << "Front element after dequeue: " << q.front() << endl;  // Outputs 20
    q.dequeue();

    q.dequeue();
    cout << "Queue empty: " << (q.is_empty() ? "Yes" : "No") << endl;  // Outputs Yes

    return 0;
}
