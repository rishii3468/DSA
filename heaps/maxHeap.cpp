#include<iostream>
#include<queue>
using namespace std;

int main(){
  // priority_queue<int> pq;
  // pq.push(10);
  // pq.push(24);
  // pq.push(-6);
  // pq.push(8);
  // cout<<pq.top();
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(10);
  pq.push(24);
  pq.push(-6);
  pq.push(8);
  cout<<pq.top();
  pq.pop();
  cout<<pq.top();
}