#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto el : graph[i]){
            cout<<el<<" , ";
        }
        cout<<endl;
    }
}

bool bfs(int src){
    unordered_set<int> vis;
    queue<int>qu;
    vector<int> par(v,-1);
    qu.push(src);
    vis.insert(src);
    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();
        for(auto neighbour : graph[curr]){
            if(vis.count(neighbour) && par[curr] != neighbour) return true;
            if(!vis.count(neighbour)){
                vis.insert(neighbour);
                par[neighbour] = curr;
                qu.push(neighbour);
            }
        }
    }
    return false;
}

bool has_cycle(){
    unordered_set<int> vis;

    for(int i=0;i<v;i++){
        if(!vis.count(i)){
            // int parent = i==0? -1:i-1;
            bool result = bfs(i);
            if(result) return true;
        }
    }
    return false;
}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s,d,false);

    }
    display();
    bool b = has_cycle();
    cout<<b<<endl;
    return 0;
}