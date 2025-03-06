#include<iostream>
using namespace std;

template <class T>
class list
{
private:
    class node
    {
    public:
        T data;
        node* next;
        node() {
            data = 0;
            next = NULL;
        }
        node(T d, node* n = 0) {
            data = d;
            next = n; // Correctly using the passed value for the next pointer
        }
    };

    node* head;
    node* tail;
    int size;

public:
    list() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~list() {
        // Destructor logic if needed
    }

    void insertAtStart(T const element) {
        node* temp = new node(element);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAtEnd(T const ele) {
        node* temp = new node(ele);
        if (head == NULL && tail == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void print() const {
        if (head == NULL) {
            return;
        }
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool search(T const& ele) const {
        if (head == NULL) {
            return false;
        }
        node* temp = head;
        while (temp != NULL) {
            if (temp->data == ele) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool is_empty() const {
        return size == 0;
    }

    void deleteStart() {
        if (head == NULL) {
            return;
        }
        node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
        size--;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            return;
        }
        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        } else {
            node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
        }
        size--;
    }

    void insertAfter(T const v1, T const v2) {
        if (head == NULL) {
            return;
        }
        node* temp = head;
        while (temp->data != v1 && temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->data == v1) {
            node* newNode = new node(v2, temp->next);
            temp->next = newNode;
            if (temp == tail) {
                tail = newNode;
            }
        } else {
            cout << "Element " << v1 << " not found in the list" << endl;
        }
    }

    void deleteAll(T const v) {
        if (head == NULL) {
            return;
        }
        while (head != NULL && head->data == v) {
            node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
        node* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->data == v) {
                node* toDelete = temp->next;
                temp->next = temp->next->next;
                if (toDelete == tail) {
                    tail = temp;
                }
                delete toDelete;
                size--;
            } else {
                temp = temp->next;
            }
        }
    }

    bool isSorted() const {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        node* temp = head;
        while (temp->next != NULL) {
            if (temp->data > temp->next->data) {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }

    void removeDuplicate() {
        if (head == NULL) {
            return;
        }

        node* temp1 = head;
        while (temp1 != NULL && temp1->next != NULL) {
            node* temp2 = temp1;
            while (temp2->next != NULL) {
                if (temp2->next->data == temp1->data) {
                    node* temp3 = temp2->next;
                    temp2->next = temp2->next->next;
                    delete temp3;
                    size--;
                } else {
                    temp2 = temp2->next;
                }
            }
            temp1 = temp1->next;
        }
    }
    
    
     void mergeList(list<T>& otherList) {
        if (otherList.head == NULL) {  
            return;
        }
        if (this->head == NULL) { 
            this->head = otherList.head;
            this->tail = otherList.tail;
        } else {
            this->tail->next = otherList.head;
            this->tail = otherList.tail;
        }
        this->size += otherList.size; 
        otherList.head = otherList.tail = NULL; 
        otherList.size = 0;
    }
};

int main()
{
    list<int> l1;
    cout << "List after the insertion is given below " << endl;

    l1.insertAtStart(3);
    l1.insertAtStart(2);
    l1.insertAtStart(1);
    l1.insertAtStart(0);
    l1.insertAtEnd(4);
    l1.insertAtEnd(5);
    l1.print();

    cout << "Output of the search function is " << endl;
    if (l1.search(5)) {
        cout << "Found " << endl;
    } else {
        cout << "Not found " << endl;
    }

    cout << "Output to check the emptiness of the list" << endl;
    if (l1.is_empty()) {
        cout << "It is empty " << endl;
    } else {
        cout << "It is not empty " << endl;
    }

    cout << "The output for deleting at start is " << endl;
    l1.deleteStart();
    l1.print();

    cout << "Output after deleting the head node is " << endl;
    l1.deleteAtEnd();
    l1.print();

    cout << "Inserting after some digit " << endl;
    l1.insertAfter(4, 5);
    l1.print();

    cout << "Output for the deletion of a particular node is " << endl;
    l1.deleteAll(5);
    l1.print();

    cout << "After inserting 5 at the end " << endl;
    l1.insertAtEnd(5);
    l1.print();

    cout << "Is it sorted???" << endl;
    if (l1.isSorted()) {
        cout << "It is a sorted list " << endl;
    } else {
        cout << "It is not a sorted list " << endl;
    }

    l1.insertAtEnd(4);
    l1.removeDuplicate();
    cout << "List after removing the duplicate is given below " << endl;
    l1.print();
     list<int> o1;
    cout << "List o1 after the insertion is given below " << endl;
    o1.insertAtStart(3);
    o1.insertAtStart(2);
    o1.insertAtStart(1);
    o1.print();

    list<int> o2;
    cout << "List o2 after the insertion is given below " << endl;
    o2.insertAtStart(6);
    o2.insertAtStart(5);
    o2.insertAtStart(4);
    o2.print();

    cout << "Merging List o1 and List o2 " << endl;
    o1.mergeList(o2); 
    o1.print();
    return 0;
}
