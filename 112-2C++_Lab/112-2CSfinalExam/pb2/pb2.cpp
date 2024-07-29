#include <iostream>
using namespace std;

class Animal{
    public:
        void sound(){
            cout << "Animal sound" << endl;
        }
};

class Dog:public Animal{
    public:
        void bark(){
            cout << "Dog barks" << endl;
        }
};

class Cat:public Animal{
    public:
        void meow(){
            cout << "Cave meows" << endl;
        }
};

int main(){
    Dog dog;
    Cat cat;
    dog.sound();
    dog.bark();
    cat.sound();
    cat.meow();
    return 0;
}