#include<bits/stdc++.h>
using namespace std;

// `Problems`:
// - First elem at least X (harder) [https://youtu.be/Hooe5ORdFsc]

#define ll long long
const int MOD = 1e9+7;
const int N = 1e5+2;
ll arr[N], tree[4*N];

void build(int node, int st, int en){
    if(st==en){
        tree[node] = arr[st];
        return;
    }
    int mid = st+(en-st)/2;
    build(2*node+1, st, mid);
    build(2*node+2, mid+1, en);
    tree[node] = max(tree[2*node+1], tree[2*node+2]);
}

int query(int node, int st, int en, int l, int r){
    // No overlap
    if(st>r || en<l){
        return -MOD;
    }
    // Complete overlap
    if(st>=l && en<=r){
        return tree[node];
    }
    // Partial overlap
    int mid = st+(en-st)/2;
    ll q1 = query(2*node+1, st, mid, l, r);
    ll q2 = query(2*node+2, mid+1, en, l, r);
    return max(q1, q2);
}

void update(int node, int st, int en, int idx, ll val){
    if(st==en){
        arr[st]=val;
        tree[node]=val;
        return;
    }
    int mid = st+(en-st)/2;
    if(idx<=mid){
        update(2*node+1, st, mid, idx, val);
    }
    else{
        update(2*node+2, mid+1, en, idx, val);
    }
    tree[node] = max(tree[2*node+1], tree[2*node+2]);
}

int main()
{
    int n,m;
    cin>>n>>m;
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
            ll val; cin>>val;
            update(0, 0, n-1, idx, val);
        }
        else if(type==2){
            int x; cin>>x;
            int l = 0, r = n-1;
            int ans = n;
            while(l<=r){
                int mid = l+(r-l)/2;
                ll res = query(0, 0, n-1, l, mid);
                if(res < x){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                    ans = min(ans, mid);
                }
            }
            if(ans==n){
                cout<<"-1"<<endl;
            }
            else{
                cout<<ans<<endl;
            }
        }
    }
    
    return 0;
}