#include <iostream>
using namespace std;

int& sum(int& c, int a, int b){
	c = a+b;
	return c;
}
int main()
{
 int x;
 int y;
 int z;
 cin >> x >> y;
 cout << sum( z, x, y ) << endl;
 cout << z << endl;
 sum( z, x, y ) += 7;
 cout << z << endl;
}

