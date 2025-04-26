#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void display(queue<int> &q)
{
  for (int i = 0; i < q.size(); i++)
  {
    int x = q.front();
    cout << x << " ";
    q.pop();
    q.push(x);
  }
  cout<<endl;
}

void reverseK(int k, queue<int>& q){
  stack<int> st;
  for(int i=1;i<=k;i++){
    st.push(q.front());
    q.pop();
  }
  while(st.size()>0){
    q.push(st.top());
    st.pop();
  }
  int n = q.size();
  for(int i=0;i<n-k;i++){
    int x = q.front();
    q.pop();
    q.push(x);
  }
}

int main()
{
  queue<int> q;
  stack<int> st1;
  stack<int> st2;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  display(q);
  int n = 5;
  int k = 8;
  k = k%n;
  reverseK(k,q);
  display(q);
}