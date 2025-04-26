#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> dp;
int f(int i,int j, vector<int> &arr){
    if(i==j || i+1==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = INT32_MAX;
    for(int k = i+1;k<j;k++){
        ans = min(ans,f(i,k,arr) + f(k,j,arr) + arr[i]*arr[j]*arr[k]);
    }
    return dp[i][j] =  ans;
}

int main(){
    int n;
    cin>>n;
    dp.resize(n+1,vector<int>(n+1,0));
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    for(int len = 3;len<=n;len++){
        for(int i= 0;i+len-1<n;i++){
            int j = i + len -1;
            int ans = INT32_MAX;
            for(int k = i+1;k<j;k++){
                ans = min(ans,dp[i][k] + dp[k][j] + v[i]*v[j]*v[k]);
            }
            dp[i][j] = ans;
        }
    }
    cout<<dp[0][n-1];
    return 0;
}