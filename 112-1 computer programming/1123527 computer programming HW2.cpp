#include <iostream>
using namespace std;

int solve(int n){
	int	num_temp = 0,
		mod_temp = 0,
		i_temp = 0,
		coprimeCount = 0;
	for (int i = 1; i < n; i++){
		i_temp = i;
		num_temp = n;
		while(i_temp != 0){	
			mod_temp = i_temp;
			i_temp = num_temp % i_temp;
			num_temp = mod_temp;	
		}
		if(mod_temp == 1){
			coprimeCount++;
		}
	}
	return coprimeCount;
}
int main(){
	int num = 0;
	cin >> num;

	cout << solve(num) << endl;
} 
