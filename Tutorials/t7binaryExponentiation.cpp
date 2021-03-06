#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll MOD = 1e9+7;

ll powRec(ll a, ll n){
    if(n==0)
        return 1;

    ll p = powRec(a, n/2);

    if(n&1){
        return (((p*p)%MOD)*a)%MOD;
    }
    else{
        return (p*p)%MOD;
    }
}

ll powIter(ll a, ll n){
    a %= MOD;
    ll ans = 1;
    while (n>0)
    {
        if(n&1){
            ans = (ans*a)%MOD;
        }
        a = (a*a)%MOD;
        n = n>>1;
    }
    return ans;
}

int main()
{
    ll a,n; 
    cin>>a>>n;

    cout<<powIter(a,n)<<endl;

    a %= MOD;
    cout<<powRec(a,n)<<endl;

    return 0;
}