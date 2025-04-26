#include<iostream>
#include<cmath>
using namespace std;

void factors(int n){
  for(int i=1;i<=sqrt(n);i++){
    if(n%i == 0){
      cout<<i<<" ";
      
    } 
  }
  for(int i=sqrt(n);i>0;i--){
    if(n%i == 0){
      if(i != sqrt(n)) cout<<n/i<<" ";
    }
  }
}

int main(){
  factors(60);
}