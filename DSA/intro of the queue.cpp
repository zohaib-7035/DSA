#include<iostream>
// #include<queue> 
#define n 20
using namespace std;

class queue{
  int *arr;
  int front;
  int back;
  public:
  
  
  queue(){
      arr=new int[n];
      front=-1;
      back=-1;
  }
  
  
  
  void push(int x){
      if(back==n-1){
          cout<<"There is no space avilable "<<endl;
      }
      back++;
      arr[back]=x;
      if(front==-1){
          front++;
      }
  }
  
  
  void pop(){
      if(front==-1 || front>back){
          cout<<"No element is present in the queue"<<endl;
          return;
      }
      front++;
  }
  int peek(){
      if(front==-1 || front>back){
          cout<<"No element is present in the queue"<<endl;
          return -1;
      }
      return arr[front];
  }
  bool empty(){
      if(front==-1 || front>back){
          return true;
      }
      return false;
  }
  
};




int main(){
    queue a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    cout<<"For the checking of the its empty function : "<<a.empty()<<endl;
    cout<<"The values of the queue is given below "<<endl;
    while(!a.empty()){
   cout<<a.peek()<<endl;
    a.pop();
}
    cout<<"For the checking of the its empty function : "<<a.empty()<<endl;

    
    
    
    return 0;
}