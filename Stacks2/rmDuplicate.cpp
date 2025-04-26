#include<iostream>
#include<stack>
using namespace std;
string compress(string s){
  stack<char> st;
  st.push(s[0]);
  for(int i=1;i<s.length();i++){
    if(st.top()!=s[i]) st.push(s[i]);
  }
  s = "";
  while(st.size()>0){
    s = st.top()+s;
    st.pop();
  }
  return s;
}

int main(){
  string s = "acddefgghii";
  s = compress(s);
  cout<<s;
}