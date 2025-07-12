#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int grid[4][4] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};
int dp[10][10];
int tsp(int curr, int mask, int n,vector<int> &a){
    if(mask ==(1<<n)-1){
        return grid[curr][0];
    }
    if(dp[curr][mask] != -1){
        return dp[curr][mask];
    }
    int ans = __INT32_MAX__;
    int t;
    for(int neigh =0;neigh<n;neigh++){
        
        if((mask & (1<< neigh)) == 0){
            int newc = grid[curr][neigh] + tsp(neigh, mask | (1<<neigh), n,a);
            if( newc< ans){
                ans = newc;
                t = neigh;
            }
        }
    }
    a.push_back(t);
    return dp[curr][mask] = ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    vector<int> a;
    cout<<tsp(0,1,4,a)<<endl;
    for(int e : a){
        cout<<e<<" ";
    }
    return 0;
}