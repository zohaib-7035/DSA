#include<iostream>
using namespace std;
class node {
public:
	int value;
	node * next;
	node() {
		value=0;
		next=0;
	}
	node(int v) {
		value=v;
		next=NULL;
	}
};
void insertathead(node *& n,int val) {
	node * temp=new node(val);
	temp->next=n;
	n=temp;//This line updated the pointer pointing to the new node
}
void insertatmiddle(node * & a,int pos,int d) {
	if(pos==1) {
		insertathead(a,d);
		return ;
	}
	else {
		int c=1;
		node *temp=new node(d);
		node * b=a;
		while(c!=pos-1 && b != nullptr) {
			b=b->next;
			c++;
		}
		temp->next=b->next;
		b->next=temp;
	}
}
void insertattail(node * & a,int data) {
	node *head =new node(data);
	if(a==NULL) {
		a=head;
	}
	else
	{
		node * b=a;
		while(b->next!=0) {
			b=b->next;
		}
		b->next=head;
	}
}


void display(node *&n) {
	node *temp=n;
	while(temp != NULL) {
		cout<<temp->value<<endl;
		temp=temp->next;
	}

}
bool search(node * & n,int key) {
	node * a=n;
	while(a!=0) {
		if(a->value==key) {
			return true;
		}
		a=a->next;
	}
	return false;
}
void deleteathead(node * &n) {
	node * todelete=n;
	n=n->next;
	delete todelete;
}
void deletenode(node * & n,int d) {
	if(n==NULL) {
		cout<<"NO node is present here "<<endl;
		return ;
	}
	if(n->next==NULL) {
		deleteathead(n);
		return ;
	}
	node * temp=n;
	while(temp->next->value!=d) {
		temp=temp->next;
	}
	node *a=temp->next;
	temp->next=temp->next->next;
	delete a;

}
node * reverseLL(node * head) {
	node *pre=NULL;
	node *curr=head;
	node *Next=NULL;
	while(curr!=NULL) {
		Next=curr->next;
		curr->next=pre;
		pre=curr;
		curr=Next;
	}
	return pre;
}
node *reverseKnode(node *& n,int k) {
	node * pre=NULL;
	node *curr=n;
	node *next;
	int c=0;
	while(curr!=NULL && c<k) {
		next=curr->next;
		curr->next=pre;
		pre=curr;
		curr=next;
		c++;
	}
	if(next!=NULL) {
		n->next=reverseKnode(next,k);
	}
	return pre;
}
bool detectcycle(node * head) {
	node *slow=head;
	node *fast=head;
	while(fast!=NULL && fast->next!=NULL) {
		fast=fast->next->next;
		slow=slow->next;
		if(fast->next==slow->next) {
			return true;
		}
	}
	return false;
}
void makecycle(node *head,int pos) {
	node *temp=head;
	node *startnode;
	int c=1;
	while(temp->next!=NULL) {
		if(c==pos) {
			startnode=temp;
		}
		temp=temp->next;
		c++;
	}
	temp->next=startnode;
}
void removecylce(node * head) {
	node *fast=head;
	node *slow=head;
	while(slow!=fast) {
		slow=slow->next;
		fast=fast->next->next;
	}
	fast=head;
	while(slow->next!=fast->next) {
		fast=fast->next;
		slow=slow->next;
	}
	slow->next=NULL;
}
int length(node * n) {
	int l=0;
	node *head=n;
	while(head!=0) {
		l++;
		head=head->next;
	}
	return l;
}
node * appendknode(node * &head,int k) {
	node *newtail;
	node *newhead;
	node *temp=head;
	int c=1;
	int l=length(head);
	k=k%l;
	while(temp->next!=NULL) {
		if(c==l-k) {
			newtail=temp;
		}
		if(c==l-k+1) {
			newhead=temp;
		}
		temp=temp->next;
		c++;
	}
	newtail->next=NULL;
	temp->next=head;
	head=newhead;
	return newhead;
}
int getIntersectionNode(node *a,node *b) {
	node *head1;
	node *head2;
	int l1=length(a);
	int l2=length(b);
	int d=0;
	if(l1>l2) {
		d=l1-l2;
		head1=a;
		head2=b;
	}
	else {
		d=l2-l1;
		head1=b;
		head2=a;
	}
	while(d) {
		if(head1==NULL) {
			return -1;
		}
		head1=head1->next;
		d--;
	}
	while(head1!=NULL && head2!=NULL) {
		if(head1==head2) {
			return head1->value;
		}
		head1=head1->next;
		head2=head2->next;
	}
	return -1;
}
node *mergelinklist(node *a,node *b) {
	node *head1=a;
	node *head2=b;
	node *dummy=new node(-1);
	node *head3=dummy;
	while(head1!=NULL && head2!=NULL) {
		if(head1->value <head2->value ) {
			head3->next=head1;
        head1=head1->next;

		}
		else {
			head3->next=head2;
			head2=head2->next;
		}
		head3=head3->next;
        
	}
	if(head1==NULL){
	head3->next=head2;
	}
	else{
	    head3->next=head1;
	}
	return dummy->next;//the reason why we return the dummy->next instead of the head3->next is that head3 is 
	// at last of the link list
}

int main() {
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
	cout<<"The cycle detection after removing the cycle is given as "<<detectcycle(t)<<endl<<endl<<endl;


	node *l=new node(1);
	insertattail(l,2);
	insertattail(l,3);
	insertattail(l,4);
	insertattail(l,5);
	insertattail(l,6);
	appendknode(l,3);
	cout<<"The output for the append of k node "<<endl;
	display(l);




	node* headA = nullptr;
	node* headB = nullptr;

	// Creating first linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
	insertattail(headA, 1);
	insertattail(headA, 2);
	insertattail(headA, 3);
	insertattail(headA, 4);
	insertattail(headA, 5);

	// Creating second linked list: 9 -> 4 -> 5 -> NULL
	// Manually creating intersection
	headB = new node(9);
	headB->next = headA->next->next->next; // 4 -> 5

	// Display the lists
	cout << "List A: "<<endl;
	display(headA);
	cout << "List B: "<<endl;
	display(headB);

	// Find and display the intersection
	int a = getIntersectionNode(headA, headB);
	cout<<"intersection with the node with the value "<<a<<endl;




    node* HeadA = nullptr;
    node* HeadB = nullptr;

    // Creating first linked list: 1 -> 2 -> 3 -> NULL
    insertattail(HeadA, 1);
    insertattail(HeadA, 2);
    insertattail(HeadA, 3);

    // Creating second linked list: 4 -> 5 -> 6 -> NULL
    insertattail(HeadB, 4);
    insertattail(HeadB, 5);
    insertattail(HeadB, 6);

    cout << "List A: " << endl;
    display(HeadA);
    cout << "List B: " << endl;
    display(HeadB);

    // Merging the two lists
    node* merged = mergelinklist(HeadA, HeadB);
    cout << "Merged List: " << endl;
    display(merged);

    return 0;


}