#include <bits/stdc++.h>
using namespace std;

int main(){
	int lines=0;
	cin >> lines;
	string str;
	
	for(int i=0; i < lines; i++){
		int runscount = 0, lenlongestrun = 0, lenlongestrun_temp = 0, longestrunscount = 0;
		cin >> str;
		int strlen = str.length();
		
		for(int j = 0; j < strlen; j++){
			if((int)str[j] >= 65 && (int)str[j] <= 90){
				str[j] = str[j]+32;
			}
		}
		lenlongestrun_temp = 1, longestrunscount = 1;
		for(int j = 0; j < strlen; j++){
			
			if((int)str[j] <= (int)str[j+1]){
				lenlongestrun_temp++;
			}else if ((int)str[j] > (int)str[j+1]){
				runscount++;
				if (lenlongestrun_temp > lenlongestrun){
					lenlongestrun = lenlongestrun_temp;
					longestrunscount = 1;
				}else if(lenlongestrun_temp == lenlongestrun){
					longestrunscount++;	
				}
			lenlongestrun_temp = 1; 
			}
		}
		cout << runscount << " " << lenlongestrun << " " << longestrunscount << endl;
	}
	return 0;
}
