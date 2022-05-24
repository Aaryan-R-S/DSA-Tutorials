#include<bits/stdc++.h>
using namespace std;

// Square root Decompostion ----------------------------------------------------
// Refer - https://youtu.be/tuxMRkKuP8Y
void sqrt_decomposition(){
    int n; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    int len = sqrtl(n) + 1;
    vector<int> b(len);
    for (int i = 0; i < n; i++){
        b[i/len] += a[i];
    }
    
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        l--; r--;
        int sum = 0;
        for (int i = l; i <= r; )
        {
            if(i%len==0 && i+len-1<=r){
                sum += b[i/len];
                i += len;
            }
            else{
                sum += a[i];
                i++;
            }
        }
        cout<<sum<<endl;
    }
}

// Mo's Algorithm --------------------------------------------------------------
// Time complexity = Time taken for sorting queries + For adjusting curr_r + For adjusting curr_l
// Time complexity = Q*log(Q) + (n/√n)*n + Q*√n = O((Q+n)*√n)
// Refer this vid for Logic & Time Complexity - [https://youtu.be/0Cu9Kg7RJYg]

int len;

struct myQ{
    int idx, l, r;    
};

bool comp(struct myQ &a, struct myQ &b){
    if(a.l/len == b.l/len){
        return a.r>b.r;
    }
    return a.l<b.l;
}

void mo(){
    int n; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    len = sqrtl(n);
    int q; cin>>q;
    vector<struct myQ> allQ(q);
    for (int i = 0; i < q; i++){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        allQ[i].l = l;
        allQ[i].r = r;
        allQ[i].idx = i;
    }
    
    sort(allQ.begin(), allQ.end(), comp);

    vector<int> ans(q);
    int curr_l = 0, curr_r = -1, l , r, curr_ans = 0;
    for (int i = 0; i < q; i++){
        l = allQ[i].l;
        r = allQ[i].r;
        while(curr_r<r){
            curr_r++;
            curr_ans += a[curr_r];
        }
        while(curr_l>l){
            curr_l--;
            curr_ans += a[curr_l];
        }
        while(curr_l<l){
            curr_ans -= a[curr_l];
            curr_l++;
        }
        while(curr_r>r){
            curr_ans -= a[curr_r];
            curr_r--;
        }
        ans[allQ[i].idx] = curr_ans;
    }

    for (int i = 0; i < q; i++)
    {
        cout<<ans[i]<<endl;
    }
    
}

// Range Minimum Query - [https://youtu.be/NreaqzAKvg0]
// No. of distinct elements in range - [https://youtu.be/XPedtcrgA4E]

int main(){
    // sqrt_decomposition();
    mo();
    return 0;
}