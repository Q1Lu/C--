#include <bits/stdc++.h>
using namespace std;

int main(){
	int test_cases = 0,
		len_LFSR = 0,
		seed = 0;
	
	cin >> len_LFSR;
	cin >> seed;		

	int num[len_LFSR - 1] = {0},
		position[len_LFSR - 1] = {0},
		numLFSR[len_LFSR - 1] = {0},
		j = -1,
		distance_min = 32,
		distance_max = 0,
		LFSR_count = 0,
		s0 = 0;
		
		cin >> len_LFSR;
		cin >> seed;
		
		for(int i = 0; i < len_LFSR; i++){
			num[i]= seed % 2;
			numLFSR[i]= seed % 2;
			seed = seed / 2;
			if(num[i] == 1){
				j++;
				cout << i+1 << " ";
				position[j] = i;
				
			}
			cout << i << endl;
			cout << num[i] << endl; 
			cout << seed << endl;
		}
		cout << endl;
		for(int i = 0; i < len_LFSR; i++){
			cout << num[i] ;
		}
	
	return 0;
}
