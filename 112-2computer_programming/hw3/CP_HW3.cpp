#include <iostream>

using namespace std;

class Martian
{
    private:
        static int population;
        int acount = 0;


    public:
        Martian() { ++population; }
        ~Martian() { --population; }

        Martian &attack()
        {
            if( population >= 3 ){
                cout << "Bravely attacking!"<<endl;
                acount++;
            }
            else
                cout << "Running for my life!"<<endl;
            return *this;

        }
        static int getCount()
        {
            return population;
        }
        int timesBravelyAttacked()
        {
            return acount;
        }


};

int Martian::population;

int main()
{
    Martian a;

    ( new Martian )->attack(); // Running for my life!
    cout << Martian::getCount() << ' '; // 2

    {
        Martian b;
        cout << a.timesBravelyAttacked() << ' '; // 0
        a.attack(); // Bravely attacking!
        cout << a.timesBravelyAttacked() << ' '; // 1
        a.attack().attack(); // Bravely attacking! Bravely attacking!
        cout << a.timesBravelyAttacked() << ' '; // 3
        cout << Martian::getCount() << ' '; // 3
    }

    a.attack(); // Running for my life!
    cout << a.timesBravelyAttacked() << ' '; // 3
    cout << Martian::getCount() << ' '; // 2

    Martian c;

    a.attack(); // Bravely attacking!
    cout << a.timesBravelyAttacked() << ' '; // 4
    cout << Martian::getCount() << ' '; // 3
    cout << c.timesBravelyAttacked() << endl; // 0
}
