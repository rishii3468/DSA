#include<iostream>
using namespace std;


int main(){
  int num = 10; //1010
  int n = num;
  while(true){
    if((n & (n-1)) == 0) break;
    n = n & (n-1);
  }
  n = n<<1;
  n -= 1;
  cout<<n<<endl;
  cout<<(n^num);
}