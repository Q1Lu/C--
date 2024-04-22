#include <iostream>
using namespace std;

class Dessert {
private:
    int weight;
public:
    Dessert() : weight(100) {}
    virtual void eat() { weight -= 20; }
    int getWeight() const { return weight; }
    virtual ~Dessert() {}
};

class Suncake : public Dessert {
public:
    void eat() override {
        cout << "Adding milk..." << endl;
        Dessert::eat();
    }
};

int main()
{
    Dessert* d;
    int choice;
    while (cin >> choice)
    {
        switch (choice)
        {
        case 1:
            d = new Dessert();
            break;
        case 2:
            d = new Suncake();
            break;
        default:
            exit(1);
        }

        cout << "The initial weight is " << d->getWeight() << '\n';
        d->eat();
        cout << "The remaining weight is " << d->getWeight() << "\n\n";
        delete d;
    }
    const Dessert* ptr = new Dessert;
    ptr->getWeight();
    delete ptr;
}