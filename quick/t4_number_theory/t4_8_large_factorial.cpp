#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Find (N!)%(P) OR N! modulo P
// 1 < P < 2*10e9, P is prime
// 1 <= N < 2*10e9
// abs(N-P) <= 1000

// Time Complexity - O((P-1-N)*log(P-2)) = O((P-N)*log(P))

// Using Binary Exponentiation (Iterative) - O(log(P-2))    OR      Recursive Approach
ll power(ll x, ll y, ll p){
    ll res = 1;
    x %= p;
    while(y>0){
        if(y&1)
            res = (res*x)%p;
        x = (x*x)%p;
        y >>= 1;
    }
    return res;
}

// Using Fermat Little Theorem - O(log(P-2))    OR      Extended Euclidean Algorithm
ll modInverse(ll a, ll p){
    return power(a, p-2, p)%p;
}

// Using Wilson Theorem - O(P-1-N)
ll modFact(ll n, ll p){
    if(n>=p){
        return 0;
    }
    ll res = p-1;   // res = -1 but to avoid -ve ans we add mod i.e. p so it becomes p-1
    for (int i = n+1; i < p; i++)
    {
        res = (res*modInverse(i,p))%p; 
    }
    return res;
}


int main()
{
    int t; cin>>t;
    while(t--){
        ll n,p; 
        cin>>n>>p;
        cout<<modFact(n,p)<<endl;
    }

    return 0;
}