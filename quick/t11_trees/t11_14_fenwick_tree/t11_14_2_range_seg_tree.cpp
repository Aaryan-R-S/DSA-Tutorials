#include<bits/stdc++.h>
using namespace std;

// `YouTube Video`:
// - https://youtu.be/08HzVTjCAsk

int query(int idx, vector<int> &bits, int n){
    int ans = 0;
    while(idx>0){
        ans += bits[idx];
        idx -= idx&(-idx);
    }
    return ans;
}

void update(int idx, int val, vector<int> &bits, int n){
    while(idx<=n){
        bits[idx] += val;
        idx += idx&(-idx);
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; 
        cin>>n;
        vector<int> bits(n+10, 0);
        int q; cin>>q;
        while(q--){
            int l, r, inc;
            cin>>l>>r>>inc;
            l++; r++;
            update(l, inc, bits, n);
            update(r+1, -inc, bits, n);
        }
        cin>>q;
        while(q--){
            int w; cin>>w;
            w++;
            cout<<query(w, bits, n)<<endl;
        }
    }
    return 0;
}