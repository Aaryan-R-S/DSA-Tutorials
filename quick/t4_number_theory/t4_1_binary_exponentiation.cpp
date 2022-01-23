#include<bits/stdc++.h>
using namespace std;

#define ll long long
// To calculate (a^n) % MOD 

// Basic ------------------------------------------------------------------------
// Assumption 'a', 'n' and 'MOD' are in range of int 
// Time complexity - O(log(N))
int powRec(int a, int n, int MOD){
    if(n==0)
        return 1;

    int p = powRec(a, n/2, MOD);

    if(n&1){
        return (int)(((p*1LL*p)%MOD)*1LL*a)%MOD;      // because p*p can exceed range of int
    }
    else{
        return (int)(p*1LL*p)%MOD;
    }
}

int powIter(int a, int n, int MOD){
    int ans = 1;
    while (n>0)
    {
        if(n&1){
            ans = (ans*1LL*a)%MOD;      // because ans*a can exceed the range of int
        }
        a = (a*1LL*a)%MOD;      // because a*a can exceed the range of int
        n = n>>1;
    }
    return ans;
}

// Q1 ---------------------------------------------------------------------------
// Assumption 'a' is very large - say O(1e18 or bigger)
// Solution: Do a === a%MOD
// Time complexity - O(log(N))
ll powIterA(ll a, ll n, ll MOD){
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

// Q2 ---------------------------------------------------------------------------
// Assumption 'MOD' is very large - say O(1e18)
// Solution: Use binary multiply for multiplication of any two num and then MOD in each step to ensure that product do not overflow long long
// Time complexity - O(log(N)*log(N)) = O(log^2(N))
ll binaryMultiply(ll a, ll b, ll MOD){
    ll ans = 0;
    while(b>0){
        if(b&1){
            ans = (ans+a)%MOD;
        }
        a = (2*a)%MOD;
        b >>= 1;
    }
    return ans;
}

ll powIterM(ll a, ll n, ll MOD){
    ll ans = 1;
    while (n>0)
    {
        if(n&1){
            ans = binaryMultiply(ans,a,MOD)%MOD;
        }
        a = binaryMultiply(a,a,MOD)%MOD;
        n = n>>1;
    }
    return ans;
}

// Q3 ---------------------------------------------------------------------------
// Assumption 'n' is very large - say O(1e18)
// Example - 50^(64^32) % 1e9+7 which means b (=64^32) is very large

// Solution: Eular's Theorem -
// (a^n)%MOD === (a^( n%phi(MOD) ))%MOD 
// That is n === n%phi(MOD) where phi() is Euler Totient Function
// If MOD is prime then phi(MOD) = MOD-1

// Time complexity - O(log(N)+log(N)) = O(log(N)))
ll powIterN(ll a, ll n, ll MOD){
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
    // int MOD = 1e9+7;
    // int a,n; 
    // cin>>a>>n;
    // cout<<powRec(a,n,MOD)<<endl;
    // cout<<powIter(a,n,MOD)<<endl;

    // ll MOD = 1e9+7;
    // ll a,n; 
    // cin>>a>>n;
    // cout<<powIterA(a,n,MOD)<<endl;

    // ll MOD = 1e18+7;
    // ll a,n; 
    // cin>>a>>n;
    // cout<<powIterM(a,n,MOD)<<endl;

    // ll MOD = 1e9+7;
    // ll a,n,c; 
    // cin>>a>>n>>c;
    // // Taking MOD as prime, otherwise make separate func for caluclating phi(MOD)
    // cout<<powIterN(a,powIterN(n,c,MOD-1),MOD)<<endl;    

    return 0;
}