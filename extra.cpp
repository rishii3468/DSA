#include <iostream>
#include <
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, int node, vector<int> &visited, int v) {
    visited[node] = 1;
    for (int j = 0; j < v; j++) {
        if (graph[node][j] == 1 && visited[j] == 0) {
            dfs(graph, j, visited, v);
        }
    }
}

int components(vector<vector<int>>& graph, int v, vector<int> &visited) {
    int count = 0;
    for (int i = 0; i < v; i++) {
        if (visited[i] == 0) {
            dfs(graph, i, visited, v);
            count++;
        }
    }
    return count;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v, vector<int>(v, 0));

    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        graph[u][w] = 1;
        graph[w][u] = 1;
    }

    vector<int> visited(v, 0);
    cout << components(graph, v, visited) << endl;

    // Try removing each vertex and see the number of components
    for (int remove = 0; remove < v; remove++) {
        vector<vector<int>> tempGraph = graph;
        vector<int> visited(v, 0);

        // Remove all edges incident to vertex 'remove'
        for (int j = 0; j < v; j++) {
            tempGraph[remove][j] = 0;
            tempGraph[j][remove] = 0;
        }

        cout << components(tempGraph, v, visited) << endl;
    }

    return 0;
}
