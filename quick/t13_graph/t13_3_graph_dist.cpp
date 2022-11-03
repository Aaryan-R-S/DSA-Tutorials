#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vvp vector<vector<pair<int,int>>>
#define pii pair<int,int>
#define rep(s,e,c) for (int i = s; i < e; i c)

// THREE FUNCS -----------------------------------------------------------------
void make_set(int idx, vi &parent, vi &size){
    parent[idx] = idx;
    size[idx] = 1;
}

int find_set(int idx, vi &parent){
    if(parent[idx]==idx)
        return idx;
    return parent[idx] = find_set(parent[idx], parent);
}

void union_sets(vi &parent, vi &size, int a, int b){
    a = find_set(a, parent);
    b = find_set(b, parent);
    if(a!=b){
        if(size[a]<size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

// APPLICATIONS -----------------------------------------------------------------
// Detect cycle in a undirectred graph
void detectCycleUndirect(){
    int n, m; cin>>n>>m;

    vi parent(n);
    vi size(n);
    rep(0,n,++)
        make_set(i, parent, size);
    
    vvi edges;
    rep(0,m,++){
        int u,v; cin>>u>>v;
        // assume it as a 2D array
        edges.push_back({u,v});
    }

    bool cycle = false;
    for(auto i: edges){
        int u = i[0];
        int v = i[1];
        int x = find_set(u, parent);
        int y = find_set(v, parent);
        if(x==y){
            cycle = true;
            break;
        }
        else{
            union_sets(parent, size, u, v);
        }
    }

    if(cycle)
        cout<<"Cycle is present"<<endl;
    else
        cout<<"Cycle not present"<<endl;
}

// FOR WEIGHTED & UNDIRECTED & CONNECTED GRAPH
// Graph = G(V,E) where |V| = no of vertices and |E| = no of edges
// Spanning tree = Tree that contains all the vertices of its graph but edges may be less than or equal to that in its graph 
// MST = G'(V',E') where V' = V and E' = V-1  or E' is subset of E
// Cost of ST = cost of the spanning tree is the sum of the weights of all the edges in the tree
// Minimum Spanning tree (MST) = min cost ST

// Overview ----------------------------------------------------------------------
// KRUSKAL - O(E*logE)
// PRIMS + DIJKSTRA - O(V^2) in adj. matrix (preferred) & O(E*log(V)) using binary heaps in adj list
// -> O(V^2) - https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/ 
// -> O(E*log(V)) - https://www.interviewbit.com/problems/useful-extra-edges/
// BELLMANFORD - O(E*(V-1)) 
// FLOYD WARSHALL - O(V^3) 

// `Problems:`
// - Single src shortest path in DAG (including negative edges), in O(V+E) [https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/]
// - Single src shortest path in simple graph with possible edge weights as 0 or 1 only, in O(V+E) [https://www.interviewbit.com/problems/min-cost-path/] [https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/]

// Kruskal's Algorithm ------------------------------------------------------------
// Time complexity - O(E*logV) or O(E*logE) (sorting period)
// [ O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. After sorting, we iterate through all edges and apply the find-union algorithm. The find and union operations can take at most O(LogV) time. So overall complexity is O(ELogE + ELogV) time. The value of E can be at most O(V2), so O(LogV) is O(LogE) the same. Therefore, the overall time complexity is O(ElogE) or O(ElogV)]
// Space complexity - O(E+V)
void kruskal(){
    int n,m; cin>>n>>m;

    vi parent(n+1);
    vi size(n+1);
    rep(1,n+1,++)
        make_set(i, parent, size);
    
    vvi edges;
    rep(0,m,++){
        int u,v,w; cin>>u>>v>>w;
        // working as 2D array
        edges.push_back({w,u,v});
    }

    sort(edges.begin(), edges.end());

    int costMST = 0;
    for (auto i : edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find_set(u, parent);
        int y = find_set(v, parent);
        if(x==y){
            // cycle detection so ignore
            continue;
        }
        else{
            cout<<u<<" "<<v<<endl;
            costMST += w;
            union_sets(parent, size, u, v);
        }
    }
    cout<<costMST<<endl;
}

// Greedy algo to find the MST
// Also refer Jenny's lecture
void prims(){
    int n, m; cin>>n>>m;
    vvp adj(n);
    rep(0, m, ++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }

    int costMST = 0;
    set<vi> edges;  // by default elems are stored in ascending order
    vi partner(n);
    vi vis(n, 0);
    int go = 0;

    for(int i=0; i<n-1; i++){
        vis[go]=1;
        for(auto j:adj[go]){
            int w = j.first;
            int v = j.second;
            if(!vis[v]){
                bool found = false;
                for(auto k:edges){
                    if(k[1]==v and k[0]<w){
                        found = true;
                        break;
                    }
                }
                if(!found){
                    partner[v] = go;
                    edges.insert({w,v});
                }
            }
        }
        auto x = *edges.begin();
        cout<<partner[x[1]]<<" "<<x[1]<<" "<<x[0]<<endl;
        costMST += x[0];
        go = x[1];
        edges.erase(edges.begin());
    }

    cout<<costMST<<endl;
}

// Single src dist algo -- works for both directed and undirected graphs but not for -ve edge wt OR -ve wt cycle
void dijkstra(){
    int n,m; cin>>n>>m;

    vvp graph(n+1);
    rep(0,m,++){
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    int src; cin>>src;
    vi dist(n+1, INT_MAX);
    dist[src] = 0;
    set<pii> s;
    s.insert({0,src});  // wt, vertex

    while(!s.empty()){
        auto x = *s.begin();
        s.erase(x);
        for(auto i:graph[x.second]){
            // dist[neighbour] > dist[curr] + edge_wt
            if(dist[i.first]>dist[x.second]+i.second){
                s.erase({dist[i.first], i.first});   // if not present i.e. running first time it won't give any error unlike python's set
                dist[i.first] = dist[x.second]+i.second;
                s.insert({dist[i.first], i.first});
            }
        }
    }
    
    rep(1,n+1,++){
        if(dist[i]<INT_MAX){
            cout<<dist[i]<<" ";
        }
        else{
            cout<<-1<<" ";
        }
    }
    cout<<endl;
}

// Problems: [https://cp-algorithms.com/graph/bellman_ford.html]
// single src dist algo -- works for both directed and undirected graphs but not for -ve wt cycle
// max passes n-1;  O(E*(V-1))
void bellmanFord(){
    int n,m; cin>>n>>m;

    vvi edges;
    rep(0,m,++){
        int u,v,w; cin>>u>>v>>w; 
        edges.push_back({u,v,w});
    }
    
    int src; cin>>src;
    vi dist(n, 99999);
    dist[src] = 0;
    
    bool negCycle = false;
    rep(0,n,++){
        bool change = false;
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            if(dist[v] > w+dist[u]){    // given dist[u] is not infinity
                change = true;
                dist[v] = w+dist[u];
            }
        }
        if(!change){
            break;
        }
        else if(i==n-1){
            cout<<"Negative Weighted Cycle; Solution might be wrong!"<<endl;
        }
    }
    // if after n-1 pass i.e. in nth pass the value still changes it means that graph contains -ve wt cycle
    for(auto i :dist){
        cout<<i<<" ";
    }
    cout<<endl;
}

// all pair shortest path dist algo --  run for all type of graphs
void floydWarshall(){
    const int INF = 9999999;
    vvi graph = {
        {0,5,INF, 10},
        {INF,0,3,INF},
        {INF,INF,0,1},
        {INF,INF,INF,0}
    };

    int n = graph.size();
    vvi dist = graph;

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if ((dist[i][j] > (dist[i][k] + dist[k][j])) && (dist[k][j] != INF && dist[i][k] != INF)){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<( dist[i][j]==INF? -1 : dist[i][j] )<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    // detectCycleUndirect();

    // kruskal();

    // prims();

    // dijkstra();

    // bellmanFord();

    floydWarshall();

    return 0;
}