#include <iostream>
using namespace std;

// Base class A
class A {
public:
    void display_A() {
        cout << "Class A" << endl;
    }
};

// Base class B
class B {
public:
    void display_B() {
        cout << "Class B" << endl;
    }
};

// Derived class C inheriting from A and B
class C : public A, public B {
public:
    void display_C() {
        cout << "Class C" << endl;
    }
};

// Derived class D inheriting from C
class D : public C {
public:
    void display_D() {
        cout << "Class D" << endl;
    }
};

int main() {
    D obj_d;
    obj_d.display_A(); // Accessing method from class A
    obj_d.display_B(); // Accessing method from class B
    obj_d.display_C(); // Accessing method from class C
    obj_d.display_D(); // Accessing method from class D
    return 0;
}
