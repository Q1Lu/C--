#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0; 
    virtual ~Shape() {} 
};

class Rectangle : public Shape {
private:
    double base;
    double height;

public:
    Rectangle(double w, double h) : base(w), height(h) {}
    double area() const override {
        return base * height;
    }
};

class IsoscelesTriangle : public Shape {
private:
    double base;
    double height;

public:
    IsoscelesTriangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height;
    }
};

int main()
{
 const Shape *myShape = new Rectangle(5, 3);

 cout << myShape->area() << '\n'; // 15
 delete myShape;
 myShape = new IsoscelesTriangle(5, 3);
 cout << myShape->area() << '\n'; // 7.5
 delete myShape;
 myShape = nullptr;

 Rectangle herShape(6, 8);
 IsoscelesTriangle hisShape(5, 4);
 const Shape &yourShape = herShape;

 cout << yourShape.area() << '\n'; // 48

 const Shape &theirShape = hisShape;
 cout << theirShape.area() << '\n'; // 10
}
