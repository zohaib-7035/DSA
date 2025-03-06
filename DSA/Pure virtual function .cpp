#include <iostream>

// Abstract base class with a pure virtual function
class Shape {
public:
    // Pure virtual function
    virtual void draw() const = 0;
};

// Derived class implementing the pure virtual function
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

// Another derived class implementing the pure virtual function
class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a rectangle" << std::endl;
    }
};

int main() {
    Circle circle;
    Rectangle rectangle;

    // Using polymorphism to call the draw() function for different shapes
    Shape* shapePtr = nullptr;

    shapePtr = &circle;
    shapePtr->draw(); // Output: Drawing a circle

    shapePtr = &rectangle;
    shapePtr->draw(); // Output: Drawing a rectangle

    return 0;
}
