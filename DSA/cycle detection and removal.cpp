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
 bool search(node * & n,int key){
     node * a=n;
     while(a!=0){
         if(a->value==key){
             return true;
         }
         a=a->next;
     }
     return false;
 }
 void deleteathead(node * &n){
     node * todelete=n;
     n=n->next;
     delete todelete;
 }
 void deletenode(node * & n,int d){
     if(n==NULL){
         cout<<"NO node is present here "<<endl;
         return ;
     }
     if(n->next==NULL){
         deleteathead(n);
         return ;
     }
     node * temp=n;
     while(temp->next->value!=d){
         temp=temp->next;
     }
     node *a=temp->next;
     temp->next=temp->next->next;
     delete a;
     
 }
 node * reverseLL(node * head){
     node *pre=NULL;
     node *curr=head;
     node *Next=NULL;
     while(curr!=NULL){
         Next=curr->next;
         curr->next=pre;
         pre=curr;
         curr=Next;
     }
     return pre;
 }
 node *reverseKnode(node *& n,int k){
     node * pre=NULL;
     node *curr=n;
     node *next;
     int c=0;
     while(curr!=NULL && c<k){
         next=curr->next;
         curr->next=pre;
         pre=curr;
         curr=next;
         c++;
     }
     if(next!=NULL){
     n->next=reverseKnode(next,k);
     }
     return pre;
 }
 bool detectcycle(node * head){
     node *slow=head;
     node *fast=head;
     while(fast!=NULL && fast->next!=NULL){
      fast=fast->next->next;
     slow=slow->next;
     if(fast->next==slow->next){
         return true;
     }
 }
 return false;
 }
 void makecycle(node *head,int pos){
     node *temp=head;
     node *startnode;
     int c=1;
     while(temp->next!=NULL){
         if(c==pos){
             startnode=temp;
         }
         temp=temp->next;
         c++;
     }
     temp->next=startnode;
}
void removecylce(node * head){
    node *fast=head;
    node *slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next->next;
    }
    fast=head;
    while(slow->next!=fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
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
    cout<<endl;
    cout<<"Its mean that 5 is not present in the node "<<endl;
    cout<<search(tail,5)<<endl<<endl;
    deletenode(tail,18);
    display(tail);
    deleteathead(tail);
    cout<<endl;
    display(tail);
     node *reverse=new node(17);
    insertattail(reverse,18);
    insertattail(reverse,20);
    insertattail(reverse,22);
    cout<<"The unreversed link list "<<endl;
    display(reverse);
   node *r= reverseLL(reverse);
    cout<<"The reversed link list is given as "<<endl;
        display(r);
        cout<<"The output of the reverseknode"<<endl;
        node *k=reverseKnode(r,2);
        display(k);
node *t=new node(1);
insertattail(t,2);
insertattail(t,3);
insertattail(t,4);
insertattail(t,5);
insertattail(t,6);
insertattail(t,7);
insertattail(t,8);
insertattail(t,9);
makecycle(t,4);
// display(t);we cannot print it as it is now in a makecycle
cout<<"The cycle detection is given as "<<detectcycle(t)<<endl<<endl;
removecylce(t);
cout<<"The cycle detection after removing the cycle is given as "<<detectcycle(t)<<endl;

    return 0;
}