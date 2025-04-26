#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

bool dfs(int curr,int end){
    if(curr==end) return true;
    visited.insert(curr);
    for(auto a : graph[curr]){

       
        if(visited.find(a) == visited.end()){
            bool result = dfs(a,end);
            if(result) return true;
        }
       
    }
    return false;
}

bool anyPath(int src, int dest){
    return dfs(src,dest);
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
    int x,y;
    cin>>x>>y;
    cout<<anyPath(x,y)<<endl;
    
    return 0;
}