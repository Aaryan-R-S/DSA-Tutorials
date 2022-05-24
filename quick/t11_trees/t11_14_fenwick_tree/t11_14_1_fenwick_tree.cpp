#include<bits/stdc++.h>
using namespace std;

// `YouTube Video`:
// - https://youtu.be/fIQABUIeWYg

int n; 
vector<int> bits;

int query(int idx){
    int ans = 0;
    while(idx>0){
        ans += bits[idx];
        idx -= idx&(-idx);
    }
    return ans;
}

void update(int idx, int val){
    while(idx<=n){
        bits[idx] += val;
        idx += idx&(-idx);
    }
}

int main(){
    cin>>n;
    bits = vector<int>(n+1);
    vector<int> a(n+1);
    for (int i = 1; i < n+1; i++){
        cin>>a[i];
        update(i, a[i]);
    }
    int q; cin>>q;
    while(q--){
        int c; cin>>c;
        if(c==1){
            int l,r; cin>>l>>r;
            int ans = query(r) - query(l-1);
            cout<<ans<<endl;
        }
        else if(c==2){
            int idx, val;
            cin>>idx>>val;
            update(idx, -a[idx]);
            a[idx] = val;
            update(idx, val);
        }
    }
    return 0;
}