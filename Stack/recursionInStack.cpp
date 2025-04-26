#include<iostream>
#include<stack>
using namespace std;
void pushBottom(stack<int>& st, int val){
  if(st.size()==0){
    st.push(val);
    return;
  }
  int x = st.top();
 
  st.pop();
  pushBottom(st, val);

  st.push(x);
} 
void displayRec(stack<int>& st){
  if(st.size()==0) return;
  int x = st.top();
 
  st.pop();
  displayRec(st);
  cout<<x<<" ";
  st.push(x);
} 
void Rev(stack<int>& st){
  if(st.size()==1) return;
  int x = st.top();
  st.pop();
  Rev(st);
  pushBottom(st,x);
} 

int main(){
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);
  st.push(60);
  pushBottom(st,90);
  displayRec(st);
  Rev(st);
  cout<<endl;
  displayRec(st);
}