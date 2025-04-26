#include<iostream>
#include<queue>
using namespace std;

int main(){
  priority_queue<int,vector<int>,greater<int>> pq;
  int arr[] = {6,5,3,2,8,10,9};
  int n = 5;
  for(int ele: arr){
    pq.push(ele);
  }
  
  int cost = 0;
  while(pq.size()>1){
    int  a = pq.top();
    pq.pop();
    a += pq.top();
    pq.pop();
    cost += a;
    pq.push(a);
  }
  
  cout<<cost;
  return 0;
}