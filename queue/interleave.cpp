#include<iostream>
#include<queue>
#include<stack>
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

int main(){
  queue<int> q;
  stack<int> st;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.push(6);
  q.push(7);
  q.push(8);
  display(q);
  while(q.size()>0){
    st.push(q.front());
    q.pop();
  }
  int n = st.size();
  while(st.size()>n/2){
    q.push(st.top());
    st.pop();
  }
  while(st.size()>0){
   
    int x = q.front();
    q.pop();
    q.push(x);
    q.push(st.top());
    st.pop();
  }
  while(q.size()>0){
    st.push(q.front());
    q.pop();
  }
  while(st.size()>0){
    q.push(st.top());
    st.pop();
  }
  display(q);

}