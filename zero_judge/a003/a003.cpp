#include <bits/stdc++.h>
using namespace std;

int main(){
    int month = 0,
        day = 0,
        s = 0;

    cin >> month >> day;
    s = (month*2 + day) % 3;
    
    if(s == 0){
        cout << "´¶³q" << endl;
    }else if (s == 1){
        cout << "¦N" << endl;
    }else{
        cout << "¤j¦N" << endl;
    }
}