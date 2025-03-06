#include<iostream>
using namespace std;
class node {
  public:
  int data;
  node *next;
  node(){
      data=0;
      next=NULL;
  }
  node(int value){
      data=value;
      next=NULL;
  }
};
class CLL{
  public:
  node *head;
  CLL(){
      head=NULL;
  }
  CLL(int v){
      head=new node(v);
      head->next=head;
  }
  
  void insert_at_start(int v){
               
      node *temp=new node(v);
      
      if(head==NULL){
          head=temp;
          head->next=head;
          return;
      }
      
      else{
          temp->next=head;
          node *t=head;
          while(t->next!=head){
              t=t->next;
          }
          
          t->next=temp;
          head=temp;
          
      }
  }
  
 void print() {
    if (head == NULL) {
        return;  
    }
    node *temp=head;

    while (temp->next != head) {      
        cout << temp->data << " ";  
        temp = temp->next;       
    }
    cout << endl;
}

void insert_at_last(int value){
    node  *t=new node(value);
    if(head==NULL){
        head=t;
        head->next=t;
        return;
    }
    node *temp=head;
    while(temp->next != head){
        temp=temp->next;
    }
    temp->next=t;
    t->next=head;
}

void delete_at_start(){
    if(head==NULL){
        return;
    }
    if(head->next==head){
     node *temp=head;
     delete temp;
     head=NULL;
    }
    else{
        node *t=head;
        node *temp =head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=head->next;
        head=head->next; 
        delete t;
    }
} 

 void delete_at_end(){
     if(head==NULL){
         return;
     }
     else if(head->next==head){
         node *t=head;
         delete t;
         head=NULL;
     }
     else{
     node*temp=head;
     while(temp->next->next != head){
         temp=temp->next;
     }
     node *t=temp->next;
     temp->next=temp->next->next;
     delete t;
     
     }
 }
 void delete_at_middle(int pos){
    if(head==NULL){
        return ;
    }
    else if(head->next==head && pos== 1){
        this->delete_at_start();
       return;
    }
    else if(head->next!=head && pos != 1){
        int i=1;
        node *temp=head;
        while(i<pos-1 && temp ->next !=NULL){
            temp=temp->next;
        }
        if(temp->next == NULL){
            cout<<"Invalid index"<<endl;
            return;
        }
        else{
            node *todel=temp->next;
            temp->next=temp->next->next;
            delete todel;
        }
        
    }
}
};

int main(){
    CLL list;
    list.insert_at_start(0);
    list.insert_at_start(1);
    list.insert_at_start(2);
    list.insert_at_start(3);
    list.insert_at_start(4);
    list.insert_at_start(5);
    
    cout<<"The ouput after inserting at start"<<endl;
    list.print();
    
    CLL l;
    l.insert_at_last(0);
    l.insert_at_last(1);
    l.insert_at_last(2);
    l.insert_at_last(3);
    l.insert_at_last(4);
    l.insert_at_last(5);
    cout<<"The output after inserting at end "<<endl;
    l.print();
    
    //cout<<"The output after deleting from the middle "<<endl;
    // l.delete_at_middle(2);
    // l.print();
    
    
    l.delete_at_start();
    cout<<"The output after deleting from the start "<<endl;
    l.print();
    
    cout<<"The output after deleting form the end "<<endl;
    l.delete_at_end();
    l.print();
    
    return 0;
}