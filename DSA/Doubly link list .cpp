#include<iostream>
using namespace std;
class node{
  public:
  int data;
  node *next;
  node *pre;
  node(){
      data=0;
      next=NULL;
      pre=NULL;
  }
  node(int d){
      data=d;
      next=pre=NULL;
  }
};


class list{
 public:
  node *head;
  node *tail;
  list(){
      head=NULL;
      tail=NULL;
  }
  list(int d){
      node *temp=new node(d);
      head=tail=temp;
  }
  
  void insert_at_start(int value){
      node *temp=new node(value);
      if(head==NULL){
         head=temp;
         tail=temp;
      }
      else{
          temp->next=head;
          head->pre=temp;
          head=temp;
          
      }
      
  }
  void print(){
      node *temp=head;
      while(temp!=NULL){
          cout<<temp->data<<" ";
          temp=temp->next;
      }
      cout<<endl;
  }
  
  void insert_at_end(int value){
      node *temp=new node(value);
      if(head==NULL){
          head=temp;
          tail=temp;
      }
      else{
          tail->next=temp;
          temp->pre=tail;
          tail=temp;
      }
  }
  
  void insert_at_middle(int value,int pos){
      if(head==NULL){
          return ;
      }
      node *n=new node(value);
      node *temp=head;
      if(temp->next==NULL){
          return;
      }
      int i=1;
      while(i<pos){
          temp=temp->next;
          i++;
      }
      n->next=temp->next;
      temp->next->pre=n;
      temp->next=n;
      n->pre=temp;
      
      
  }
  
  void delete_at_start(){
      if(head==NULL){
          return;
      }
      node * temp=head;
      head=head->next;
      head->pre=NULL;
      delete temp;
      
  }
  
  void delete_at_end(){
      if(head==NULL){
          return;
      }
      node *temp=tail;
      tail->pre->next=NULL;
      delete temp;
  }
  
  void delete_from_middle(int pos){
      if(head==NULL){
          return;
      }
      if(pos==1){
          this->delete_at_start();
          return;
      }
      node *temp=head;
      int i=1;
      while(i<pos-1){
          temp=temp->next;
          i++;
      }
      if(temp == NULL){
          cout<<"you entered the wrong index for deletion"<<endl;
          return;
      }
      else if(temp->next->next==NULL){
          node *t=temp->next;
          temp->next=NULL;
          tail=temp;
          delete t;
      }
      else if(temp->next->next != NULL){
          node *t=temp->next;
          temp->next=temp->next->next;
          temp->next->pre=temp;
          delete t;
        }
    }
    
};



int main(){
    list *head=new list(0);
    head->insert_at_start(1);
    head->insert_at_start(2);
    head->insert_at_start(3);
    head->insert_at_start(4);
    head->insert_at_start(5);
    head->insert_at_start(6);
    head->print();
    
    cout<<"The output of insert at end"<<endl;
    list *head1=new list(0);
    head1->insert_at_end(1);
    head1->insert_at_end(2);
    head1->insert_at_end(3);
    head1->insert_at_end(4);
    head1->insert_at_end(5);
    head1->insert_at_end(6);
    head1->print();
    
    cout<<"The output of the insert_at_middle"<<endl;
    head1->insert_at_middle(5,5);
    head1->print();

    cout<<"The output after the delete from the start"<<endl;
    head1->delete_at_start();
    head1->print();
    
    cout<<"The output after the delete from the end"<<endl;
    head1->delete_at_end();
    head1->print();
    
    cout<<"The output after deleting from the middle "<<endl;
    head1->delete_from_middle(5);
    head1->print();
    return 0;
}