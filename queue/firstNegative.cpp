#include<iostream>
#include<queue>
using namespace std;

int main(){
  queue<int> q;
  int arr[] = {0,-1,-2,3,4,-5,6,4,7,-8,4,4,4,4};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = 3;
  int ans[n-k+1];
  for(int i=0;i<n;i++){
    if(arr[i]<0) q.push(i);
  }
  for(int i=0;i<n-k+1;i++){
    if(q.size()==0){
      ans[i] = 0;
      continue;
    }
    if(q.front()<i+k && q.front()>=i){
      ans[i]=(arr[q.front()]);
      continue;
    } 
    else{
      while(q.front()<i) q.pop();
    }
    if(q.front()<i+k && q.front()>=i) ans[i]=(arr[q.front()]);
    else ans[i]=0;
  }
  for(int i=0;i<n-k+1;i++){
    cout<<ans[i]<<" ";
  }
}