#include <bits/stdc++.h>
using namespace std;

class MyClass {
public:
    
    MyClass() {
        cout << "Constructor called" << endl;
    }
    ~MyClass() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    MyClass obj; 

    return 0;
}