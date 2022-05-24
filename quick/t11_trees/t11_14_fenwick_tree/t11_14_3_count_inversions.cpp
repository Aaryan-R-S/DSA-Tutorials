#include<bits/stdc++.h>
using namespace std;

// `YouTube Video`:
// - https://youtu.be/qvwdpqVvcRQ

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

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }

    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++){
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
    }
    
    int inv = 0;
    for (int i = n-1; i >= 0; i--)
    {
        inv += query(a[i]-1);
        update(a[i], 1);
    }
    cout<<inv<<endl;

    return 0;
}