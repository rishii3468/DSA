#include<iostream>
#include<stack>
using namespace std;

int main(){
  int arr[] = {100,80,60,81,70,60,75,85};
  int n = sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  int nge[n];
  stack<int> st;
  st.push(0);
  nge[0] = 1;
  for(int i=1;i<n;i++){
    while(!st.empty() && arr[i] >= arr[st.top()]){
        st.pop();
    }
    if(st.size()==0) nge[i] = -1;
    else{
      nge[i] = i -  st.top();
      
    } 
    st.push(i);
  }
  for(int i=0;i<n;i++){
    cout<<nge[i]<<" ";
  }
}