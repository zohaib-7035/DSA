#include<iostream>
// #include<queue> 
using namespace std;
class node {
      public:
  int data;
  node *next;
  node(int d){
   data=d;
   NULL;
  }
};

class queue{
  node *front;
  node *back;
  public:
  
  
  queue(){
      back=NULL;
      front=NULL;
  }
  
  
  
  void push(int x){
     node *n=new node(x);
     if(front==NULL){
         front=n;
         back=n;
         return ; 
     }
     back->next=n;
     back=n;
  }
  void pop(){
      if(front==NULL){
          cout<<"There is nothing to pop"<<endl;
          return;
      }
      node *todelete=front;
      front=front->next;
      delete todelete;
  }
  
 
  int peek(){
      if(front==NULL){
          cout<<"No element to return "<<endl;
          return-1 ;
      }
      return front->data;
  }
  bool empty(){
      if(front==NULL){
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