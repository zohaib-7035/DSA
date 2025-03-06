#include<iostream>
#include<string>
#include<climits>
#include<vector>
using namespace std;
class node {
public:
	int key;
	int value;
	node * next;

	node(int k,int v) {
		key=k;
		value=v;
		next=NULL;
	}


};

class Htable {
private:
	vector<node *> table;
	int size;

	int hashfunc(int key) {
		return (key % size);
	}

public:

	Htable(int s) {
		size=s;
		table.resize(size,NULL);
	}

	void insert(int k,int v) {
		int index=hashfunc(k);

		node * temp=new node(k,v);

		if(table[index]==NULL) {
			table[index]=temp;
		}
		else {

			node *t=table[index];

			while(t->next != NULL) {
				if(t->key==k) {
					t->value=v;
					return;
				}
				t=t->next;
			}
			if(t->key==k) {
				t->value=v;
			}
			else {
				t->next=temp;
			}
		}


	}

	int get(int k) {
		int index = hashfunc(k);

	
			node * temp=table[index];
			while(temp != NULL) {

				if(temp->key==k) {
					return temp->value;
				}

				temp=temp->next;
			}
			return -1;
		
	}


	void display() {
		for(int i =0; i<size; i++) {
			cout<<"...Bucket... "<<endl;
			node * temp=table[i];
			while(temp != NULL) {
				cout<<"( "<<temp->key<<" "<<temp->value<<" ) ->";
				temp=temp->next;

			}
			cout<<"NULL"<<endl;
		}
	}
	
	void remove(int k){
	   
	  int index=hashfunc(k);
	  node * temp=table[index];
	  
	  if(temp==NULL){
	      return ;
	  }
	  
	  
	  else if(temp->key == k) {
	      node *t=table[index];
	      table[index]=temp->next;
	      delete t;
	      return;
	  }
	  
	  else{
	      while(temp != NULL and temp->next != NULL){
	          if(temp->next->key==k ){
	              node *t=temp->next;
	              temp->next=t->next;
	              delete t;
	              return;
	          }
	          temp=temp->next;
	      }
	  }
	  
	}

};


int main() {


Htable h(7);  

    h.insert(1, 10);
    h.insert(2, 20);
    h.insert(3, 30);
    h.insert(10, 100);
    h.insert(17, 170);  

    h.display();

    cout << "Value for key 10: " << h.get(10) << endl;
    cout << "Value for key 17: " << h.get(17) << endl;

    h.remove(10);
    cout << "After removing key 10:" << endl;
    h.display();

	return 0;
}