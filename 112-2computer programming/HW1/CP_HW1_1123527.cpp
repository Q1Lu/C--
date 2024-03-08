#include <iostream>
using namespace std;

class Dessert{
    protected:
        int weight = 0;
    public:
        Dessert(){
            weight = 100;
        };

        int getWeight()const{
            return weight;
        };
        virtual void eat(){
            weight = weight -20;
//          weight -= 20  
        };
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
 Dessert *d;
 int choice;
 while ( cin >> choice )
 {
    switch ( choice )
    {
        case 1:
            d = new Dessert();
            break;
        case 2:
            d = new Suncake();
            break;
        default:
            exit( 1 );
    }

 cout << "The initial weight is " << d->getWeight() << '\n';
 d->eat();
 cout << "The remaining weight is " << d->getWeight() << "\n\n";
 delete d;
 }
 const Dessert *ptr = new Dessert;
 ptr->getWeight();
 delete ptr;
}
