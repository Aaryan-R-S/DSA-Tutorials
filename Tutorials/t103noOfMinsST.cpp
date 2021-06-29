#include<bits/stdc++.h>
using namespace std;
 
#define MOD 1e9+7

const long long N = 1e5+2;
long long arr[N];
pair<long long,long long> tree[4*N];
 
void build(long long node, long long st, long long en){
    if(st==en){
        tree[node].first = arr[st];
        tree[node].second=1;
        return;
    }
    long long mid = st+(en-st)/2;
    build(2*node+1, st, mid);
    build(2*node+2, mid+1, en);
    if(tree[2*node+1].first < tree[2*node+2].first){
      tree[node].first = tree[2*node+1].first;
      tree[node].second = tree[2*node+1].second;   
    }
    else if(tree[2*node+1].first > tree[2*node+2].first){
      tree[node].first = tree[2*node+2].first;
      tree[node].second = tree[2*node+2].second;   
    }
    else{
      tree[node].first = tree[2*node+2].first;
      tree[node].second = tree[2*node+2].second+tree[2*node+1].second;   
    }
}
 
pair<long long,long long> query(long long node, long long st, long long en, long long l, long long r){
    // No overlap
    if(st>r || en<l){
        return {MOD, -1};
    }
    // Complete overlap
    if(st>=l && en<=r){
        return tree[node];
    }
    // Partial overlap
    long long mid = st+(en-st)/2;
    pair<long long,long long> q1 = query(2*node+1, st, mid, l, r);
    pair<long long,long long> q2 = query(2*node+2, mid+1, en, l, r);
    pair<long long,long long> ansq;
    if(q1.first < q2.first){
        ansq = q1;
    }
    else if(q1.first > q2.first){
        ansq = q2;
    }
    else{
      ansq.first = q1.first;
      ansq.second = q1.second+q2.second;   
    }
    return ansq;
}
 
void update(long long node, long long st, long long en, long long idx, long long val){
    if(st==en){
        arr[st]=val;
        tree[node].first=val;
        tree[node].second=1;
        return;
    }
    long long mid = st+(en-st)/2;
    if(idx<=mid){
        update(2*node+1, st, mid, idx, val);
    }
    else{
        update(2*node+2, mid+1, en, idx, val);
    }
    if(tree[2*node+1].first < tree[2*node+2].first){
      tree[node].first = tree[2*node+1].first;
      tree[node].second = tree[2*node+1].second;   
    }
    else if(tree[2*node+1].first > tree[2*node+2].first){
      tree[node].first = tree[2*node+2].first;
      tree[node].second = tree[2*node+2].second;   
    }
    else{
      tree[node].first = tree[2*node+2].first;
      tree[node].second = tree[2*node+2].second+tree[2*node+1].second;   
    }
}


int main()
{
    long long n,m;
    cin>>n>>m;
    for (long long i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    build(0,0,n-1);
    while (m--)
    {
        int type;
        cin>>type;
        if(type==1){
            int idx, val; cin>>idx>>val;
            update(0, 0, n-1, idx, val);
        }
        else if(type==2){
            int l, r; cin>>l>>r;
            pair<long long,long long> pp = query(0, 0, n-1, l, r-1);
            cout<<pp.first<<" "<<pp.second<<endl;
        }
    }
    
    return 0;
}