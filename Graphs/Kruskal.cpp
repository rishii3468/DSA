// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// int find(vector<int> &parent, int a){
//     return parent[a] == ((parent[a]=a) ? a: find(parent,parent[a]));
// }

// void Union(vector<int> &parent, vector<int> &rank, int a, int b){
//     a = find(parent,a);
//     b = find(parent,b);
//     if(a==b)return;
//     if(rank[a]>=rank[b]){
//         rank[a]++;
//         parent[b] = a;
//     }
//     else{
//         rank[b]++;
//         parent[a] = b;
//     }
// }

// struct Edge{
//     int src;
//     int dest;
//     int wt;
// };

// bool cmp(Edge e1, Edge e2){
//     return e1.wt < e2.wt;
// }

// ll kruskals(vector<Edge> &input, int n, int e){
//     sort(input.begin(),input.end(),cmp);
//     vector<int> parent(n+1);
//     vector<int> rank(n+1,1);
//     for(int i=0;i<=n;i++){
//         parent[i]=i;
//     }
//     int edgeCount = 0;
//     int i = 0;
//     ll ans = 0;
//     while(edgeCount < n-1 && i< input.size()){
//         Edge curr = input[i];
//         int srcPar = find(parent,curr.src);
//         int destpar = find(parent,curr.dest);
//         if(srcPar != destpar){
//             Union(parent,rank,srcPar,destpar);
//             ans += curr.wt;
//             edgeCount++;
//         }
//         i++;
//     }
//     return ans;
// }

// int main(){
//     int n,e;
//     cin>>n>>e;
//     vector<Edge> v(e);
//     for(int i=0;i<e;i++){
//         cin>>v[i].src>>v[i].dest>>v[i].wt;
//     }
//     cout<<kruskals(v,n,e)<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Edge {
    int src;
    int dest;
    int wt;
};

// Comparator function to sort edges by weight
bool cmp(const Edge &e1, const Edge &e2) {
    return e1.wt < e2.wt;
}

// Find with path compression
int find(vector<int> &parent, int a) {
    if (parent[a] != a)
        parent[a] = find(parent, parent[a]);
    return parent[a];
}

// Union by rank
void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if (a == b) return;

    if (rank[a] < rank[b]) {
        parent[a] = b;
    } else if (rank[a] > rank[b]) {
        parent[b] = a;
    } else {
        parent[b] = a;
        rank[a]++;
    }
}

ll kruskals(vector<Edge> &edges, int n) {
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 0; i <= n; i++) parent[i] = i;

    ll totalWeight = 0;
    int edgeCount = 0;

    for (int i = 0; i < edges.size() && edgeCount < n - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].wt;

        int pu = find(parent, u);
        int pv = find(parent, v);

        if (pu != pv) {
            Union(parent, rank, pu, pv);
            totalWeight += w;
            edgeCount++;
        }
    }

    return totalWeight;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edges(e);

    for (int i = 0; i < e; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].wt;
    }

    cout << kruskals(edges, n) << endl;
    return 0;
}
