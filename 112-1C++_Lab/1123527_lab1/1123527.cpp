#include <bits/stdc++.h>
using namespace std;

int main(){
	int x=0,y=0,mul=0,div=0,m0d1=0,m0d2=0,m0d3=0,m0d4=0;
	cout<<"Input two integers X and Y:";
	cin>>x>>y;
	mul=x*y;
	cout<<"X*Y ="<<mul<<endl;
	if (y==0){
		cout<<"X/Y = NA"<<endl;
	}
	else{ 
		div=x/y;
		cout<<"X/Y ="<<div<<endl;
	
	} 
	if (y!=0){
		m0d1=x%y;
		cout<<"X%Y ="<<m0d1<<endl;   
	}
	else{
		cout<<"X%Y = NA"<<endl;
	} 
	if (y==0){
		cout<<"-X%Y = NA"<<endl;
		cout<<"X%(-Y) = NA"<<endl;
		cout<<"-X%(-Y) = NA"<<endl; 
	}
	else{
		m0d2=-x%y;
		cout<<"-X%Y ="<<m0d2<<endl;
		m0d3=x%(-y);
		cout<<"X%(-Y) ="<<m0d3<<endl;
		m0d4=-x%(-y);
		cout<<"-X%(-Y) ="<<m0d4<<endl;
		cout<<"Total result ="<<mul+div+m0d1+m0d2+m0d3+m0d4;
	}
	
	
	return 0;
}
