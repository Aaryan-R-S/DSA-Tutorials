#include<bits/stdc++.h>
using namespace std;
const int mod = 1e3+2;

// 1. Matrix Chain Multiplication:
int mcm_rec(int arr[], int i, int j){
    if(i>=j){
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++){
        ans = min(ans, arr[i-1]*arr[k]*arr[j] + mcm_rec(arr, i, k) + mcm_rec(arr, k+1, j));
    }
    return ans;
}

int dp1[mod][mod] = {-1};
int mcm_mem(int arr[], int i, int j){
    if(i>=j){
        return 0;
    }
    if(dp1[i][j]!=-1){
        return dp1[i][j];
    }
    dp1[i][j] = INT_MAX;
    for (int k = i; k < j; k++){
        dp1[i][j] = min(dp1[i][j], arr[i-1]*arr[k]*arr[j] + mcm_mem(arr, i, k) + mcm_mem(arr, k+1, j));
    }
    return dp1[i][j];
}

// 2. Palindrome Partitioning:
// Minimum number of partitions required such that each partition is a palindrome
bool isPalindrome(string s, int st, int en){
    for (int i = st; i < (en+1)/2; i++){
        if(s[i]!=s[en-i]){
            return false;
        }
    }
    return true;
}

int pal_rec(string s, int i, int j){
    if(i>=j){
        return 0;
    }
    if(isPalindrome(s, i, j)){
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++){
        ans = min(ans, 1 + pal_rec(s, i, k) + pal_rec(s, k+1, j));
    }
    return ans;
}

int dp2[mod][mod] = {-1};
int pal_mem(string s, int i, int j){
    if(i>=j){
        return 0;
    }
    if(dp2[i][j]!=-1){
        return dp2[i][j];
    }
    if(isPalindrome(s, i, j)){
        return dp2[i][j]=0;
    }
    dp2[i][j] = INT_MAX;
    for (int k = i; k < j; k++){
        dp2[i][j] = min(dp2[i][j], 1 + pal_mem(s, i, k) + pal_mem(s, k+1, j));
    }
    return dp2[i][j];
}

// 3. Evaluate Boolean Expression:
// Ex. s = "T|F&T^F" find no of ways of partitioning(not necessarily two times) so that string evaluates to true

int eval_bool(string s, int i, int j, bool isTrue){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue==true){
            if(s[i]=='T'){
                return 1;
            }
            return 0;
        }
        else{
            if(s[i]=='F'){
                return 1;
            }
            return 0;
        }
    }
    int ans = 0;
    for (int k = i+1; k <= j-1; k++)
    {
        int left_true = eval_bool(s, i, k-1, true);
        int left_false = eval_bool(s, i, k-1, false);
        int right_true = eval_bool(s, k+1, j, true);
        int right_false = eval_bool(s, k+1, j, false);
        if(isTrue==true){
            switch (s[k])
            {
            case '|':
                ans += left_true*right_false + left_false*right_true + left_true*right_true;
                break;
            case '&':
                ans += left_true*right_true;
                break;
            case '^':
                ans += left_true*right_false + left_false*right_true;
                break;
            }
        }
        else{
            switch (s[k])
            {
            case '|':
                ans += left_false*right_false;
                break;
            case '&':
                ans += left_true*right_false + left_false*right_true + left_false*right_false;
                break;
            case '^':
                ans += left_true*right_true + left_false*right_false;
                break;
            }
        }
    }
    return ans;
}

int dp3[mod][mod][2] = {-1};
int eval_bool_mem(string s, int i, int j, bool isTrue){
    if(i>j){
        return 0;
    }
    if(isTrue){
        if(dp3[i][j][1]!=-1){
            return dp3[i][j][1];
        }
    }
    else{
        if(dp3[i][j][0]!=-1){
            return dp3[i][j][0];
        }
    }
    if(i==j){
        if(isTrue==true){
            if(s[i]=='T'){
                return 1;
            }
            return 0;
        }
        else{
            if(s[i]=='F'){
                return 1;
            }
            return 0;
        }
    }
    int ans = 0;
    for (int k = i+1; k <= j-1; k++)   
    {
        int left_true = eval_bool_mem(s, i, k-1, true);
        int left_false = eval_bool_mem(s, i, k-1, false);
        int right_true = eval_bool_mem(s, k+1, j, true);
        int right_false = eval_bool_mem(s, k+1, j, false);
        if(isTrue==true){
            switch (s[k])
            {
            case '|':
                ans += left_true*right_false + left_false*right_true + left_true*right_true;
                break;
            case '&':
                ans += left_true*right_true;
                break;
            case '^':
                ans += left_true*right_false + left_false*right_true;
                break;
            }
        }
        else{
            switch (s[k])
            {
            case '|':
                ans += left_false*right_false;
                break;
            case '&':
                ans += left_true*right_false + left_false*right_true + left_false*right_false;
                break;
            case '^':
                ans += left_true*right_true + left_false*right_false;
                break;
            }
        }
    }
    int t = (isTrue==true? 1:0);
    return dp3[i][j][t] = ans;
}

// 4. Scrambled Strings:
bool scramble(string a, string b){
    if(a.compare(b)==0){
        return true;
    }
    int n = a.length();
    bool flag = false;
    for (int i = 1; i <= n-1; i++)
    {
        bool c1 = scramble(a.substr(0, i), b.substr(n-i, i)) 
                && scramble(a.substr(i, n-i), b.substr(0, n-i));
        bool c2 = scramble(a.substr(0, i), b.substr(0, i)) 
                && scramble(a.substr(i, n-i), b.substr(i, n-i));
        if(c1 || c2){
            flag = true;
            break;
        }
    }
    return flag;
}

unordered_map<string, bool> mp;
bool scramble_mem(string a, string b){
    string key = a+" "+b;
    if(mp.find(key) != mp.end()){
        return mp[key];
    }
    if(a.compare(b)==0){
        return mp[key] = true;
    }
    int n = a.length();
    bool flag = false;
    for (int i = 1; i <= n-1; i++)
    {
        // Case 1: Swap Occured
        bool c1 = scramble_mem(a.substr(0, i), b.substr(n-i, i)) 
                && scramble_mem(a.substr(i, n-i), b.substr(0, n-i));
        // Case 1: Swap Not Occured
        bool c2 = scramble_mem(a.substr(0, i), b.substr(0, i)) 
                && scramble_mem(a.substr(i, n-i), b.substr(i, n-i));
        if(c1 || c2){
            flag = true;
            break;
        }
    }
    return mp[key] = flag;
}

// 5. Egg Dropping Problem:
int dp4[mod][mod] = {-1};
int egg_drop_tab(int egg, int floor){
    for (int i = 1; i <= egg; i++){
        for (int j = 0; j <= floor; j++)
        {
            if(i==1 || j==0 || j==1){
                dp4[i][j] = j;
            }
            else{
                for (int k = 1; k <= j; k++)
                {
                    dp4[i][j] = min(dp4[i][j], 1+max(dp4[i][j-k], dp4[i-1][k-1]));
                }
            }
        }
    }
    return dp4[egg][floor];
}

int main()
{
    // 1.
    // int arr[] = {40, 20, 30, 10 ,30};
    // for (int i = 0; i < mod; i++){
    //     for (int j = 0; j < mod; j++){
    //         dp1[i][j]=-1;
    //     }
    // }
    // cout<<mcm_rec(arr, 1, 4)<<endl;  // start = 1  &&  end = arr.length - 1 // pure recursive
    // cout<<mcm_mem(arr, 1, 4)<<endl;  // memoization

    // 2.
    // string s = "nitina";
    // for (int i = 0; i < mod; i++){
    //     for (int j = 0; j < mod; j++){
    //         dp2[i][j]=-1;
    //     }
    // }
    // cout<<pal_rec(s, 0, s.length()-1)<<endl;  // start = 0  &&  end = s.length - 1 // pure recursive
    // cout<<pal_mem(s, 0, s.length()-1)<<endl;  // memoization

    // 3.
    // string s = "T|F&T^F";
    // bool isTrue = true;
    // cout<<eval_bool(s, 0, s.length()-1, isTrue)<<endl;  
    // for (int i = 0; i < mod; i++){
    //     for (int j = 0; j < mod; j++){
    //         for (int t = 0; t < 2; t++)
    //         {
    //             dp3[i][j][t]=-1;
    //         }
    //     }
    // }
    // cout<<eval_bool_mem(s, 0, s.length()-1, isTrue)<<endl;  // memoization

    // 4.
    // string a="great", b="rgate";
    // if(a.length()!=b.length()){
    //     cout<<0<<endl;
    // }
    // else if(a == "" && b == ""){
    //     cout<<1<<endl;
    // }
    // else{
    //     cout<<scramble(a, b)<<endl;
    //     cout<<scramble_mem(a, b)<<endl;
    // }

    // 5.
    // for (int i = 0; i < mod; i++)
    // {
    //     for (int j = 0; j < mod; j++)
    //     {
    //         dp4[i][j] = INT_MAX;
    //     }
    // }
    // cout<<egg_drop_tab(2,100)<<endl;
    
    return 0;
}