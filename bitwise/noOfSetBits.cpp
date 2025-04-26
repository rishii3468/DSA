#include<iostream>
using namespace std;

int no_of_set_bits(int num){
  int count = 0;
  while(num>0){
    count++;
    num = num & (num-1);
  }
  return count;
}

int main(){
  cout<<no_of_set_bits(7)<<"\n";
  return 0;
}