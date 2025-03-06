#include<iostream>
using namespace std;
class node{
  public:
  int data;
  node *next;
  node(){
      data=0;
      next=0;
  }
   node(int value){
      data=value;
      next=NULL;
  }
};


void print(node * head){
    if(head==NULL){
        cout<<"No element in the linklist"<<endl;
        return ;
    }
      node * temp=head;
      while(temp!=NULL){
          cout<<temp->data<<" ";
          temp=temp->next;
      }
      cout<<endl;
  }
  
  
  void insert(node *& head,int value){
      
              node *temp=new node(value);
      if(head==NULL){
          
          temp->next=NULL;
          head=temp;
      }
      else{
        
          temp->next=head;
          head=temp;
      }
  }
  
  void insert_at_bottom(node *& head,int value){
  node *temp=new node (value);
  node *curr=head;
 
  while(curr->next!=NULL){
      curr=curr->next;
  }
  
  curr->next=temp;
  
  }
  
  
  void insert_at_middle(node *&head,int value,int pos){
      if(head==NULL){
          cout<<"Can't be inserted at the bottom"<<endl;
          return ;
  }
      node *temp=new node(value);
      node *curr=head;
      int i=1;
      while(i<pos){
          curr=curr->next;
          i++;
      }
      temp->next=curr->next;
            curr->next=temp;
  }
  void delete_at_last(node *&head){
      if(head==NULL){
          cout<<"Nothing can be deleted "<<endl;
          return;
      }
      
      if(head->next==NULL){
          delete head;
          head=NULL;
          return ;
      }
      node * temp=head;
      
      while(temp->next->next != NULL){
         temp =  temp->next;
      }
      delete temp->next;
      temp->next=NULL;
  }
  
  void delete_element(node *&head,int ele){
      if(head==NULL){
          cout<<"It is empty "<<endl;
          return;
      }
      if(head->next==NULL && head->data==ele){
          delete head;
          head=NULL;
          return ;
      }
      
      node *temp=head;
      
      while(temp !=NULL ){
          if(temp->next->data==ele){
              node *t=temp->next;
              temp->next=temp->next->next;
              delete t;
              return ;
          }
          temp=temp->next;
      }
      cout<<"Element is not present in the linklist "<<endl;
  }
  
  
  void insertion_in_orderlist(node *&head,int ele){
      node *t=new node(ele);
      if(head==NULL){
          head=t;
          return ;
      }
      if(head->data>ele){
          t->next=head;
          head=t;
          return;
      }
      
      node *temp=head;
      
      while(temp!=NULL){
          if(temp->next->data>ele){
              t->next=temp->next;
              temp->next=t;
              return;
          }
          else if(temp->next==NULL){
              temp->next=t;
              return ;
          }
          temp=temp->next;
      }
      
  }
  
  void reverse_linklist(node *&head){
      if(head==NULL){
          cout<<"Nothing in the list"<<endl;
          return;
      }
      node *pre=NULL;
      node *curr=head;
      node *next=head->next;
      
      while(curr!=NULL){
          next=curr->next;
          curr->next=pre;
          pre=curr;
          curr=next;
      }
      head=pre;
  }
int main(){
    node *head=new node(0);
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    cout<<"Printing for the insert at start"<<endl;
    print(head);



       node *head1=new node(0);
    insert_at_bottom(head1,1);
    insert_at_bottom(head1,2);
    insert_at_bottom(head1,3);
    insert_at_bottom(head1,4);
    insert_at_bottom(head1,5);
    cout<<"Printing for the insert at last"<<endl;
    print(head1);
    
        insert_at_middle(head1,10,3);
    cout<<"Printing for the insert at middle"<<endl;
    print(head1);
    delete_at_last(head1);
    cout<<"Printing after deleting at the last "<<endl;
    print(head1);
    delete_element(head1,10);
    cout<<"delete_element() Output after this function is given below "<<endl;
    print(head1);
     insert_at_bottom(head1,6);
     cout<<"After insertion of 5 at last of the linklist"<<endl;
     print(head1);
    insertion_in_orderlist(head1,5);
    cout<<"insertion_in_orderlist(head,4) after this function is given as "<<endl;
    print(head1);
    cout<<"Linklist before reversing the linklist"<<endl;
    print(head);
    reverse_linklist(head);
    cout<<"Linklist after reversing the linklist"<<endl;
    print(head);
    
    return 0;
}