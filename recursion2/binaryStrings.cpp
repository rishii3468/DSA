#include<iostream>
#include<string>
using namespace std;
int n=1;
void binaryString(string s){
    if(n==s.length()){
        cout<<s<<endl;
        return;
    } 
    binaryString(s+'0');
    if(s[s.length()-1] != '1') binaryString(s+'1');
}
int main(){
    binaryString("");
}