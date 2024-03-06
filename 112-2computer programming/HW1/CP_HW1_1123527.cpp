#include <iostream>
using namespace std;

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
