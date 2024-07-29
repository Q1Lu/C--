#include <bits/stdc++.h>
using namespace std;

long long rd(long long a, long long b, long long c){
	if(b == 0){
		return 1;
	}
	if(b == 1){
		return a%c;
	}
	long long half = rd(a,b/2,c);
	long long result = (half * half)%c;
	
	if(b%2 == 1){
		result = (result*(a%c))%c;
	}
	return result;
}
int main (){
	long long a,
		b,
		c;
	while(cin >> a && a != -1){
		cin >> b >> c;
		cout << rd(a, b, c) << endl;
	}
}
