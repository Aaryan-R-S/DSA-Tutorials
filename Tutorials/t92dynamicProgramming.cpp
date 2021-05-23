#include<bits/stdc++.h>
using namespace std;

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

int main()
{
    int n; cin>>n;
    vector<unsigned long long int> dp(n,-1);
    cout<<fib1(n, dp)<<endl;
    cout<<fib2(n, dp)<<endl;

    return 0;
}