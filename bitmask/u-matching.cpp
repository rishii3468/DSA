#include <bits/stdc++.h>
using namespace std;

vector<int> dp((1<<16), INT32_MAX);
vector<int> sum((1<<16), 0);

int calc(vector<vector<int>> &compat, int mask){
    int ans = 0;
    for(int i = 0; i < 16; i++){
        for(int j = i + 1; j < 16; j++){
            if((mask & (1 << i)) && (mask & (1 << j))){
                ans += compat[i][j];
            }
        }
    }
    return ans;
}

void precompute(vector<vector<int>> &compat, int n){
    for(int i = 1; i < (1 << n); i++){
        sum[i] = calc(compat, i);
    }
}

int f(vector<vector<int>> &compat, int mask){
    if(mask == 0) return 0;
    if(dp[mask] != INT32_MAX) return dp[mask];
    int ans = INT32_MIN;
    for(int g = mask; g != 0; g = (g - 1) & mask){
        ans = max(sum[g] + f(compat, g ^ mask), ans); 
    }
    return dp[mask] = ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> compat(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> compat[i][j];
        }
    }
    precompute(compat, n);
    cout << f(compat, (1 << n) - 1);
    return 0;
}
