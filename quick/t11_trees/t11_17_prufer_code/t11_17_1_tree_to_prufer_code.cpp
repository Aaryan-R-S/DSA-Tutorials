#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>

// Tutorial - https://youtu.be/DTrB8Qqt14Q?si=EBSI3zY5znIWRfES 

// CP Algorithm - https://cp-algorithms.com/graph/pruefer_code.html#number-of-ways-to-make-a-graph-connected

// Given N nodes and for each node its degree count, how many different spanning trees can we build while maintaining the degree count of each node (Hint: Think what is the relation of degree of a node in with prufer code)
// Answer - (         N-2         )      [This is a combinatorial formula]
//          (d1-1, d2-1, ..., dn-1)

vi treeToPruferCode(int nodes, vector<pii> &edges){
    unordered_set<int> neighbours[nodes+1];

    for(int i=0; i<edges.size(); i++){
        pii edge = edges[i];
        int u = edge.first, v = edge.second; 
        neighbours[u].insert(v);
        neighbours[v].insert(u);
    }

    priority_queue<int> leaves;
    for (int i = 1; i <= nodes; i++){
        if(neighbours[i].size()==1){
            leaves.push(-i);
        }
    }

    vi pruferCode;
    int need = nodes-2;
    while(need--){
        int leaf = -leaves.top(); leaves.pop();
        int neighbourOfLeaf = *(neighbours[leaf].begin());
        pruferCode.push_back(neighbourOfLeaf);
        neighbours[neighbourOfLeaf].erase(leaf);
        if(neighbours[neighbourOfLeaf].size()==1){
            leaves.push(-neighbourOfLeaf);
        }
    }

    return pruferCode;
}

int main(){
    return 0;
}