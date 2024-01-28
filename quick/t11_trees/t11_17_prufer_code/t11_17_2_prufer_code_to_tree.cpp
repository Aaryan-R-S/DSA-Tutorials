#include<bits/stdc++.h>
using namespace std;

#define ll long long

// CSES Problem - https://cses.fi/problemset/task/1134#:~:text=CSES%20%2D%20Pr%C3%BCfer%20Code&text=A%20Pr%C3%BCfer%20code%20of%20a,the%20structure%20of%20the%20tree.

int main(){
    ll n; cin>>n;

    vector<int> order(n-2);
    map<int,int> freq;
    for (int i = 0; i < n-2; i++){
        cin>>order[i];
        freq[order[i]]++;
    }

    set<int> leaf;
    for (int i = 1; i <= n; i++){
        if(freq[i]==0){
            leaf.insert(i);
        }
    }

    for (int i = 0; i < n-2; i++){
        int x = *leaf.begin();
        leaf.erase(x);
        cout<<x<<" "<<order[i]<<"\n";
        freq[order[i]]--;
        if(freq[order[i]]==0){
            leaf.insert(order[i]);
        }
    }

    cout<<*leaf.begin()<<" "<<*leaf.rbegin()<<"\n";

    return 0;
}