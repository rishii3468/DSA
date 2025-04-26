#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main(){
  string s = "2/3+3*3";
  string t = to_string(s[1]);
  cout<<typeid(t).name();
  return 0;
}