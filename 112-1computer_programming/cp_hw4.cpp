#include <iostream>
#include <cassert>
using namespace std;

void foo (int array[], int arraylength, int input,const int notChange[], int notChangelength){
	for(int i = 0; i < arraylength; i++){
		array[i] = input%3;
		input = input/3;
	}
	for(int i = 0; i < arraylength; i++){
    	if(array[i] == 0){
        	array[i] = notChange[i];
        }
	}
}
int main()
{
 const int LENGTH = 10;
 int ternary[ LENGTH ] = {};
 const int noChange[ LENGTH ] = {};
 int n;
 cin >> n;
 foo( ternary, LENGTH, n, noChange, LENGTH );
 
 for ( int i = 0; i < LENGTH; ++i ){
 	assert( ternary[ i ] >= 0 && ternary[ i ] <= 2 );
 }
 assert( ternary[ 0 ] * 1 + ternary[ 1 ] * 3 + ternary[ 2 ] * 9 == n );
 cout << "yes\n"; // yes
}


