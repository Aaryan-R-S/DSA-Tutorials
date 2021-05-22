#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

//  Matrix Representation of Graph -------------------------------------------------
void matrixRepres(){
    int n, m;  // no of nodes - n and no of edges - m
    cin>>n>>m;

    int d;   // directed or not
    cin>>d;

    vector<vi> adjMat(n+1, vi(n+1, 0));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin>>x>>y;

        adjMat[x][y] = 1;
        if(!d){
            adjMat[y][x] = 1;
        }
    }
    
    // Display Graph
    cout<<"Adjacent Matrix"<<endl;
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
    
    // Is edge from 3 to 7 or vice-versa
    if(adjMat[3][7]==1){
        cout<<"True"<<endl;
    }else{cout<<"False"<<endl;}

    if(adjMat[3][4]==1){
        cout<<"True"<<endl;
    }else{cout<<"False"<<endl;}

}

// Adjancency list representation of Graph -------------------------------------------
void adjListRepres(){
    int n, m;  // no of nodes - n and no of edges - m
    cin>>n>>m;

    vector<vi> l(n+1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin>>x>>y;
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    cout<<"Adjacent List"<<endl;
    for (int i=1; i<n+1; i++)
    {
        cout<<i<<"->";
        for (auto &j : l[i])
        {
            cout<<" "<<j;
        }
        cout<<endl;
    }

}

// BFS Traversal -----------------------------------------------------------------------
void bfs(){
    int n, m;  // no of nodes - n and no of edges - m
    cin>>n>>m;

    // Adjancency list representation of Graph -------------------------------------------
    vector<vi> l(n+1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin>>x>>y;
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    cout<<"Adjacent List"<<endl;
    for (int i=1; i<n+1; i++)
    {
        cout<<i<<"->";
        for (auto &j : l[i])
        {
            cout<<" "<<j;
        }
        cout<<endl;
    }

    cout<<"BFS"<<endl;

    vi vis(n+1, 0);
    
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    
    while (!q.empty())
    {
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for (auto &j : l[node])
        {
            if(!vis[j]){
                vis[j] = 1;
                q.push(j);
            }
        }
    }
    cout<<endl;
}

// DFS Traversal -----------------------------------------------------------------------
// Refer main()
// default pre-order
void dfs(vector<vi> &l, vi &vis, stack<int> &s, int node = 1){    
    s.push(node);
    vis[node] = 1;
    cout<<node<<" ";
    for (auto &i : l[node])
    {
        if(!vis[i]){
            dfs(l, vis, s, i);
        }
    }
    s.pop();
};

// post-order
void dfsPos(vector<vi> &l, vi &vis, stack<int> &s, int node = 1){    
    s.push(node);
    vis[node] = 1;
    for (auto &i : l[node])
    {
        if(!vis[i]){
            dfsPos(l, vis, s, i);
        }
    }
    cout<<node<<" ";
    s.pop();
};

// Topological Sort -----------------------------------------------------------------------
// Only directed acyclic graphs have topological sort
// undirected or cyclic graphs do not have topological sort
// it implies if during topological sort anyone doesn't traverse all the nodes exactly once then cycle exists
// topological sort is not unique
void topological(){
    int n, m;  // no of nodes - n and no of edges - m
    cin>>n>>m;

    vector<vi> l(n);
    vector<int> indeg(n, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin>>x>>y;
        // x -> y
        l[x].push_back(y);
        indeg[y]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if(indeg[i]==0){
            q.push(i);
        }
    }

    int count = 0;
    while(!q.empty()){
        count++;
        int x = q.front();
        q.pop();
        cout<<x<<"->";
        for (auto &i : l[x])
        {
            if(--indeg[i] == 0){
                q.push(i);
            }
        }
    }
    cout<<endl;

    if(count==n)
        cout<<"Cycle doesn't exist"<<endl;
    else
        cout<<"Cycle do exists"<<endl;

    return;
}

int main(){
    // int n, m;  // no of nodes - n and no of edges - m
    // cin>>n>>m;

    // // Adjancency list representation of Graph -------------------------------------------
    // vector<vi> l(n+1);
    // for (int i = 0; i < m; i++)
    // {
    //     int x, y;
    //     cin>>x>>y;
    //     l[x].push_back(y);
    //     l[y].push_back(x);
    // }
    
    // cout<<"Adjacent List"<<endl;
    // for (int i=1; i<n+1; i++)
    // {
    //     cout<<i<<"->";
    //     for (auto &j : l[i])
    //     {
    //         cout<<" "<<j;
    //     }
    //     cout<<endl;
    // }

    // cout<<"DFS"<<endl;
    // vi vis(n+1, 0);
    // stack<int> s;
    // // dfs(l, vis, s);
    // dfsPos(l, vis, s);
    // cout<<endl;

    topological();

    return 0;
}