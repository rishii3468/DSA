#include<iostream>
#include<vector>
using namespace std;
vector<int> remove1(vector <int> arr,vector <int> ans,int idx){
    if(idx == arr.size()){
        return ans;
    }
    int ele = arr[idx];
    if(ele!=1){
        ans.push_back(ele);
        return remove1(arr,ans,idx+1);
    } 
    else return remove1(arr,ans,idx+1);
}
int main(){
    vector <int> ans;
    vector <int> arr(5);
    arr = {1,3,1,4,3};
    ans = remove1(arr,ans,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}