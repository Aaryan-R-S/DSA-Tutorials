#include<bits/stdc++.h>
using namespace std;

// int arr[N];
// For 1D arrays N = 10e5+2
// int arr[N][N];
// For 2D arrays N = 10e3+2

#define vi vector<int>
#define vvi vector<vi>
#define rep(s,e,c) for (int i = s; i < e; i c)

// Nth Fibonacci num from O(2^n) to O(n) --------------------------------------------
// Top down approach -- recursive way (memoization)
long long int fib1(int n, vector<unsigned long long int> &dp){
    if(n==1 || n==2)
        return (n-1);
    if(dp[n-1]!=-1){
        return dp[n-1];
    }
    dp[n-1] = fib1(n-1, dp) + fib1(n-2, dp);
    return dp[n-1];
}

// Bottom up approach -- iterative way (tabulation)
long long int fib2(int n, vector<unsigned long long int> &dp){
    dp[0] = 0;
    dp[1] = 1;
    rep(2,n,++)
        dp[i] = dp[i-1]+dp[i-2];
    return dp[n-1];
}

// Coin change -- find no of ways you can make an amount X using any no of any coin
int coinChange(vi &coinsArr, int amt, int n, vvi &dp){
    if(amt==0)
        return 1;
    if(amt<0)
        return 0;
    if(n<=0)
        return 0;
    if(dp[n][amt] != -1)
        return dp[n][amt];

    dp[n][amt] = coinChange(coinsArr, amt-coinsArr[n-1], n, dp) + coinChange(coinsArr, amt, n-1, dp);
    return dp[n][amt];
}

// Minimun no of squares --  find min no of nums req such that sum of their squares equals the X
int minSquares(int n, vi &dp){
    if(n==1 || n==2 || n==3 || n==0)
        return n;

    if(dp[n]!=INT_MAX)
        return dp[n];

    for (int i = 1; i*i <= n; i++){
        dp[n] = min(dp[n], 1+minSquares(n-i*i, dp));        
    }
    
    return dp[n];
}

// Knapsack -- wt arr and val arr find max Val put in bag of max load W;
int knapsack(int n, vi &wt, vi &val, int w, vvi &dp){
    if(w<=0)
        return 0;
    if(n<=0)
        return 0;
    if(dp[n][w]!=-1)
        return dp[n][w];
    if(wt[n-1]>w)
        dp[n][w] = knapsack(n-1, wt, val, w, dp);
    else
        dp[n][w] = max(knapsack(n-1, wt, val, w, dp), knapsack(n-1, wt, val, w-wt[n-1], dp) + val[n-1]);
    return dp[n][w];
}

// Longest increasing subsequence
int subs(vi &a, int n, vi &dp_subs){
    if(dp_subs[n]!=-1)
        return dp_subs[n];

    dp_subs[n] = 1;
    rep(0,n,++){
        if(a[n]>a[i])
            dp_subs[n] = max(dp_subs[n], 1 + subs(a, i, dp_subs));
    }
    return dp_subs[n];
}

// Longest common subsequence
int lcs(string &s1, string &s2, int n, int m, vvi &dp){
    if(n==0 || m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(s1[n-1]==s2[m-1])
        dp[n][m] = (1+lcs(s1, s2, n-1, m-1,dp));
    else
        dp[n][m] = max(lcs(s1,s2,n-1,m,dp), lcs(s1,s2,n,m-1,dp));
    return dp[n][m];
}

// Matrix chain multiplication
int mcm(vi a, int i, int j, vvi &dp){
    if(i==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], mcm(a,i,k,dp) + mcm(a,k+1,j,dp) + a[i-1]*a[k]*a[j]);
    }
    return dp[i][j];
}

int main()
{
    // int n; cin>>n;
    // vector<unsigned long long int> dp(n,-1);
    // cout<<fib1(n, dp)<<endl;
    // cout<<fib2(n, dp)<<endl;


    // int n;cin>>n;
    // vi coinsArr(n);
    // rep(0,n,++){
    //     cin>>coinsArr[i];
    // }
    // int amt; cin>>amt;
    // vvi dp(10e3+2, vi(10e3+2, -1));
    // cout<<coinChange(coinsArr, amt, n, dp)<<endl;

    // int n;cin>>n;
    // vi dp(10e5+2, INT_MAX);
    // cout<<minSquares(n, dp)<<endl;
    
    // int n;cin>>n;
    // vi wt(n);
    // vi val(n);
    // rep(0, n, ++)
    //     cin>>wt[i];
    // rep(0, n, ++)
    //     cin>>val[i];
    // int w;cin>>w;
    // vvi dp(10e3+2, vi(10e3+2, -1));
    // cout<<knapsack(n, wt, val, w, dp)<<endl;

    int n; cin>>n;
    vi a(n);
    rep(0,n,++){
        cin>>a[i];
    }
    vi dp_subs(10e5+2, -1);
    cout<<subs(a, n-1, dp_subs)<<endl;

    // string s1, s2;
    // cin>>s1>>s2;
    // int n = s1.size();
    // int m = s2.size();
    // vvi dp(10e3+2, vi(10e3+2, -1));
    // cout<<lcs(s1, s2, n, m, dp)<<endl;

    // int n; cin>>n;
    // vi a(n);
    // rep(0,n,++)
    //     cin>>a[i];
    // vvi dp(10e3+2, vi(10e3+2, -1));
    // cout<<mcm(a, 1, n-1, dp)<<endl;
    // INPUTS: 5 means there are 4 matrices and remaining are dimensions of 4 matrices 10X20, 20X30, ..., 20X30
    // 5
    // 10 20 30 20 30

    return 0;
}