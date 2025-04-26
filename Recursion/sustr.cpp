#include<iostream>
#include<string>
using namespace std;

void printsubstr(string s1,string s2){
    if(s2 == ""){
        cout<<s1<<endl;
        return;
    } 
    printsubstr(s1+s2[0],s2.substr(1));
    printsubstr(s1,s2.substr(1));
   
}

int main(){
    printsubstr("","abc");
}