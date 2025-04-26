#include<iostream>
#include<string>
using namespace std;

void parenthesis(string s,int n, int op, int cl){
    if(cl+op == 2*n){
        cout<<s<<endl;
        return;
    }
    if(op<n) parenthesis(s+"(",n,op+1,cl);
    if(cl<op)parenthesis(s+")",n,op,cl+1);
}

int main(){
    parenthesis("",3,0,0);
}