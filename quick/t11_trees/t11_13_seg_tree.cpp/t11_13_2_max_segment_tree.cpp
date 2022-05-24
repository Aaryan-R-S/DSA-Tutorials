#include<bits/stdc++.h>
using namespace std;

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
    tree[node] = max(tree[2*node+1], tree[2*node+2]);
}

int query(int node, int st, int en, int l, int r){
    // No overlap
    if(st>r || en<l){
        return INT_MIN;
    }
    // Complete overlap
    if(st>=l && en<=r){
        return tree[node];
    }
    // Partial overlap
    int mid = st+(en-st)/2;
    int q1 = query(2*node+1, st, mid, l, r);
    int q2 = query(2*node+2, mid+1, en, l, r);
    return max(q1, q2);
}

void update(int node, int st, int en, int idx, int val){
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
    }cout<<endl;
    while (1)
    {
        int type;
        cin>>type;
        if(type==-1){
            break;
        }
        else if(type==1){
            int l, r; cin>>l>>r;
            cout<<query(0, 0, n-1, l, r)<<endl;
        }
        else if(type==2){
            int idx, val; cin>>idx>>val;
            update(0, 0, n-1, idx, val);
            for (int i = 0; i < 2*n-1; i++)
            {
                cout<<tree[i]<<" ";
            }cout<<endl;
        }
    }
    
    return 0;
}