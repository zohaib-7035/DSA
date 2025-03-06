/*Write a program that has an abstract base class named Quad. This class should have four
member data variables (floats) representing side lenghts and a pure virtual function Area.
It should also have a method for setting the data variables. Derive a class Rectangle from
Quad and override the Area method so that it returns the area of the Rectangle. Write a
main function that creates a Rectangle and sets the side lengths. Also write a top-level
function that will take a parameter of type Quad and return the value of the appropriate
Area function.*/
/*
#include <iostream>

// Abstract base class
class Quad {
protected:
    float side1, side2, side3, side4;

public:
    // Pure virtual function for calculating area
    virtual float Area() const = 0;

    // Method for setting side lengths
    void setSides(float s1, float s2, float s3, float s4) {
        side1 = s1;
        side2 = s2;
        side3 = s3;
        side4 = s4;
    }
};

// Derived class: Rectangle
class Rectangle : public Quad {
public:
    // Override the Area() method for Rectangle
    float Area() const override {
        return side1 * side2;
    }
};

// Function to calculate area for any Quad object
float calculateArea(const Quad& q) {
    return q.Area();
}

int main() {
    Rectangle rect;

    // Setting side lengths for the rectangle
    rect.setSides(4.5f, 6.7f, 4.5f, 6.7f);

    // Calculating and printing the area of the rectangle
    std::cout << "Area of the rectangle: " << rect.Area() << std::endl;
    
    
    
    
    
  //Quad a;
  //calculateArea(a);
  /*In the provided code, when you create an object `a` of type `Quad` and pass it to the `calculateArea()` function, it's causing undefined behavior. This is because `Quad` is an abstract base class, and you cannot create objects of abstract classes directly. 

To avoid this issue, you should not attempt to create objects of abstract classes. Instead, you should create objects of concrete derived classes like `Rectangle`.
  
  */
  
    // Using the top-level function to calculate area
  /*
    std::cout << "Area using top-level function: " << calculateArea(rect) << std::endl;

    return 0;
}
*/

/*

#include<iostream>
using namespace std;
class parent {
  private:
  float a,b,c;
  public:
  void operator()(float x,float y,float z){
      a=x;
      b=y;
      c=z;
      
  }
  friend ostream & operator<<(ostream & os,parent & i){
      os<<i.a<<"  "<<i.b<<"   "<<i.c<<"   "<<endl;
      return os;
  }
  parent operator++(int ){
      ++a;
      ++b;
      ++c;
      return *this;
  }
   parent & operator=(parent & i){
      a=i.a;
      b=i.b;
      c=i.c;
      return *this;
  }
  parent & operator+(float i){
      a+=i;
      b+=i;
      c+=i;
      return *this;
  }
  float getter1(){
     return a;
  }
  float getter2(){
     return b;
  }
  float getter3(){
     return c;
  }
  void setter(float x,float y,float z){
      a=x;
      b=y;
      c=z;
  }
   parent(float x,float y,float z){
      a=x;
      b=y;
      c=z;
  }
  parent(){
      a=0;
      b=0;
      c=0;
  }
  void print(){
      cout<<a<<"  "<<b<<"   "<<c<<"   "<<endl;
  }
};
int main(){
    parent a(1.2 , 2.2,3.2);
    a.setter(1.4,4.5,5.6);
    a.print();
    cout<<"The value of the a :  "<<a.getter1()<<endl;
    parent b;
    b=b+2.2;
    b.print();
    b++;
    b.print();
    cout<<b;
    b(9.9,9.9,9.9);
    cout<<b<<endl;
    return 0;
}


*/
/*
#include<iostream>
class A{
public:
A(){}
virtual int output() = 0;
private:
int i;
};
class B: public A{
private:
int j;
};
class C{
public:
int f(int a){return x*a;}
protected:
void setX(int a){x=a;}
int getX(){return x;}

private:
int x;
};

class D: public C{
private:
int z;
};
int main(){
//A objA;
//B objB;
C objC;
D objD;
//C.setX(2);
//cout<<C.getX();
//D.setX(1);
//D.f(3);
return 0;
}


*/

/*
#include<iostream>

using namespace std;

class A {
public:
    int f() { return 1; }
    virtual int g() { return 2; }
};

class B : public A {
public:
    int f() { return 3; }
    virtual int g() { return 4; }
};

class C : public A {
public:
    virtual int g() { return 5; }
};

int main() {
    A *pa;
    A a;
    B b;
    C c;
    pa = &a;
    cout << pa->f() << endl;
    cout << pa->g() << endl;
    pa = &b;
    cout << pa->f() + pa->g() << endl;
    pa = &c;
    cout << pa->f() << endl;
    cout << pa->g() << endl;
    return 0;
}

*/
/*
#include <iostream>

class PopulationCounter {
private:
    static int numLiving; // Static member to track total number of living objects
    static int numBorn;   // Static member to track total number of born objects

public:
    PopulationCounter() {
        ++numLiving; // Increment total living objects when an object is constructed
        ++numBorn;   // Increment total born objects when an object is constructed
    }

    ~PopulationCounter() {
        --numLiving; // Decrement total living objects when an object is destructed
    }

    static int getNumBorn() {
        return numBorn;
    }

    static int getNumLiving() {
        return numLiving;
    }
};

// Initialize static members
int PopulationCounter::numLiving = 0;
int PopulationCounter::numBorn = 0;

int main() {
    PopulationCounter obj1;
    PopulationCounter obj2;

    std::cout << "Number of objects born: " << PopulationCounter::getNumBorn() << std::endl;
    std::cout << "Number of objects living: " << PopulationCounter::getNumLiving() << std::endl;

    {
        PopulationCounter obj3;
        std::cout << "Number of objects born: " << PopulationCounter::getNumBorn() << std::endl;
        std::cout << "Number of objects living: " << PopulationCounter::getNumLiving() << std::endl;
    } // obj3 is destructed here

    std::cout << "Number of objects born: " << PopulationCounter::getNumBorn() << std::endl;
    std::cout << "Number of objects living: " << PopulationCounter::getNumLiving() << std::endl;

    return 0;
}
*/

/*
#include <iostream>

template <typename T1, typename T2>
class Point {
private:
    T1 x;
    T2 y;

public:
    Point(T1 x_val, T2 y_val) : x(x_val), y(y_val) {}

    void display() {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

    void set(T1 new_x, T2 new_y) {
        x = new_x;
        y = new_y;
    }

    void swap() {
        T1 temp = x;
        x = static_cast<T1>(y);
        y = static_cast<T2>(temp);
    }
};

int main() {
    Point<int, double> point1(3, 4.5);
    std::cout << "Initial Point: ";
    point1.display();

    point1.set(5, 6.7);
    std::cout << "After setting new values: ";
    point1.display();

    point1.swap();
    std::cout << "After swapping values: ";
    point1.display();

    return 0;
}
*/






