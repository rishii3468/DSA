#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> f(n+10,0);
    int m;
    cin>>m;

    for(int i=0;i<m;i++){
        int L,R;
        cin>>L>>R;
        f[L]++;
        f[R+1]--;
    }
    for(int i=2;i<f.size();i++){
        f[i] += f[i-1];
    }

    vector<int> c(10000004,0);
    for(int i=0;i<=n;i++){
        c[f[i]]++;
    }
    for(int i=c.size()-2;i>=0;i--){
        c[i] += c[i+1];
    }
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        cout<<c[n]<<endl;
    }
    return 0;
}