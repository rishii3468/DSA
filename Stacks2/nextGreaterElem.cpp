#include<iostream>
#include<stack>
using namespace std;

int main(){
  int arr[] = {3,1,2,5,7,4,6,2,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  int nge[n];
  stack<int> st;
  st.push(arr[n-1]);
  nge[n-1] = -1;
  for(int i=n-2;i>=0;i--){
    while(!st.empty() && arr[i] >= st.top()){
        st.pop();
    }
    if(st.size()==0) nge[i] = -1;
    else nge[i] = st.top();
    st.push(arr[i]);
  }
  for(int i=0;i<n;i++){
    cout<<nge[i]<<" ";
  }
}