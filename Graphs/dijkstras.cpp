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

unordered_map<int,int> dijkstra(int src,int n,vector<int>& via){
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    
    unordered_set<int> vis;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[i] = INT32_MAX;
    }
    
    pq.push({0,src});
    mp[src] = 0;
    
   
    while( !pq.empty() ){
        pp curr = pq.top();
       
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        pq.pop();
        for(auto neighbour : gr[curr.second]){
            if(!vis.count(neighbour.first) && mp[neighbour.first] > neighbour.second + mp[curr.second]){
                mp[neighbour.first] = neighbour.second + mp[curr.second];
                pq.push({neighbour.second + mp[curr.second],neighbour.first});
                via[neighbour.first] = curr.second;
                
            }
        }
    }
    return mp;
}

void print(vector<int>& via, int dest){
    if(via[dest]==-1){
        cout<<dest<<" ->";
        return;
    }
    print(via,via[dest]);
    cout<<dest<<" ->";
}

int main(){
    int n,m;
    cin>>n>>m;
    gr.resize(n,list<pair<int,int>>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src;
    cin>>src;
    vector<int> via(n);
    unordered_map<int,int> sp = dijkstra(src,n,via);
    
    for(auto el: sp){
        cout<<el.first<<" "<<el.second<<endl;
    }
    int dest;
    cin>>dest;
    cout<<sp[dest]<<endl;
    via[src] = -1;
    print(via,dest);
    
    return 0;
}