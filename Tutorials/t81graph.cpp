#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

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

int main(){
    int n, m;  // no of nodes - n and no of edges - m
    cin>>n>>m;

    // int d;   // directed or not
    // cin>>d;

    // //  Matrix Representation of Graph -------------------------------------------------
    // vector<vi> adjMat(n+1, vi(n+1, 0));
    // for (int i = 0; i < m; i++)
    // {
    //     int x, y;
    //     cin>>x>>y;

    //     adjMat[x][y] = 1;
    //     if(!d){
    //         adjMat[y][x] = 1;
    //     }
    // }
    
    // // Display Graph
    // cout<<"Adjacent Matrix"<<endl;
    // for (int i = 1; i < n+1; i++)
    // {
    //     for (int j = 1; j < n+1; j++)
    //     {
    //         cout<<adjMat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // // Is edge from 3 to 7 or vice-versa
    // if(adjMat[3][7]==1){
    //     cout<<"True"<<endl;
    // }else{cout<<"False"<<endl;}

    // if(adjMat[3][4]==1){
    //     cout<<"True"<<endl;
    // }else{cout<<"False"<<endl;}


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

    // BFS Traversal -----------------------------------------------------------------------
    // cout<<"BFS"<<endl;

    // vi vis(n+1, 0);
    
    // queue<int> q;
    // q.push(1);
    // vis[1] = 1;
    
    // while (!q.empty())
    // {
    //     int node = q.front();
    //     cout<<node<<" ";
    //     q.pop();
    //     for (auto &j : l[node])
    //     {
    //         if(!vis[j]){
    //             vis[j] = 1;
    //             q.push(j);
    //         }
    //     }
    // }
    // cout<<endl;

    // DFS Traversal -----------------------------------------------------------------------
    cout<<"DFS"<<endl;
    vi vis(n+1, 0);
    stack<int> s;
    // dfs(l, vis, s);
    dfsPos(l, vis, s);
    cout<<endl;
    
    return 0;
}