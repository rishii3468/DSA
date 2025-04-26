#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
int v;
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void dfs(int node,unordered_set<int>& visited){
    visited.insert(node);
    for(auto neighbour: graph[node]){
        if(visited.find(neighbour) == visited.end()){
            dfs(neighbour,visited);
        }
    }
}
    
int connected_components(){
    int res = 0;
    unordered_set<int> visited;
    for(int i=0;i<v;i++){
        if(visited.find(i) == visited.end()){
            res++;
            dfs(i,visited);
        }
    }
    return res;
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
    cout<<connected_components()<<endl;  
    return 0;
}