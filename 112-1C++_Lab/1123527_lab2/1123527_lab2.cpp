#include <bits/stdc++.h>
using namespace std;

 
int main(){
	double weight,height;
	double bmi;
	bool testing=true;
	double bmi10h,bmi10w,bmi45h,bmi45w;
	double bmi18w,bmi25w;
	string bmilevel;
		
		while(testing){
			cout<<"Input weight (kg):";
			cin>>weight;
			cout<<"Input height (m):";
			cin>>height;
			
			bmi=round (weight/(height*height) *10)/10.0;
			
			if(weight==0&&height==0){
				break;
			}
			else if(weight<20||weight>200){
				cout<<"# Invalid weight (>= 20kg and <= 200kg)" << endl;
				continue;
    		}
			else if (height<0.9||height>2.5){
        		cout<<"# Invalid height (>= 0.9m and <= 2.5m)" << endl;
        		continue;
    		}
    		else{
				cout<<"# Your weight(kg):"<<weight<<endl;
				cout<<"# Your height(m):"<<height<<endl;
				cout<<"# Your BMI:"<<bmi<<endl;
				if(bmi<=10){
					bmilevel="Unreasonably underweight";
				}
				else if(bmi>10&&bmi<=15){
					bmilevel="Highly severely underweight ";
				}
				else if (bmi>15&&bmi<=16){
					bmilevel="Severely underweight";
				}
				else if(bmi>16&&bmi<18){
					bmilevel="Underweight";
				}
				else if(bmi>=18&&bmi<=25){
					bmilevel="Normal";
				}
				else if(bmi>25&&bmi<=30){
					bmilevel="Overweight";
				}
				else if(bmi>30&&bmi<=35){
					bmilevel="Obese";
				}
				else if (bmi>35&&bmi<=40){
					bmilevel="Severely obese";
				}
				else if (bmi>40&&bmi<=45){
					bmilevel="Highly severely obese";
				}
				else if (bmi>45){
					bmilevel="Unreasonably obese";
				}
				cout<<"# Your BMI  level is "<<bmilevel<<endl;
				if(bmi<10){
					bmi10h=sqrt(weight / 10);
					bmi10w=10*(height*height);
					cout<<"# Either weight or height might be wrongly given (Step 4)"<<endl;
					cout<<"# If given weight is correct, so the given height should be at most "<<bmi10h<<"m (Step 4)."<<endl;
					cout<<"# If given height is correct, so the given weight should be at least "<<bmi10w<<"kg (Step 4)."<<endl;
				}
				else if(bmi>45){
					bmi45h=sqrt(weight / 45);
					bmi45w=45*(height*height);
					cout<<"# Either weight or height might be wrongly given. (Step4)" <<endl;
					cout<<"# If given weight is correct, so the given height should be at least "<<bmi45h<<"m (Step 4)."<<endl;
					cout<<"# If given height is correct, so the given weight should be at most "<<bmi45w<<"kg (Step 4)."<<endl;	 
				}
				else if(bmi<18.5){
					bmi18w=18.5*(height*height); 
					cout<<"# Increase your weight to "<<bmi18w<<"kg to bring your BMI value to 18.5 (Step 5)"<<endl;
				}
				else if(bmi>25){
					bmi25w=25*(height*height);
					cout<<"# Decrease your weight to "<<bmi25w<<"kg to bring your BMI value to 25 (Step 5)"<<endl;
				}
			continue;	
			}
		}
return 0;
}
