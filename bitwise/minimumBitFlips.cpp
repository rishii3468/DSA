#include<iostream>
using namespace std;

int main(){
  int x = 23, y = 31;
  cout<< __builtin_popcount((x^y));
}