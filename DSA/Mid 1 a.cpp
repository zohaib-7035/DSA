#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node() : data(0), next(NULL) {}

    node(int data) : data(data), next(NULL) {}
};

class list {
public:
    node* head;
    node* tail;

    list() : head(NULL), tail(NULL) {}

    list(int d) {
        head = new node(d);
        tail = head;
    }

    void insert_at_start(int d) {
        node* temp = new node(d);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert_at_end(int d) {
        node* temp = new node(d);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void reverse_the_list() {
        if (head == NULL) return;
        node* pre = NULL;
        node* curr = head;
        node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        tail = head; // Update tail
        head = pre;  // Update head
    }

    void merge_list(list& l1) {
        if (l1.head == NULL) return;
        if (head == NULL) {
            head = l1.head;
            tail = l1.tail;
        } else {
            tail->next = l1.head;
            tail = l1.tail;
        }
    }

    bool detect_cycle() {
        if (head == NULL) {
            cout << "There is no element in the linked list." << endl;
            return false;
        }
        node* slow = head;
        node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }

    void make_cycle(int pos) {
        if (head == NULL || pos < 0) {
            cout << "Unable to make the cycle." << endl;
            return;
        }
        
        node* temp = head;
        node* cycleNode = nullptr;
        int c = 0;
        while (temp != NULL) {
            if (c == pos) {
                cycleNode = temp;
            }
            temp = temp->next;
            c++;
        }
        
        if (cycleNode != nullptr) {
            temp->next = cycleNode; // Create cycle
        }
    }

    void remove_cycle() {
        if (head == NULL) return;

        node* slow = head;
        node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                node* cycleNode = slow;
                while (cycleNode->next != slow) {
                    cycleNode = cycleNode->next; // Find the last node in the cycle
                }
                cycleNode->next = NULL; // Break the cycle
                return;
            }
        }
    }

    void append_k_node(int k) {
        if (head == NULL || k <= 0) {
            cout << "I cannot do that for you." << endl;
            return;
        }

        int i = 1;
        node* t = head;
        while (t != NULL && i < k) {
            t = t->next;
            i++;
        }
        if (t != NULL && t->next != NULL) {
            node* newhead = t->next;
            node* newtail = t;
            newtail->next = NULL;
            tail->next = head;
            head = newhead;
            tail = newtail;
        }
    }

    int len() {
        int c = 0;
        node* temp = head;
        while (temp != NULL) {
            c++;
            temp = temp->next;
        }
        return c;
    }

    bool intersection(list& other) {
        if (head == NULL || other.head == NULL) return false;
        
        int l1 = len();
        int l2 = other.len();
        node* ptr1 = head;
        node* ptr2 = other.head;
        int d = abs(l1 - l2);
        
        // Advance the pointer of the longer list by d nodes
        if (l1 > l2) {
            while (d-- > 0) ptr1 = ptr1->next;
        } else {
            while (d-- > 0) ptr2 = ptr2->next;
        }

        while (ptr1 != NULL && ptr2 != NULL) {
            if (ptr1 == ptr2) return true; // They intersect
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return false; // No intersection
    }
};

node* reverse_k_nodes(node* head, int k) {
    if (head == NULL || k <= 0) return NULL;

    node* pre = NULL;
    node* curr = head;
    node* next = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
        count++;
    }

    if (next != NULL) {
        head->next = reverse_k_nodes(next, k);
    }

    return pre;
}

void reverse_k_node(list& l1, int k) {
    l1.head = reverse_k_nodes(l1.head, k);
}

int main() {
    list list1(1);
    list1.insert_at_start(0);
    list1.insert_at_end(2);
    list1.insert_at_end(3);
    list1.insert_at_end(4);
    list1.insert_at_end(5);
    cout << "The output of this list is given as: " << endl;
    list1.print();
    cout << "Length of list1: " << list1.len() << endl; // Check length
    cout << "The output after reversing the list: " << endl;
    list1.reverse_the_list();
    list1.print();

    list list2(1);
    list2.insert_at_start(0);
    list2.insert_at_end(2);
    list2.insert_at_end(3);
    list2.insert_at_end(4);
    list2.insert_at_end(5);

    list list3(7);
    list3.insert_at_end(8);
    list3.insert_at_end(9);
    list3.insert_at_end(11);
    list3.insert_at_end(12);
    list3.insert_at_end(13);

    cout << "The list after merging is given as: " << endl;
    list2.merge_list(list3);
    list2.print();

    int k = 2;
    reverse_k_node(list2, k);
    cout << "The list after reversing every " << k << " nodes is: " << endl;
    list2.print();
    
    cout << "The output of detect_cycle function is given below: " << list1.detect_cycle() << endl;

    list list5(1);
    list5.insert_at_start(0);
    list5.insert_at_end(2);
    list5.insert_at_end(3);
    list5.insert_at_end(4);
    list5.insert_at_end(5);
    cout << "List before removing the cycle: " << endl;
    
    list5.print();
    list5.make_cycle(3);
     
    cout << "The output of detect_cycle function is given below: " << list5.detect_cycle() << endl;
    cout << "After removing the cycle: " << endl;

    list5.remove_cycle();
    cout << "The output of detect_cycle function is given below: " << list5.detect_cycle() << endl;
    cout << "The output after removing the cycle is given below: " << endl;

    list5.print();
    cout << "The output to append the k position node in the list: " << endl;
    list5.append_k_node(3);
    list5.print();
    
    // Intersection test
    list a; // First linked list
    list b; // Second linked list

    // Create first linked list: 1 -> 2 -> 3
    a.insert_at_end(1);
    a.insert_at_end(2);
    a.insert_at_end(3);

    // Create second linked list: 4 -> 5
    b.insert_at_end(4);
    b.insert_at_end(5);

    node* intersectionNode = new node(6);
    intersectionNode->next = a.head->next; // 6 -> 2
    a.tail->next = intersectionNode; // 3 -> 6

    cout << "Intersection exists: " << (a.intersection(b) ? "Yes" : "No") << endl;
    
    
    
    return 0;
}
