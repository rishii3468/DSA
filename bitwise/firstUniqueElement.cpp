#include<iostream>
using namespace std;

int main(){
  int arr[] = {1,3,3,5,2,2,1,4,4};
  int n =7,ans=arr[0];
  for(int i=1;i<7;i++){
    ans = ans ^ arr[i];
  }
  cout<<ans;
}