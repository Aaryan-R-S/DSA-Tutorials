#include<bits/stdc++.h>
using namespace std;

#define ll long long

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

ll query(int node, int st, int en, int k){
    if(st==en){
        return st;
    }
    int mid = st+(en-st)/2;
    if(k<tree[2*node+1]){
        return query(2*node+1, st, mid, k);
    }
    return query(2*node+2, mid+1, en, k-tree[2*node+1]);
}

void update(int node, int st, int en, int idx){
    if(st==en){
        if(arr[st]==0){
            arr[st] = 1;
            tree[node] = 1;
        }else{
            arr[st] = 0;
            tree[node] = 0;
        }
        return;
    }
    int mid = st+(en-st)/2;
    if(idx<=mid){
        update(2*node+1, st, mid, idx);
    }
    else{
        update(2*node+2, mid+1, en, idx);
    }
    tree[node] = tree[2*node+1] + tree[2*node+2];
    return;
}

int main()
{
    ll n;
    cin>>n;
    ll m; cin>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    build(0,0,n-1);
    while (m--)
    {
        int type;
        cin>>type;
        if(type==1){
            int idx; cin>>idx;
            update(0, 0, n-1, idx); 
        }
        else if(type==2){
            int k; cin>>k;
            cout<<query(0, 0, n-1, k)<<endl;
        }
    }
    
    return 0;
}