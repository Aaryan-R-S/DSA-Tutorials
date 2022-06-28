#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vvp vector<vector<pair<int,int>>>
#define pii pair<int,int>
#define rep(s,e,c) for (int i = s; i < e; i c)

// `Problems`:
// - [!]https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/ [https://youtu.be/Om47LiGTy8o]
// - [!]https://www.interviewbit.com/problems/stepping-numbers/
// - [!]https://www.interviewbit.com/problems/clone-graph/
// - [!]https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/
// - [!]https://www.interviewbit.com/problems/word-ladder-i/
// - [!]https://www.interviewbit.com/problems/word-ladder-ii/
// - [!]https://www.interviewbit.com/problems/permutation-swaps/
// - https://www.interviewbit.com/problems/valid-path/
// - https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/
// - https://www.interviewbit.com/problems/knight-on-chess-board/
// - https://www.interviewbit.com/problems/region-in-binarymatrix/
// - https://www.interviewbit.com/problems/mother-vertex/
// - https://www.interviewbit.com/problems/path-with-good-nodes/
// - https://www.interviewbit.com/problems/water-flow/
// - https://www.interviewbit.com/problems/delete-edge/

// Snake and ladder -- explore all possibility using BFS
void sl(){
    int ladders, snakes;
    map<int, int> ladd;
    map<int, int> snak;

    cin>>ladders;
    rep(0,ladders,++){
        int u, v; 
        cin>>u>>v;
        ladd[u] = v;
    }

    cin>>snakes;
    rep(0,snakes,++){
        int u, v; 
        cin>>u>>v;
        snak[u] = v;
    }

    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vi vis(101,0);
    vis[1] = true;

    while (!q.empty() and !found)
    {
        int sz = q.size();
        moves++;
        while(sz--){
            int top = q.front();
            q.pop();
            for (int die = 1; die <= 6; die++)
            {
                if(top+die == 100){     // got the ans
                    found = true;
                    break;
                }
                else if(top+die < 100){
                    if(ladd[top+die] and !vis[ladd[top+die]]){   // if next step is ladd
                        vis[ladd[top+die]] = true;
                        if(ladd[top+die] == 100){
                            found = true;
                            break;
                        }
                        q.push(ladd[top+die]);
                    }
                    else if(snak[top+die] and !vis[snak[top+die]]){   // if next step is snak
                        vis[snak[top+die]] = true;
                        if(snak[top+die] == 100){   // in normal snake & ladder such snake not possible as it will work as ladder, but stil included as an exception 
                            found = true;
                            break;
                        }
                        q.push(snak[top+die]);
                    }
                    else if(!vis[top+die] and !snak[top+die] and !ladd[top+die]){   // if next step is normal sqaure
                        vis[top+die] = true;
                        q.push(top+die);
                    }
                }
            }
            if(found){
                break;
            }
        }

    }
    
    if(found)
        cout<<moves<<endl;
    else
        cout<<-1<<endl;
}

// Given a 2D board containing X and O, capture all regions surrounded by X
// Caturing is done by flipping O to X in that region
void change(vector<vector<char>> &arr, int i, int j){
    arr[i][j] = '_';
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    for (int k = 0; k < 4; k++)
    {
        int cx = i + dx[k];
        int cy = j + dy[k];
        if(cx>=0 and cx<arr.size() and cy>=0 and cy<arr[0].size() and arr[cx][cy]=='O'){
            change(arr, cx, cy);
        }
    }
}

void capture(){
    int n, m;
    cin>>n>>m;

    // Grid -- n*m
    vector<vector<char>> arr(n, vector<char>(m));
    rep(0,n,++){
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(i==0 or i==n-1 or j==0 or j==m-1){
                if(arr[i][j]=='O'){
                    change(arr,i,j);   // convert protected O's to _
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(arr[i][j]=='O'){
                arr[i][j] = 'X';   // capture O to X
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(arr[i][j]=='_'){
                arr[i][j] = 'O';   // convert back to O
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    

}

int main()
{
    // sl();

    capture();

    return 0;
}