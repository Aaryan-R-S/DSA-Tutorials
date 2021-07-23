#include<bits/stdc++.h>
using namespace std;
const int mod = 1002;

// 1. Longest Common Subsequence (LCS):
int dp1[mod][mod] = {-1};
int lcs_mem(string s1, string s2, int m, int n){
    if(m==0||n==0){
        return 0;
    }
    if(dp1[m][n]!=-1){
        return dp1[m][n];
    }
    if(s1[m-1]==s2[n-1]){
        return dp1[m][n] = 1+lcs_mem(s1, s2, m-1, n-1);
    }
    return dp1[m][n] = max(
        lcs_mem(s1, s2, m-1, n),
        lcs_mem(s1, s2, m, n-1)
    );
}

int lcs_tab(string s1, string s2, int m, int n){
    for (int i = 0; i < m+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            if(i==0||j==0){
                dp1[i][j] = 0;
            }
            else if(s1[i-1]==s2[j-1]){
                dp1[i][j] = 1+dp1[i-1][j-1];
            }
            else{
                dp1[i][j] = max(
                        dp1[i][j-1],
                        dp1[i-1][j]
                    );
            }
        }
        
    }
    
    return dp1[m][n];
}

// 2. Longest Common Substring:
int dp2[mod][mod] = {-1};
int subs_tab(string s1, string s2, int m, int n){
    for (int i = 0; i < m+1; i++){
        for (int j = 0; j < n+1; j++){
            if(i==0||j==0){
                dp2[i][j] = 0;
            }
            else if(s1[i-1]==s2[j-1]){
                dp2[i][j] = 1+dp2[i-1][j-1];
            }
            else{
                dp2[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m+1; i++){
        for (int j = 0; j < n+1; j++){
            ans = max(ans, dp2[i][j]);
        }
    }
    return ans;
}



int main()
{
    
    return 0;
}