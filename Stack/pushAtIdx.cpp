#include<iostream>
#include<stack>

using namespace std;

void pushBottom(stack<int>& st, int val){
  stack<int> t;
  while(st.size()>0){
    t.push(st.top());
    st.pop();
  }
  t.push(val);
  while(t.size()>0){
    st.push(t.top());
    t.pop();
  }
}

void prnt(stack<int> st){
  while(st.size()>0){
    cout<<st.top()<<" ";
    st.pop();
  }
  cout<<endl;
}

void pushAtIdx(stack<int>& st, int val, int idx){
  if(idx>st.size()-1){
    cout<<"invalid input";
    return;
  }
  stack<int> t;
  for(int i=0;i<=st.size()-idx+1;i++){
    t.push(st.top());
    st.pop();
  }
  st.push(val);
  while(t.size()>0){
    st.push(t.top());
    t.pop();
  }
}

int main(){
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);
  stack<int> temp;
  pushBottom(st,2);
  prnt(st);
  pushAtIdx(st,90,3);
  prnt(st);
}