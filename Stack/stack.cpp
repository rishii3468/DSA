#include<iostream>
#include<stack>

using namespace std;

int main(){
  stack<int> st;
  cout<<st.size()<<endl;
  st.push(10);
  cout<<st.size()<<endl;
  st.push(20);
  cout<<st.size()<<endl;
  st.pop();
  cout<<st.size()<<endl;
  cout<<st.top()<<endl;
  st.push(30);
  cout<<st.size()<<endl;
  st.push(40);
  cout<<st.size()<<endl;
  stack<int> temp;
  while(st.size()>0){
    temp.push(st.top());
    st.pop();
  }
  while(temp.size()>0){
    cout<<temp.top()<<" ";
    st.push(temp.top());
    temp.pop();
  }
}