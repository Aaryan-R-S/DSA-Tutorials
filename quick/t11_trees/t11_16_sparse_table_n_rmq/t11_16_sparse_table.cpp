#include<bits/stdc++.h>
using namespace std;

// Sparse Table ----------------------------------------------------
// Refer - https://youtu.be/0jWeUdxrGm4
// Range Minimum Query - https://cses.fi/problemset/task/1647

const int MAX_N = 2e5 + 10;
const int MAX_LOG = 17;
int sp_table[MAX_N][MAX_LOG] = {0}; 
int LOGS[MAX_N] = {0};

int n, q; 

void build_sparse_table(){
    for (int i = 1; i <= LOGS[n]; i++){
        for (int j = 0; j + (1<<i) - 1 < n; j++){
            sp_table[j][i] = min(sp_table[j][i-1], sp_table[j + (1<<(i-1))][i-1]);
        }
    }
}

int query(int l, int r){
    int k = LOGS[r-l+1];
    return min(sp_table[l][k], sp_table[r-(1<<k)+1][k]);
}

int main(){
    for (int i = 2; i < MAX_N; i++){
        LOGS[i] = LOGS[i/2] + 1;
    }

    cin>>n;
    cin>>q;
    for (int i = 0; i < n; i++){
        cin>>sp_table[i][0];
    }
    build_sparse_table();
    
    while(q--){
        int l; cin>>l;
        int r; cin>>r;
        cout<<query(l-1, r-1)<<"\n";
    }
    return 0;
}