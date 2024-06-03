#include <iostream>
#include <cassert>
using namespace std;

void foo (int *x, int *y, int *z, int i){
    *z = i%2;
    i = i/2;
    *y = i%2;
    i = i/2;
    *x = i%2;
}

int main()
{
 int x;
 int y;
 int z;
 for ( int i = 0; i < 8; ++i )
 {
 foo( &x, &y, &z, i );
 assert( x >= 0 && x <= 1 && y >= 0 && y <= 1 && z >= 0 && z <= 1 );
 assert( z + y * 2 + x * 4 == i );
 }
 cout << "yes" << endl; // yes
}
