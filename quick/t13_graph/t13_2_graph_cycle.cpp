#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define rep(s,e,c) for (int i = s; i < e; i c)

// Detect cycle ---------------------------------------------------
bool isCycle(int src, vvi &adj, vi &vis, int parent){
    vis[src] = 1;
    for (auto i : adj[src])
    {
        if(i!=parent){
            if(vis[i]){
                return true;
            }
            else{
                if(isCycle(i, adj, vis, src))
                    return true;
            }
        }
    }
    return false;
}

void udDetectCycle(){
    int n, m; cin>>n>>m;
    vvi adj(n);
    rep(0,m,++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    vi vis(n,0);
    rep(0,n,++){
        if(!vis[i] and isCycle(i,adj,vis,-1)){   // isCycle will traverse the entire graph in only one iteration provided it is not disconnected (this case is ensured by for loop in case cycle is present in some other disconnected component)
            cycle = true;
            break;
        }
    }

    if(cycle)
        cout<<"Cycle present"<<endl;
    else
        cout<<"Cycle not present"<<endl;
    
}

bool isCycle(int src, vvi &adj, vi &vis, vi &stack){
    stack[src] = 1;
    vis[src] = 1;
    for (auto i : adj[src])
    {
        if(stack[i]){
            return true;
        }
        if(!vis[i]){
            if(isCycle(i, adj, vis, stack))
                return true;
        }
    }
    stack[src] = 0;
    return false;
}

void dDetectCycle(){
    int n, m; cin>>n>>m;
    vvi adj(n);
    rep(0,m,++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }

    bool cycle = false;
    vi vis(n,0);
    vi stack(n,0);
    rep(0,n,++){
        if(!vis[i] and isCycle(i,adj, vis,stack)){
            cycle = true;
            break;
        }
    }
    
    if(cycle)
        cout<<"Cycle present"<<endl;
    else
        cout<<"Cycle not present"<<endl;
}

// Connected components ---------------------------------------------------
int get_comp(int index, vvi &adj, vi &vis){
    vis[index] = 1;
    int ans = 1;
    for(auto i: adj[index]){
        if(!vis[i]){
            ans += get_comp(i, adj, vis);
        }
    }
    return ans;
}

void components(){
    int n, m; cin>>n>>m;
    vvi adj(n);
    rep(0,m,++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi comp;
    vi vis(n,0);
    rep(0,n,++){
        if(!vis[i]){
            comp.push_back(get_comp(i, adj, vis));
        }
    }
    for(auto i:comp){
        cout<<i<<" ";
    }
    cout<<endl;

    // No of ways of selecting two nodes such that they are not connected
    long long ans = 0;
    for(auto i:comp){
        ans += i*(n-i);
    }
    ans /= 2;
    cout<<ans<<endl;
}

// Bipartite graph --------------------------------------------------
// CHECK GFG - https://www.geeksforgeeks.org/bipartite-graph/
// able to color graph in two colors only such that each x colored node has y colored nodes only and vice-versa
// OR graph without any odd length cycles 
bool isBipartite(int idx, vvi &adj, vi &vis){
    int ones = 0;
    int zeros = 0;
    for (auto i : adj[idx])
    {
        if(vis[i]==0){
            zeros++;
        }
        if(vis[i]==1){
            ones++;
        }
    }
    int choice = 0;
    if(zeros){
        if(ones){
            return false;
        }
        else{
            choice = 1;
        }
    }
    else{
        choice = 0;
    }

    vis[idx] = choice;
    for (auto i : adj[idx])
    {
        if(vis[i]==-1){
            if(!isBipartite(i, adj, vis))
                return false;
        }
    }
    return true;
}

void bipartite(){
    int n, m; cin>>n>>m;
    vvi adj(n);
    rep(0,m,++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi vis(n,-1);
    bool ans = true;
    rep(0,n,++){
        if(vis[i]==-1 and !isBipartite(i, adj, vis)){
            ans = false;
            break;
        }
    }
    if(ans)
        cout<<"Its bipartite"<<endl;
    else
        cout<<"Its not bipartite"<<endl;
}

int main()
{
    // udDetectCycle();

    // dDetectCycle();

    // components();

    bipartite();

    return 0;
}