#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Fermat Little Theorem + Wilson Theorem

// Fermat Little Theorem:
// (a^p)%p = a OR (a^p - a) is a multiple of p 
// OR a^p === a (mod p)
// OR a^(p-1) === 1 (mod p)
///-> a^(p-2) === a^(-1) (mod p) [MODULO INVERSE]

// Used in calculating (a/b)%m = a%m * (b^-1)%m    where b^-1 is multiplicative modulo inverse
// (b^-1)%m = b^(m-2) mod m

// Wilson Theorem:
// n>1 is a prime if and only if 
// (n-1)! === -1 (mod n)
///-> (n-1)! === n-1 (mod n)

// Used in calculating N! modulo P = ((P-1)! mod p * (n+1)^-1 mod p * (n+2)^-1 mod p *...* (P-1)^-1 mod p
// which is equal to p-1 * product of mod inverse of n+1, n+2, .... to p-1

// Find (N!)%(P) OR N! modulo P
// 1 < P < 2*10e9, P is prime
// 1 <= N < 2*10e9
// abs(N-P) <= 1000
// Time Complexity - O((P-N)*log(n))

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

ll modInverse(ll a, ll p){
    return power(a, p-2, p)%p;
}

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