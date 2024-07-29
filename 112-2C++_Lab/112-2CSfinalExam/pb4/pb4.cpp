#include <iostream>
#include <fstream>
using namespace std;

int main (){
    fstream fn;
    fn.open("fn.txt",ios::out);
    if(!fn){
        cout << "Error while creatng the file" << endl;
    }else{
        cout << "File created and data got writtem to file" << endl;
        fn << "This is ablog posted on internet";
        fn.close();     
    }
    return 0;
}