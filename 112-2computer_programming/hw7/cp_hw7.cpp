#include <iostream>
using namespace std;
int main(){
 int solve[200000]={};
 int n;
 int m;
 cin>>n;
 int narr[100000];
 int marr[100000];
 for(int i=0;i<n;i++){
  int tmp;
  cin>>tmp;
  narr[i]=tmp;
  solve[narr[i]]++;
 }
 cin>>m;
 for(int i=0;i<m;i++){
  int tmp2;
  cin>>tmp2;
  marr[i]=tmp2;
 }
 for(int i=0;i<m;i++){
  if(solve[marr[i]]>=1)cout<<"yes"<<endl;
  else cout<<"no"<<endl;
 }
}