#include<bits/stdc++.h>
using namespace std;

// Nested Segments ----------------
// - [https://youtu.be/lPWCLJLokzs]
const int N = 2e5+2;
int arr[N] = {0}, tree[4*N] = {0};

struct triplet{
    int l, r, idx;
};

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
    tree[node] = tree[2*node+1]+ tree[2*node+2];
}

bool comp(triplet &a, triplet &b){
    return a.r<b.r;
}

// Intersecting Segments ----------------
// [https://youtu.be/YH4aS0F0D8c]
// Use -> no. of intersecting segments b/w l & r = (total elems b/w l & r) - 2*(no of nested segments) 

int main()
{
    int n;
    cin>>n;

    triplet t1;
    t1.l = t1.r = -1;
    vector<triplet> t(n, t1);

    int x;
    for (int i = 0; i < 2*n; i++){
        cin>>x;
        if(t[x-1].l == -1){
            t[x-1].l = i;
        }
        else{
            t[x-1].r = i;
        }
        t[x-1].idx = x;
    }

    sort(t.begin(), t.end(), comp);

    // build(0,0,2*n-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        ans[t[i].idx-1] = query(0, 0, 2*n-1, t[i].l, t[i].r);
        // ans[t[i].idx-1] = (t[i].r-t[i].l-1) - 2*query(0, 0, 2*n-1, t[i].l, t[i].r); // for intersecting segments
        update(0, 0, 2*n-1, t[i].l, 1);
    }

    for (int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}