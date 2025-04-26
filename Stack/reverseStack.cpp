#include<iostream>
#include<stack>

using namespace std;



int main(){
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);
  stack<int> temp;
  while(st.size()>0){
    temp.push(st.top());
    st.pop();
  }
  stack<int> t;
  while(temp.size()>0){
    t.push(temp.top());
    temp.pop();
  }
  
  while(t.size()>0){
    st.push(t.top());
    t.pop();
  }
  
}