#include<iostream>
using namespace std;
#define n 100
class stack{
    int *arr;
    int top;
    public:
    stack(){
        arr=new int [n];
        top=-1;
    }
    void push(int x){
        if(top==n-1){
            cout<<"No space in the stack"<<endl;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(this->top==-1){
            cout<<"Nothing to pop"<<endl;
            return ;
        }
        top--;
        
    }
    int empty(){
        return top==-1;
    }
    
    int Top(){
        if(top==-1){
            return -1;
        }
        return arr[top];
    }
};
int main(){
    stack array;
    array.push(1);
    array.push(2);
    array.push(3);
    cout<<array.Top()<<endl;
    array.pop();
       cout<<"For Empty function "<< array.empty()<<endl;;
        cout<<array.Top()<<endl;
    array.pop();
            cout<<array.Top()<<endl;
    array.pop();//here the top value is not -1, so it is not print pop msg
    array.pop();

            cout<<"For the Top function "<<array.Top()<<endl<<endl;
   cout<<"For Empty function "<< array.empty()<<endl;
    return 0;
    
}
