#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string input = "";
	int WordsCount = 0,
		VowelCount = 0,
		RepeatCount = 0,
		Wordslen[16] = {0},
		FirstLetter[26] = {0};
	
	while(cin >> input){
		for(int i = 0; i < input.length(); i++){
			if(isalpha(input[i])){
				WordsCount++;
				if(input[i] == 'A'|| input[i] == 'E'|| input[i] == 'I'|| input[i] == 'O'|| input[i] == 'U'|| input[i] == 'a'|| input[i] == 'e'|| input[i] == 'i'|| input[i] == 'o'|| input[i] == 'u'){
					VowelCount++;
				}   
				break;
			}
		}
		int repeat2 = 0, 
			repeatover2 = 0,
			RepeatLetter[26] = {0},
			lencount = 0,
			i = 0;
		for(int i = 0; i < input.length(); i++){
			if(isalpha(input[i])){
				int index = toupper(input[i]) - 65;
				RepeatLetter[index]++;
			}
		}
		for(int i = 0; i < 26; i++){
			if(RepeatLetter[i] == 2){
				repeat2 = 1;
			}else if (RepeatLetter[i] > 2){
				repeatover2 = 1;
			}
		}
		if(repeat2 == 1 && repeatover2 == 0){
			RepeatCount++;
		}
		for(int i = 0;i < input.length(); i++){
			if(isalpha(input[i]) && lencount < 15){
				lencount++;
			}
		}
		Wordslen[lencount]++;
		for(int i = 0; i < input.length(); i++){
			if(isalpha(input[i])){
				FirstLetter[toupper(input[i]) - 65]++;
				break;
			}
		} 
	}
	cout << "# Total number of words, each of which has at least a letter: " << WordsCount << endl << "# Total number of words whose first letter is a vowel: " << VowelCount << endl << "# Total number of words containing same letter repeated twice but no letter repeated more than twice : " << RepeatCount << endl<< "# Distribution of words by word length :" << endl;
	for(int i =0; i <= 15; i++){
		cout << "# L" << i << " =  " << Wordslen[i] << endl;
	}
	cout <<"# Distribution of words by the first letter:" << endl;
	for(int i = 0; i < 26 ;i++){
		cout << "# " << char(i+65) << "/" << char(i+97) << ": " << FirstLetter[i]  << endl;
	}
	
	return 0;
}
