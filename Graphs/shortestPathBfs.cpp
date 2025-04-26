#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<queue>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result; 
vector<int> dist;
int v;
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void bfs(int src, int dest, vector<int> &dist){
    queue<int> qu;
    qu.push(src);
    dist.resize(v,INT32_MAX);
    dist[src] = 0;   
    visited.insert(src);
    while(qu.size()>0){
        int curr = qu.front();
        qu.pop();
        for(auto neighbour: graph[curr]){
            if(visited.find(neighbour) == visited.end()){
                qu.push(neighbour);
                dist[neighbour] = dist[curr] + 1;
                visited.insert(neighbour);
            }
            
        }
    }
}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s,d);

    }
    int x,y;
    cin>>x>>y;
    bfs(x,y,dist);

    for(int el : dist){
        cout<<el<<" ";
    }
    return 0;
}