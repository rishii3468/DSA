#include<iostream>
using namespace std;

int max_power_of2(int n){
  n = n | (n>>1);
  n = n | (n>>2);
  n = n | (n>>4);
  return (n+1)>>1;
}

int main(){
  int x = 100;
  int temp;
  while(true){
    if((x & (x-1)) == 0) break;
    x = x & (x-1);
  }
  cout<<max_power_of2(24);
  return 0;
}