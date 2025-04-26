#include<iostream>
#include<string>
using namespace std;

void printsubstr(string s1,string s2,int idx){
    if(idx==s2.length()){
        cout<<s1<<endl;
        return;
    } 
    printsubstr(s1,s2,idx+1);
    s1 += s2[idx];
    printsubstr(s1,s2,idx+1);
    
   
}

int main(){
    printsubstr("","abc",0);
}