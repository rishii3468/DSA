#include<iostream>
#include<stack>
using namespace std;
int main(){

  int arr[7] = {2,1,5,6,2,3,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<n;
  int nse[7], pse[7];
  pse[0] = -1;
  nse[6] = -1;
  int maxa = INT16_MIN;

  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  int nge[n];
  stack<int> st;
  st.push(arr[0]);
  nge[0] = -1;
  for(int i=1;i<n;i++){
    while(!st.empty() && arr[i] <= st.top()){
        st.pop();
    }
    if(st.size()==0) nge[i] = -1;
    else nge[i] = st.top();
    st.push(arr[i]);
  }


}