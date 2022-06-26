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
// The Time complexity of BFS is O(V + E) when Adjacency List is used and O(V^2) when Adjacency Matrix is used, where V stands for vertices and E stands for edges.	
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

    // Can use a for-loop in case of disconnected components
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
// The Time complexity of DFS is also O(V + E) when Adjacency List is used and O(V^2) when Adjacency Matrix is used, where V stands for vertices and E stands for edges.
// NO STACK IS REQUIRED (OPTIONAL)
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
// NO STACK IS REQUIRED (OPTIONAL)
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
// topological sort is not unique
// REFER GFG for implementation - DFS - O(V+E) - https://www.geeksforgeeks.org/topological-sorting/
// *IGNORE THIS CODE*
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
        // there may be a case when indegree=1 as a least indegree so you can use a while loop to loop until you don't push someting to queue and then use that minimum indegree to again push in below loop
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