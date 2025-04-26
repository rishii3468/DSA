#include<iostream>
#include<vector>
#include<climits>
#define ll long long int
using namespace std;

vector<vector<ll>> dp(105,vector<ll>(105,-1));

ll g(vector<int> &colors,int i, int j){
    ll result = 0;
    for(int k=i;k<=j;k++){
        result = (result%100 + colors[k]%100) %100;
    }
    return result;
}


ll f(vector<int> &colors, int i,int j){
    if(i==j) return 0; 
    if(i+1==j) return colors[i]*colors[j];
    if(dp[i][j] != -1) return dp[i][j];
    ll res = INT32_MAX;
    for(int k = i+1;k<j;k++){
        res = min(res, f(colors,i,k) + f(colors,k+1,j) + g(colors,i,k) * g(colors,k+1,j)) ;
    }
    return dp[i][j] = res;
}

int main(){
    int n;
    while(cin>>n){
        vector<int> colors;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            colors.push_back(x);
        }
        cout<<f(colors,0,colors.size()-1);
    }
   
    return 0;
}