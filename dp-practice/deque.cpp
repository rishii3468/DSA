#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

vector<vector<ll>> dp;
vector<ll> arr(3005);

ll f(int i, int j){
    if(i == j) return arr[i];
    if(dp[i][j] != -1) return dp[i][j];
    else return dp[i][j] = max(arr[i]-f(i+1,j), arr[j]-f(i,j-1));
}

ll fbu(int n){
    for(int i=0;i<n;i++){
        dp[i][i] = arr[i];
    }

    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j = i+len-1;
            dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    dp.resize(3005,vector<ll>(3005,-1));
    cout<<fbu(n)<<endl;
    return 0;
}