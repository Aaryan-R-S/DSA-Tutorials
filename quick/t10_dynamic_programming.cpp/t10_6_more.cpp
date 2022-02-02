#include<bits/stdc++.h>
using namespace std;

// Only refer -----------------------------------------------
// Binary Str
// Staircase
// LCS
// Ugly
// LCS
// Pair
// ----------------------------------------------------------


#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define rep(i,s,e,c) for (int i = s; i < e; i c)

void noOfSubs(){
    int n; cin>>n;
    string s; cin>>s;

    int e=1, a=0, ab=0, abc=0;
    rep(i,0,n,++)
    {
        if(s[i]=='a')
            a+=e;
        else if(s[i]=='b')
            ab+=a;
        else if(s[i]=='c')
            abc+=ab;
        else if(s[i]=='?'){
            abc = 3*abc+ab;
            ab = 3*ab+a;
            a = 3*a+e;
            e = 3*e;
        }
    }
    cout<<abc<<endl;
}

// count no of binary string of len N without consec one's
// observation -- below code is working as fibonacci sequence so u can directly use fib(n+1) to get ans for any n  
int binaryStr(int n, vvi &dp){
    if(n==1)
        return 2;

    if(dp[0][n]==-1){
        binaryStr(n-1, dp);
        dp[0][n] = dp[0][n-1]+dp[1][n-1];
        // Fib sequence : dp[0][n] = dp[0][n-1]+dp[0][n-2];
        // because dp[1][n-1] = dp[0][n-2]
        // so use only fib sequence or fib func to get the ans
        dp[1][n] = dp[0][n-1];
    }

    return dp[0][n]+dp[1][n];
}

// O-N knapsack -- same as O-1 knapsack but you can take any item any times
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
        dp[n][w] =
        max(knapsack(n-1, wt, val, w, dp),
            max(
                knapsack(n, wt, val, w-wt[n-1], dp) + val[n-1],
                knapsack(n-1, wt, val, w-wt[n-1], dp) + val[n-1]
                )
        );
    return dp[n][w];
}

// Staircase problem -- person can climb 1, 2 or 3 strairs at time find no of ways in which he can climb the staircase of N stairs
int staircase(int n, vi &dp){
    if(dp[n]==-1){
        dp[n] = staircase(n-1, dp)+staircase(n-2, dp)+staircase(n-3, dp);
    }
    return dp[n];
}

// LCS -- 3 strings
// Longest common subsequence -- same as that of two strings
int lcs(string &s1, string &s2, string &s3, int n, int m, int l, vvvi &dp){
    if(n==0 || m==0 || l==0)
        return 0;
    if(dp[n][m][l]!=-1)
        return dp[n][m][l];

    if(s1[n-1]==s2[m-1] && s1[n-1]==s3[l-1]){
        dp[n][m][l] = (1+lcs(s1, s2, s3, n-1, m-1, l-1, dp));
    }
    else{
        int p = lcs(s1,s2,s3,n-1,m,l,dp);
        int q = lcs(s1,s2,s3,n,m-1,l,dp);
        int r = lcs(s1,s2,s3,n,m,l-1,dp);
        dp[n][m][l] = max({p,q,r});
    }
    return dp[n][m][l];
}

// Ugly nums -- find nth ugly nums which is a num whose prime factors are 2, 3 or 5 only
// E.g. -  1,2,3,4,5,6,8,10,12,...
int ugly(int n, vi &dp){
    int counter_2, counter_3, counter_5; 
    counter_2 = counter_3 = counter_5 = 0;
    dp[0] = 1;
    rep(i,1,n,++){
        dp[i] = min({ 2*dp[counter_2], 3*dp[counter_3], 5*dp[counter_5] });
        if(2*dp[counter_2]==dp[i])
            counter_2++;
        if(3*dp[counter_3]==dp[i])
            counter_3++;
        if(5*dp[counter_5]==dp[i])
            counter_5++;
    }
    return dp[n-1];
}

// LCS -- 2 strings -- Can change atmost k elems to make longest subseq
int lcs(string &s1, string &s2, int n, int m, int k, vvi &dp){
    if(n==0 || m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(s1[n-1]==s2[m-1])
        dp[n][m] = (1+lcs(s1, s2, n-1, m-1,k,dp));
    else{
        int c1=-1, c2, c3;
        if(k>0){
            c1 = (1+lcs(s1, s2, n-1, m-1,k-1,dp));
        }
        c2 = lcs(s1,s2,n-1,m,k,dp);
        c3 = lcs(s1,s2,n,m-1,k,dp);
        dp[n][m] = max({c1, c2, c3});
    }
    return dp[n][m];
}

// Friends pairing problem
int pairs(int n, vi &dp){
    if(n==0||n==1||n==2)
        return n;
    if(dp[n]==-1)
        dp[n] = pairs(n-1, dp) + (n-1)*pairs(n-2, dp); 
    return dp[n];       
}

int main()
{
    // noOfSubs();

    // int n; cin>>n;
    // vvi dp(2, vi(n+1,-1));
    // dp[0][1] = 1;
    // dp[1][1] = 1;
    // cout<<binaryStr(n, dp)<<endl;

    // int n;cin>>n;
    // vi wt(n);
    // vi val(n);
    // rep(i, 0, n, ++)
    //     cin>>wt[i];
    // rep(i, 0, n, ++)
    //     cin>>val[i];
    // int w;cin>>w;
    // vvi dp(10e3+2, vi(10e3+2, -1));
    // cout<<knapsack(n, wt, val, w, dp)<<endl;

    // int n; cin>>n;
    // vi dp(10e5+2, -1);
    // dp[0] = 1;
    // dp[1] = 1;
    // dp[2] = 2;
    // cout<<staircase(n, dp)<<endl;

    // string s1, s2, s3;
    // cin>>s1>>s2>>s3;
    // int n = s1.size();
    // int m = s2.size();
    // int l = s3.size();
    // vvvi dp(200, vvi(200, vi(200, -1)));
    // cout<<lcs(s1, s2, s3, n, m, l, dp)<<endl;

    // int n; cin>>n;
    // vi dp(n);
    // cout<<ugly(n, dp)<<endl;

    // string s1, s2;
    // cin>>s1>>s2;
    // int k; cin>>k;
    // int n = s1.size();
    // int m = s2.size();
    // vvi dp(10e3+2, vi(10e3+2, -1));
    // cout<<lcs(s1, s2, n, m, k, dp)<<endl;

    // Length of longest Bitonic subsequence -- Longest strictly increasing or decreasing or first strictly increaing and then decreasing subsequence
    // int n; cin>>n;
    // vi a(n);
    // rep(i,0,n,++){
    //     cin>>a[i];
    // }
    // vi dp_increase(n,1);
    // vi dp_decrease(n,1);
    // rep(i,0,n,++){
    //     rep(j,0,i,++){
    //         if(a[i]>a[j]){
    //             dp_increase[i] = max(dp_increase[i], 1+dp_increase[j]);
    //         }
    //     }
    // }
    // for (int i = n-1; i >= 0; i--)
    // {
    //     for (int j = n-1; j > i; j--){
    //         if(a[i]>a[j]){
    //             dp_decrease[i] = max(dp_decrease[i], 1+dp_decrease[j]);
    //         }
    //     }
    // }
    // int ans=0;
    // rep(i,0,n,++){
    //     ans = max(ans, dp_increase[i]+dp_decrease[i]-1);
    // }
    // cout<<ans<<endl;

    int n; cin>>n;
    vi dp(n+1,-1);
    cout<<pairs(n,dp)<<endl;

    return 0;
}