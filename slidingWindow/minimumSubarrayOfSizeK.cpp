#include<iostream>
using namespace std;
int main(){
  int arr[] = {7,1,2,5,8,4,9,3,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = 3;
  int maxSum = INT32_MIN;
  int maxIdx = -1;
  int sum = 0;
  for(int i=0;i<k;i++){
    sum += arr[i];
  }
  int i = 1, j = k;
  // sliding window
  while(j<n){
    sum += arr[j] - arr[i-1];
    if(maxSum<sum){
      maxSum = sum;
      maxIdx = i;
    }
    i++;
    j++;
    
  }
  // TC = O(n)
  cout<<maxSum<<endl;
  cout<<maxIdx;
}