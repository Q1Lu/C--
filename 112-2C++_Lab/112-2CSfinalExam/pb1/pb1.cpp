#include <iostream>
using namespace std;

class Base1{
    public:
        void displayBase1(){
            cout << "Base class1 method" << endl;
        }
};

class Base2{
    public:
        void displayBase2(){
            cout << "Base class2 method" << endl;
        }
};

class Derived:public Base1, public Base2{
    public:    
        void displayDerived(){
            cout << "Derived class method" << endl;
        }
};

int main (){
    Derived derived;
    derived.displayBase1();
    derived.displayBase2();
    derived.displayDerived();
    return 0;
}