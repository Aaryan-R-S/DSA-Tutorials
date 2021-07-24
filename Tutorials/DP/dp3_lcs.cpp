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

// 3. Print LCS:
string print_lcs(string s1, string s2, int m, int n){
    lcs_tab(s1, s2, m, n);
    string ans;
    int i=m, j=n; 
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--; j--;
        }
        else{
            if(dp1[i][j-1]>dp1[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// 4. Shortest Common Super-sequence:
// Length of shortest super-sequence = m+n-lcs

// 5. Min no of insertions & deletions to convert a string s1 to s2:
// Insertions = s2-lcs
// Deletions = s1-lcs

// 6. Longest Palindromic Subsequence (LPS):
// lcs(s1, reverse(s1.begin(), s1.end()), n, n)

// 7. Min no of deletions to convert a string s1 to palindrome:
// Deletions = s1 - lps (see Point-6)

// 11. Min no. of insertions to make it palindrome:
// Insertions = s1 - lps (see Point- 6 & 7) = Deletions

// 8. Print Shortest Common Super-sequence:
string print_scs(string s1, string s2, int m, int n){
    lcs_tab(s1, s2, m, n);
    string ans;
    int i=m, j=n; 
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--; j--;
        }
        else{
            if(dp1[i][j-1]>dp1[i-1][j]){
                ans.push_back(s2[j-1]);
                j--;
            }
            else{
                ans.push_back(s1[i-1]);
                i--;
            }
        }
    }
    while(i>0){
        ans.push_back(s1[i-1]);
        i--;
    }
    while(j>0){
        ans.push_back(s2[j-1]);
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// 9. Longest Repeating (2 times) Subsequence in a string s1:
// s2 = s1 and n = m
int dp3[mod][mod] = {-1};
int lrs(string s1, string s2, int m, int n){
    for (int i = 0; i < m+1; i++){
        for (int j = 0; j < n+1; j++){
            if(i==0||j==0){
                dp3[i][j] = 0;
            }
            else if(s1[i-1]==s2[j-1] && i!=j){
                dp3[i][j] = 1+dp3[i-1][j-1];
            }
            else{
                dp3[i][j] = max(
                        dp3[i][j-1],
                        dp3[i-1][j]
                    );
            }
        }
    }
    return dp3[m][n];
}

// 10. Sequence Pattern Matching:
// Check if a is subsequence of b?
// lcs(a,b).length() == a.length() then YES else NO 

int main()
{
    
    return 0;
}