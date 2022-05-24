#include<bits/stdc++.h>
using namespace std;

// Segment tree:
// For arr of len N--
// No of nodes = 2*N-1 but for safety purpose we will use 4*N
// No of levels = log2(N)+1

const int N = 1e5+2;
int arr[N], tree[4*N];

void build(int node, int st, int en){
    if(st==en){
        tree[node] = arr[st];
        return;
    }
    int mid = st+(en-st)/2;
    build(2*node+1, st, mid);
    build(2*node+2, mid+1, en);
    tree[node] = tree[2*node+1] + tree[2*node+2];
}

int query(int node, int st, int en, int l, int r){
    // No overlap
    if(st>r || en<l){
        return 0;
    }
    // Complete overlap
    if(st>=l && en<=r){
        return tree[node];
    }
    // Partial overlap
    int mid = st+(en-st)/2;
    int q1 = query(2*node+1, st, mid, l, r);
    int q2 = query(2*node+2, mid+1, en, l, r);
    return q1+q2;
}

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    build(0,0,n-1);
    for (int i = 0; i < 2*n-1; i++)
    {
        cout<<tree[i]<<" ";
    }
    while (1)
    {
        int type;
        cin>>type;
        if(type==0){
            break;
        }
        else{
            int l, r; cin>>l>>r;
            cout<<query(0, 0, n-1, l, r)<<endl;
        }
    }
    
    return 0;
}