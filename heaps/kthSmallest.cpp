#include<iostream>
#include<queue>
using namespace std;

int main(){
  
  int arr[10] = {2,5,1,6,31,5,3,8,23,652};
  int k = 2;
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i=0;i<10;i++){
    pq.push(arr[i]);
    if(pq.size()>k) pq.pop();

  }
  cout<<pq.top();
}