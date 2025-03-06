#include<iostream>
#include<queue>
using namespace std;

class stack{
  int n;
  queue<int> q1;
  queue<int> q2;
  public:
  
  stack(){
      n = 0;
  }
  
  void push(int d){
      n++;
      q2.push(d);
      while(!q1.empty()){
          q2.push(q1.front());  // Corrected to use front()
          q1.pop();
      }
      swap(q2, q1);
  }
  
  void pop(){
      if (!q1.empty()) {
          q1.pop();
          n--;
      }
  }
  
  int top(){
      if (!q1.empty()) {
          return q1.front();  // Corrected to use front()
      }
      return -1;  // Return an invalid value if the stack is empty
  }
  
  int size(){
      return n;
  }

  bool empty() {
      return n == 0;
  }
};

int main(){
    stack s;
    
    // Check if stack is empty
    cout << (s.empty() ? "Stack is empty" : "Stack is not empty") << endl;
    
    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);
    
    // Check if stack is empty after pushing
    cout << (s.empty() ? "Stack is empty" : "Stack is not empty") << endl;
    
    // Display the top element
    cout << "Top element: " << s.top() << endl;
    
    // Display the size of the stack
    cout << "Size of the stack: " << s.size() << endl;
    
    // Pop an element from the stack
    s.pop();
    
    // Display the top element and size after popping
    cout << "Top element after pop: " << s.top() << endl;
    cout << "Size of the stack after pop: " << s.size() << endl;
    
    // Pop all elements to make the stack empty
    s.pop();
    s.pop();
    
    // Check if stack is empty after popping all elements
    cout << (s.empty() ? "Stack is empty" : "Stack is not empty") << endl;

    return 0;
}
