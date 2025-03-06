#include<iostream>
using namespace std;

class node {
public:
    int value;
    node* next;
    node() {
        value = 0;
        next = NULL;
    }
    node(int d) {
        value = d;
        next = NULL;
    }
};

void insertathead(node*& n, int data) {
    node* temp = new node(data);
    if (n == NULL) {
        temp->next = temp;
        n = temp; // Setting n to point to the new node
        return;
    }
    node* head = n;
    while (head->next != n) {
        head = head->next;
    }
    head->next = temp;
    temp->next = n; // Link to new head
    n = temp;       // Update head
}

void insertattail(node*& n, int data) {
    if (n == NULL) {
        insertathead(n, data);
        return;
    }
    node* temp = new node(data);
    node* head = n;
    while (head->next != n) {
        head = head->next;
    }
    head->next = temp; // Link last node's next to new node
    temp->next = n; // New node should point to the head
}

void display(node*& n) {
    if (n == NULL) {
        cout << "NULL" << endl;
        return;
    }
    node* temp = n;
    do {
        cout << temp->value << "->";
        temp = temp->next;
    } while (temp != n);
    cout << "NULL" << endl;
}
void deleteathead(node *& n){
    node *temp=n;
    while(temp->next!=n){
          temp=temp->next;
    }
    node *todelete=n;
    temp->next=temp->next->next;
    n=n->next;
    delete todelete;
}
void deletion(node *&n,int pos){
    if(pos==1){
        deleteathead(n);
        return ;
    }
    node *temp=n;
    int c=1;
    while(c!=pos-1){
        temp=temp->next;
        c++;
    }
    node *a=temp->next;
    temp->next=temp->next->next;
    delete a;
}
int main() {
    node* temp = NULL; // Initialize temp to NULL
    insertattail(temp, 1);
    insertattail(temp, 2);
    insertattail(temp, 3);
    insertattail(temp, 4);
    insertattail(temp, 5);
    display(temp);
    insertathead(temp,0);
    display(temp);
    cout<<"After deletion "<<endl;
    deletion(temp,1);
        display(temp);
        
        

    return 0;
}
