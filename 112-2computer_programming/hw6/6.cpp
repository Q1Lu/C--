#include <iostream>
#include <cassert>
using namespace std;

class Dessert
{
private:
    int weight;

public:
    Dessert() : weight(100) {}
    ~Dessert() { cout << "Dessert destructor\n"; }
    int getWeight() const { return weight; }
    void eat()
    {
        cout << "Eating...\n";
        weight = (weight >= 20 ? weight - 20 : 0);
    }
};

class Pen
{
public:
    ~Pen() { cout << "Pen destructor\n"; }
    void write() { cout << "Writing...\n"; }
};

template <typename T>
class MySmartPointer
{
private:
    T *ptr;

public:
    MySmartPointer(T *p) : ptr(p) {}
    ~MySmartPointer() { delete ptr; }
    T *operator->() { return ptr; }
};

int main()
{
    MySmartPointer<Dessert> myMealPtr(new Dessert);
    MySmartPointer<Pen> myPenPtr(new Pen);
    char choice;

    while (cin >> choice)
    {
        switch (choice)
        {
        case '1':
            myMealPtr->eat();
            assert(myMealPtr->getWeight() != 100);
            break;
        case '2':
            myPenPtr->write();
            break;
        case '3':
            // Destructors of Dessert and Pen will be called automatically when the program exits.
            return 0;
        default:
            return 0;
        }
    }
}