#include <bits/stdc++.h>
using namespace std;

int main(){
	int gradearray[10]={0};
	int grade=0;
	int gradecount=0;
	
	cout<<"Please Input the grade:";
    while (cin>>grade){
        if (grade>=0&&grade<=10){
            gradearray[0]++;
        } else if(grade>10&&grade<=20){
            gradearray[1]++;
        } else if (grade>20&&grade<=30){
            gradearray[2]++;
        } else if (grade>30&&grade<=40){
            gradearray[3]++;
        } else if (grade>40&&grade<=50){
            gradearray[4]++;
        } else if (grade>50&&grade<=60){
            gradearray[5]++;
        } else if (grade>60&&grade<=70){
            gradearray[6]++;
        } else if (grade>70&&grade<=80){
            gradearray[7]++;
        } else if (grade>80&&grade<=90){
            gradearray[8]++;
        } else if (grade>90&&grade<=100){
            gradearray[9]++;
        } else {
            break;
        }

        gradecount++;
    }
    
	 
	cout<<"$$$$$  Number of Grades per Range  $$$$$"<<endl;
	cout<<" "<<endl;
	cout<<"#      0~10  11~20  21~30  31~40  41~50  51~60  61~70  71~80  81~90  91~100"<<endl;
	int i=0;
	int maxcount=0;
	string maxranges="";
	cout<<"# ";
	while(i<10){
		cout<<setw(7)<<gradearray[i];
		if (gradearray[i]>maxcount){
			maxcount=gradearray[i];
			switch(i){
				case 0:
					maxranges="0~10";
					break;
				case 1:
					maxranges="11~20";
					break;
				case 2:
					maxranges="21~30";
					break;
				case 3:
					maxranges="31~40";
					break;
				case 4:
                    maxranges="41~50";
                    break;
                case 5:
                    maxranges="51~60";
                    break;
                case 6:
                    maxranges="61~70";
                    break;
                case 7:
                    maxranges="71~80";
                    break;
                case 8:
                    maxranges="81~90";
                    break;
                case 9:
                    maxranges="91~100";
                    break;
            }
        } else if(gradearray[i]==maxcount){
            switch(i){
                case 0:
                    maxranges+=", 0~10";
                    break;
                case 1:
                    maxranges+=", 11~20";
                    break;
                case 2:
                    maxranges+=", 21~30";
                    break;
                case 3:
                    maxranges+=", 31~40";
                    break;
                case 4:
                    maxranges+=", 41~50";
                    break;
                case 5:
                    maxranges+=", 51~60";
                    break;
                case 6:
                    maxranges+=", 61~70";
                    break;
                case 7:
                    maxranges+=", 71~80";
                    break;
                case 8:
                    maxranges+=", 81~90";
                    break;
                case 9:
                    maxranges+=", 91~100";
                    break;
			}
		}
		i++;
	}
	cout<<endl;
	cout<<"# Maximum count = "<<maxcount<<endl;
	cout<<"# Range od maximum count :"<<maxranges<<endl;
	cout<<"# Grade count = "<<gradecount<<endl;
	cout<<endl;
	cout<<"$$$$$  Grade Distribution Graph  $$$$$"<<endl<<endl;
	cout<<setw(10)<<"0~10  |"<<setw(gradearray[0])<<right<<"*"<<endl;
	cout<<setw(10)<<"11~20  |"<<setw(gradearray[1])<<right<<"*"<<endl;
	cout<<setw(10)<<"21~30  |"<<setw(gradearray[2])<<right<<"*"<<endl;
	cout<<setw(10)<<"31~40  |"<<setw(gradearray[3])<<right<<"*"<<endl;
	cout<<setw(10)<<"41~50  |"<<setw(gradearray[4])<<right<<"*"<<endl;
	cout<<setw(10)<<"51~60  |"<<setw(gradearray[5])<<right<<"*"<<endl;
	cout<<setw(10)<<"61~70  |"<<setw(gradearray[6])<<right<<"*"<<endl;
	cout<<setw(10)<<"71~80  |"<<setw(gradearray[7])<<right<<"*"<<endl;
	cout<<setw(10)<<"81~90  |"<<setw(gradearray[8])<<right<<"*"<<endl;
	cout<<setw(10)<<"91~100 |"<<setw(gradearray[9])<<right<<"*"<<endl;
	cout << "vertical chart" << endl << endl;
	for(int i = maxcount; i >= 0; i--){
		for(int j = 0; j < 10; j++){
			if(gradearray[j] >= i){
				cout <<"******* ";
			}else{
				cout << "        "; 
			}
		}
		cout << endl;
		
	}
	cout << "=========================================================================================" << endl;
	cout << "  0~10   11~20   21~30   31~40   41~50   51~60   61~70   71~80   81~90   91~100" << endl;
	


	return 0;
} 
