#include<iostream>
using namespace std;
class node{
  public:
  int value;
  node *next;
  node *pre;
  node(int data){
      value=data;
      next=NULL;
      pre=NULL;
  }
};
void insertathead(node *&head,int data){
 node *temp=new node(data);
 temp->next=head;
 if(head!=NULL){
 head->pre=temp;
 }
 head =temp;
}
void insertattail(node *&n,int data){
    if(n==NULL){
        insertathead(n,data);
        return ;
    }
    node *temp=new node(data);
    node *head=n;
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=temp;
    temp->pre=head;
}
void display(node * & head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void deleteathead(node * & head){
    if(head!=NULL){
    node *temp=head;
    head=head->next;
    if(head!=NULL){
        head->pre=NULL;
    }
    delete temp;
}}
void deleltenode(node * &n,int pos){
    if(pos==1){
        deleteathead(n);
        return ;  
    }
    node *temp=n;
    int c=1;
    while(temp!=NULL && c!=pos){
        temp=temp->next;
        c++;
    }
    temp->pre->next=temp->next;
    if(temp->next!=NULL){
    temp->next->pre=temp->pre;
    }
    delete temp;
}
int main(){
    node *temp=NULL;
    insertattail(temp,1);
    insertattail(temp,2);
    insertattail(temp,3);
    insertattail(temp,4);
    insertattail(temp,5);
    insertattail(temp,6);
    insertattail(temp,7);
display(temp);
insertathead(temp,0);
display(temp);
deleltenode(temp,5);
cout<<"/// After deletion ///"<<endl;
display(temp);

    return 0;
}