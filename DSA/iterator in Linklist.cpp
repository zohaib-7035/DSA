#include <iostream>
using namespace std;

class List {
public:
    class node {
    public:
        int data;
        node *next;
        friend class List;
        node() : data(0), next(NULL) {}
        node(int value) : data(value), next(NULL) {}
    };

    class iterator {
    public:
        node *curr;
        friend class List;
        iterator() : curr(NULL) {}
        iterator(node *head) : curr(head) {}
        
        int &operator*() {
            return curr->data;
        }
        
        iterator &operator++() {
            if (curr != NULL) {
                curr = curr->next;
            }
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            if (curr != NULL) {
                curr = curr->next;
            }
            return temp;
        }

        bool operator==(const iterator &other) const {
            return curr == other.curr;
        }

        bool operator!=(const iterator &other) const {
            return curr != other.curr;
        }
    };

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(NULL);
    }

public:
    node *head;
    node *tail;

    List() : head(NULL), tail(NULL) {}

    List(int data) {
        node *temp = new node(data);
        head = temp;
        tail = temp;
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        for (iterator i = begin(); i != end(); ++i) {
            cout << *i << " ";
        }
        cout << endl;
    }

    void insert_at_end(int value) {
        node *t = new node(value);
        if (head == NULL) {
            head = t;
            tail = t;
        } else {
            node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = t;
            tail = t;
        }
    }
};

int main() {
    List myList;

    myList.insert_at_end(1);
    myList.insert_at_end(2);
    myList.insert_at_end(3);

    
    cout << "List contents: ";
    myList.print();  

   
    cout << "Using iterator to print list: ";
    for (List::iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

   
    List emptyList;
    cout << "Empty list contents: ";
    emptyList.print();  

    return 0;
}
