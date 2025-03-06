#include<iostream>
using namespace std;
class node{
 public:
 int value;
 node * next;
 node(){
     value=0;
     next=0;
 }
 node(int v){
     value=v;
     next=NULL;
 }
};
 void insertathead(node *& n,int val){
      node * temp=new node(val);
      temp->next=n;
      n=temp;//This line updated the pointer pointing to the new node
 }
void insertatmiddle(node * & a,int pos ,int d){
    if(pos==1){
        insertathead(a,d);
        return ;
    }
    else{
        int c=1;
        node *temp=new node(d);
        node * b=a;
        while(c!=pos-1 && b != nullptr){
            b=b->next;
            c++;
        }
        temp->next=b->next;
        b->next=temp;
    }
}
void insertattail(node * & a,int data){
    node *head =new node(data);
    if(a==NULL){
        a=head;
    }
    else
    {
    node * b=a;
    while(b->next!=0){
        b=b->next;
    }
    b->next=head;
}
}


 void display(node *&n){
     node *temp=n;
     while(temp != NULL){
         cout<<temp->value<<endl;
         temp=temp->next;
     }
     
 }
int main(){
    // node * n=new node;
      node * n=new node(10);
    // n->display();
    cout<<"Insert at head"<<endl;
    node *temp=n;
    insertathead(n,12);
    insertathead(n,14);
    insertathead(n,16);
    display(n);
    cout<<"Insert at tail"<<endl;
    node *tail=new node(17);
    insertattail(tail,18);
    insertattail(tail,20);
    insertattail(tail,22);
    display(tail);
    cout<<"The output for the insertatmiddle"<<endl;
    insertatmiddle(tail,3,40);
    display(tail);
    return 0;
}