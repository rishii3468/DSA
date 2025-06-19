#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define ll long long int

vector<list<pair<int,int>>> gr;
void add_edge(int u, int v,int wt,  bool bidir=true){
    gr[u].push_back({v,wt});
    if(bidir){
        gr[v].push_back({u,wt});
    }
}

ll prims(int src,int n){
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    
    unordered_set<int> vis;
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++){
        mp[i] = INT32_MAX;
    }
    vector<int> par(n+1);
    pq.push({0,src});
    mp[src] = -1;
    int totalCount = 0;
    int result = 0;
    while(totalCount < n && !pq.empty() ){
        pp curr = pq.top();
       
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        totalCount++;
        result += curr.first;
         pq.pop();
        for(auto neighbour : gr[curr.second]){
            if(!vis.count(neighbour.first) && mp[neighbour.first] > neighbour.second){
                mp[neighbour.first] = neighbour.second;
                pq.push({neighbour.second,neighbour.first});
                par[neighbour.first] = curr.second;
            }
        }
    }
    return result;
}

int main(){
    int n,m;
    cin>>n>>m;
    gr.resize(n+1,list<pair<int,int>>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src;
    cin>>src;
    cout<<prims(src,n)<<endl;

    return 0;
}