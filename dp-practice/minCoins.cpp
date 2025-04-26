#include<iostream>
#include<vector>
using namespace std;

vector<int> coins;
vector<int> dp;

int f(int x){
    if(x==0) return 0;
    // if(x<0) return INT64_MAX;
    if(dp[x]!=-2) return dp[x];
    int res = INT32_MAX;

    for(int i=0;i<coins.size();i++){
        if(x-coins[i] < 0) continue;
        res = min(res, f(x - coins[i])) ;
    }
    if(res == INT32_MAX) return dp[x] = INT32_MAX;
    return dp[x] = 1 + res;
}

int fbu(int n){
    dp[0] = 0;
    int res = INT32_MAX;
    for(int x = 1;x<coins.size(),x++){
        if(x-coins[i] < 0) continue;
        res = min(res, f(x - coins[i])) ;
    }
    if(res == INT32_MAX) return dp[x] = INT32_MAX;
}

int main(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        coins.push_back(ele);
    }
 
    dp.resize(1000005,-2);
    int ans = f(x);
    if(ans == INT32_MAX) cout<<-1;
    else cout<<ans;
    return 0;   
}