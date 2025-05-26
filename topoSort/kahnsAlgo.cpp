#include<bits/stdc++.h>
using namespace std;

vector<list<int> > graph;
int v;
void add_edge(int a, int b, bool bidir = true){
    graph[a].push_back(b);
    if(bidir) graph[b].push_back(a);    
}

void topoBFS(){
    //Kahn's Algo
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto neigh : graph[i]){
            indegree[neigh]++;
        }
    }
    queue<int> qu;
    unordered_set<int> visited;
    for(int i = 0;i<v;i++){
        if(indegree[i] == 0){
            qu.push(i);
            visited.insert(i);
        }
    }
    while(!qu.empty()){
        int node = qu.front();
        cout<<node<<" ";
        qu.pop();
        for(auto neigh : graph[node]){
            if(!visited.count(neigh)){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    qu.push(neigh);
                    visited.insert(neigh);
                } 
            }
        }
    }
}

int main(){ 
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v, list<int> ());
    while(e--){
        int a,b;
        cin>>a>>b;
        add_edge(a,b,false);
    }
    topoBFS();
    cout<<endl; 
    return 0;
}