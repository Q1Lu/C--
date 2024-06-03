#include <bits/stdc++.h>
using namespace std;


int main(){

	int test_cases = 0,
		len_LFSR = 0,
		seed = 0;
			
	cout << "Number of test cases :";
	cin >> test_cases;
	for (int i = 0; i < test_cases; i++){
		cout << "Length of LFSR :";
		cin >> len_LFSR;
		cout << "Integer determines tap bits and seed :";
		cin >> seed;
		int num[len_LFSR - 1] = {0},
			position[len_LFSR - 1] = {0},
			numLFSR[len_LFSR - 1] = {0},
			j = -1,
			distance_min = 32,
			distance_max = 0,
			LFSR_count = 0,
			s0 = 0;
		for(int i = 0; i <= len_LFSR; i++){
			num[i]= seed % 2;
			numLFSR[i]= seed % 2;
			if(num[i] == 1){
				j++;
				cout << i+1 << " ";
				position[j] = i;
				
			}
			seed = seed / 2;
		}
		cout << endl;
		for(int i = 0; i < len_LFSR; i++){
			cout << num[i] ;
		}
		cout << endl;
		for(int i = 0; i < pow(2,len_LFSR) - 1 ; i++){
			//
			int sum = 0;
			for(int k = 0; k <= j; k++){
				sum = sum + num[position[k]];
			}
			if(sum % 2 == 1) {
				s0 = 1;
			}else if(sum % 2 == 0) {
				s0 = 0;
			} 
			
			for(int l = len_LFSR - 2; l >= 0; l--){
				num[l + 1] = num[l];
			} 
			num[0] = s0;
			//°µxor 
			for(int i = 0; i < len_LFSR; i++){
				cout << num[i] ;
			}
			cout << endl;
			LFSR_count++;
			int distance = 0;
			bool equal = true;
			for (int l = 0; l < len_LFSR; l++){
				if (num[l] != numLFSR [l]){
					equal = false;
					break;
				}
			}
			if(equal){
				break;
			}
			
			for(int l = 0; l < len_LFSR; l++){
				if(num[l] != numLFSR [l]){ 
					distance ++;
				} 
			} 

			if(distance < distance_min){
				distance_min = distance;
			}
			if(distance > distance_max){
				distance_max = distance;
			}
			if(i == pow(2,len_LFSR) - 2){
				LFSR_count = 0;
			}
		}
		cout << LFSR_count << " " << distance_min << " " << distance_max << endl;
	}
	return 0;
} 
