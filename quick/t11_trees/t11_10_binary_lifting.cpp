#include<bits/stdc++.h>
using namespace std;

// Kth Ancestor using Binary Lifting -------------------------------------------
class TreeAncestor {
    int log;
    vector<int> depth;
    vector<vector<int>> up;
public:
    TreeAncestor(int n, vector<int>& parent) {
        log = 0;
        while((1<<log) <= n){
            log++;
        }
        depth = vector<int>(n, 0);
        up = vector<vector<int>>(n, vector<int>(log, 0));
        parent[0] = 0;
        for(int i=0; i<n; i++){
            up[i][0] = parent[i];
        }
        for(int j=1; j<log; j++){
            for(int i=0; i<n; i++){
                if(i!=0){
                    depth[i] = depth[parent[i]]+1;
                }
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node]<k){
            return -1;
        }
        for(int i=log-1; i>=0; i--){
            if(k>=(1<<i)){
                node = up[node][i];
                k -= (1<<i);
            }
        }
        return node;
    }
};


// LCA using Binary Lifting ----------------------------------------------------
int MAX_N = 10000;
int MAX_LOG = 14;
vector<vector<int>> children(MAX_N, vector<int>(0));
vector<vector<int>> up(MAX_N, vector<int>(MAX_LOG, 0));
vector<int> depth(MAX_N, 0);

void dfs(int u){
    for(auto v: children[u]){
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for (int i = 1; i < MAX_LOG; i++){
            up[v][i] = up[up[v][i-1]][i-1];
        }
        dfs(v);
    }
}

int lca(int u, int v){
    if(depth[u]<depth[v]){
        swap(u, v);
    }
    int k = depth[u]-depth[v];
    for (int i = MAX_LOG-1; i>=0; i--)
    {
        if(k&(1<<i)){
            u = up[u][i];
        }
    }
    if(u==v){
        return u;
    }
    for (int i = MAX_LOG-1; i>=0; i--)
    {
        if(up[u][i]!=up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int m; cin>>m;
        while(m--){
            int v; cin>>v;
            children[i].push_back(v);
        }
    }
    dfs(0);
    int q; cin>>q;
    while(q--){
        int u, v; cin>>u>>v;
        cout<<lca(u, v)<<endl;
    }
    return 0;
}