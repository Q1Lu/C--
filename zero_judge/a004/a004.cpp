#include <bits/stdc++.h>
using namespace std;

int main(){
    int years = 0;
    while(cin >> years){
        if(years % 400 == 0 || (years % 4 == 0 && years % 100 != 0)){
            cout << "¶|¦~" << endl;
        }else{
            cout << "¥­¦~" << endl;
        }
    }
        return 0;
}