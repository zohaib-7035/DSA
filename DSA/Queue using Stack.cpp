#include <iostream>
#include <stack>
using namespace std;

class queue {
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s1.empty() && s2.empty()) {
            cout << "NO element to pop" << endl;
            return -1;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int value = s2.top();
        s2.pop();
        return value;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    queue a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);

    cout << a.pop() << endl; // Output: 1
    cout << a.pop() << endl; // Output: 2
    cout << a.pop() << endl; // Output: 3
    cout << a.pop() << endl; // Output: 4
    cout << a.pop() << endl; // Output: 5
    cout << a.pop() << endl; // Output: NO element to pop and returns -1
    cout << a.empty() << endl; // Output: 1 (true)

    return 0;
}
