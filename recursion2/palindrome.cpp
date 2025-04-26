#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool palindrome(string s,int i,int j){
    if(i>j) return true;
    if(s[i] == s[j]) return palindrome(s,i+1,j-1);
    else return false;
}
int main(){
    string s = "racedcar";
    cout<<palindrome(s,0,s.length()-1);
}