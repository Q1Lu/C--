#include <bits/stdc++.h>
using namespace std;

int main (){
    int k = 0,
        num = pow(1,k)+pow(5,k)+pow(3,k);
    while(num != 153){
    	num = pow(1,k)+pow(5,k)+pow(3,k);
        if(num == 153){
            cout << "yes " << k << endl;
            break;	 
        }
        k++;
    }
}