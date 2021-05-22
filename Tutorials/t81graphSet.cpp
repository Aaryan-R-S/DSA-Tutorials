#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
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
    
    vector<pair<int,int>> edges;
    rep(0,m,++){
        int u,v; cin>>u>>v;
        edges.push_back({u,v});
    }

    bool cycle = false;
    for(auto i: edges){
        int u = i.first;
        int v = i.second;
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

int main()
{
    detectCycleUndirect();

    return 0;
}