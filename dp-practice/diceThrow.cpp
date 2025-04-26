#include<iostream>
#include<vector>
#define mod 1000000007
#define ll long long int
using namespace std;
vector<ll> dp(1000005,-1);


ll f(int n){
    dp[0] = 1;

    for(int k=1;k<=n;k++){
        ll sum = 0;
        for(int i=1;i<=6;i++){
        
            if(k>=i) sum = (sum % mod + dp[k-i] % mod)%mod;
            else break;
        }
        dp[k] = sum%mod;
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    
    cout<<f(n);
    return 0;
}