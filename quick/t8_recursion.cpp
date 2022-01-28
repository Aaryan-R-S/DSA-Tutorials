#include<bits/stdc++.h>
using namespace std;

// Q1) To calculate (a^n) % MOD ------------------------------------------------------------------
// Time complexity - O(N)
int pow(int a, int n){
    if(n==0){return 1;}
    return a*pow(a, n-1);
};

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

// Q2) Print all permutation of a given string ----------------------------------------------------
// Time complexity - O(N!)
void permutationOfString(string s, string ans){
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        string r = s.substr(0, i) + s.substr(i+1, s.length());
        permutationOfString(r, ans+c);
    }

    return;
}

// Q3) Permutation of integer (distinct) arrays  ---------------------------------------------------
// Time complexity - O(N!)
void permutationOfIntArr(vector<int> &v, int index, vector<vector<int>> &ans){
    if (index == v.size()){
        ans.push_back(v);
        return;
    }
    for (int i = index; i < v.size(); i++)
    {

        swap(v[i], v[index]);
        permutationOfIntArr(v, index+1, ans);
        swap(v[i], v[index]);
    }
    return;
}

// [Important]
// Q4) Permutation of integer (may not be distinct) arrays  ----------------------------------------
void helper(vector<int> v, vector<vector<int>> &answer, int index){
    if (index == v.size()){
        answer.push_back(v);
        return;
    }
    for (int i = index; i < v.size(); i++)
    {
        if(i!=index and v[i]==v[index]){
            continue;
        }
        swap(v[i], v[index]);
        helper(v, answer, index+1);
        // swap(v[i], v[index]);    // give Wrong Answer [Important]
    }
    return;
}

vector<vector<int>> permute(vector<int> nums){
    sort(nums.begin(), nums.end());     // [Important]
    vector<vector<int>> answer;
    helper(nums, answer, 0);
    return answer;
}

// STL Trick - works in all cases
void permutationOfIntArr(vector<int> &v, vector<vector<int>> &ans){
    sort(v.begin(), v.end());
    do{
        ans.push_back(v);
    } while (next_permutation(v.begin(), v.end()));
    return;   
}

// Q5) LINEAR PATH STARTING FROM S TO E. FIND NO. OF PATHS POSSIBLE WHERE EACH STEPS LENGTH RANGES FROM 1 TO 6
int countPath(int s, int e){
    if (s == e)
    {
        return 1;
    }
    if (s > e)
    {
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += countPath(s + i, e);
    }

    return count;
}

// Q6) MAZE STARTING FROM (1,1) TO (M,N) FIND NO. OF PATHS POSSIBLE WHERE EACH STEPS LENGTH IS 1 EITHER IN DOWN OR RIGHT DIRECTOIN
int path(int m, int n){
    if (m == 1 || n == 1)
    {
        return 1;
    }
    return path(m, n - 1) + path(m - 1, n);
};

// Q7) GIVE A BOARD OF SIZE 2XN AND TILE OF SIZE 2X1. FIND NO OF WAYS TO TILE THE GIVEN BOARD USING THESE TILES
// Order doesn't matter that is for n=2 ans should be 1 not 2 as we can rotate tile 90deg to get same configuration
int tilingWays(int n){
    if (n == 1 || n == 2){
        return 1;
    }
    return tilingWays(n - 1) + tilingWays(n - 2);
}

// Q8) FIND THE NO OF WAYS IN WHICH N FRIENDS CAN REMAIN SINGLE OR CAN BE PAIRED UP
int pairUp(int n){
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }
    return (pairUp(n - 1) + (n - 1) * pairUp(n - 2));
}

// Q9) PUT N ITEMS WITH GIVEN WEIGHT AND VALUE IN A KNAPSACK OF CAPACITY W TO GET THE MAX TOTAL VALUE IN THE KNAPSACK
int knapsackRec(int val[], int wt[], int n, int W){
    if (W == 0 || n == 0){
        return 0;
    }

    if(wt[n-1] > W){
        return 0;
    }

    return max(
        knapsackRec(val, wt, n-1, W-wt[n-1]) + val[n-1], 
        knapsackRec(val, wt, n-1, W) + 0
    );
}

int knapsackGreed(vector<pair<int,int>> &v, int w){
    sort(v.begin(), v.end(), [&](pair<int,int> &p1, pair<int,int> &p2){
        double v1 = (double) p1.first/p1.second;
        double v2 = (double) p2.first/p2.second;
        return v1>v2;
    });

    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if(w >= v[i].second){
            ans += v[i].first;
            w -= v[i].second;
        }
    }
    return ans;
}

// Q10) ---------------------------------------------
void rev_str(string s){
    if(s.length()==0){
        return;
    }
    rev_str(s.substr(1, s.length()));
    cout<<s[0];
}

// Q11) ---------------------------------------------
void replace_Pi(string s){
    if(s.length()==0 || s.length()==1){
        return;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        replace_Pi(s.substr(2, s.length()));
    }
    else{
        cout<<s[0];
        replace_Pi(s.substr(1, s.length()));
    }
}

// Q12) ---------------------------------------------
void tower_of_hanoi(int n, char src, char hepler, char dest){
    if(n==0){
        return;
    }
    tower_of_hanoi(n-1, src, dest, hepler);
    cout<<"Move ring no. "<<n<<" from "<<src<<" to "<<dest<<endl;
    tower_of_hanoi(n-1, hepler, src, dest);
}

// Q13) ---------------------------------------------
string remove_duplicates(string s){
    if(s.length()==0){
        return "";
    }

    char c = s[0];
    string ans = remove_duplicates(s.substr(1, s.length()));

    if(c == ans[0]){
        return ans;
    }
    else{
        return (c+ans);
    }
}

// Q14) ---------------------------------------------
string move_all_x_to_end(string s){
    if(s.length()==0){
        return "";
    }

    char c = s[0];
    string ans = move_all_x_to_end(s.substr(1, s.length()));

    if(c == 'x'){
        return (ans+c);
    }
    else{
        return (c+ans);
    }
}

// Q15) ---------------------------------------------
void subseq_str(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char c = s[0];
    string r = s.substr(1, s.length());

    subseq_str(r, ans);
    subseq_str(r, ans+c);
}

// Q16) ---------------------------------------------
void subseq_str_ascii(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char c = s[0];
    int ascii = c;

    string r = s.substr(1, s.length());

    subseq_str_ascii(r, ans);
    subseq_str_ascii(r, ans+c);
    subseq_str_ascii(r, ans+to_string(ascii));
}

// Q17) Game Theory ---------------------------------
int coinGame(int arr[], int l, int r){
    if (l+1>=r)
    {
        return max(arr[l], arr[r]);
    }
    return max(
        arr[l] + min(coinGame(arr, l+2, r), coinGame(arr, l+1, r-1)),
        arr[r] + min(coinGame(arr, l, r-2), coinGame(arr, l+1, r-1))
        );
};

int coinGameDP(int arr[], int l, int r, vector<vector<int>> &dp){
    if (l+1>=r)
    {
        dp[l][r] = max(arr[l], arr[r]);
    }
    else if(dp[l][r]==-1){
        dp[l][r] = max(
            arr[l] + min(coinGame(arr, l+2, r), coinGame(arr, l+1, r-1)),
            arr[r] + min(coinGame(arr, l, r-2), coinGame(arr, l+1, r-1))
            );
    }
    return dp[l][r];
};

int main(){
    // cout<<pow(3, 10)<<endl;      // 11 steps
    // cout<<powRec(3, 10, 1e9+7)<<endl;  // 4 steps

    // string s = "ABCD";
    // permutationOfString(s, "");

    // int n;
    // cin>>n;
    // vector<int> v(n);
    // for (auto &i : v)
    // {
    //     cin>>i;
    // }
    // vector<vector<int>> ans;
    // permutationOfIntArr(v, 0, ans);
    // for (auto &k : ans)
    // {
    //     for (auto &i : k)
    //     {
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }

    int n;
    cin>>n;
    vector<int> nums(n);
    for (auto &i : nums)
    {
        cin>>i;
    }
    vector<vector<int>> answer = permute(nums);
    // vector<vector<int>> answer;
    // permutationOfIntArr(nums, answer);
    for (auto &k : answer)
    {
        for (auto &i : k)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    // cout<<countPath(0, 3)<<endl;
    // cout<<path(200, 2)<<endl;
    // cout<<tilingWays(3)<<endl;
    // cout<<pairUp(3)<<endl;

    // int val[] = {100,50,150};
    // int wt[] = {10,20,30};
    // cout<<knapsackRec(val, wt, 3, 50)<<endl;
    
    // vector<pair<int,int>> v;
    // for (int i = 0; i < 3; i++){
    //     v.push_back(make_pair(val[i], wt[i]));
    // }
    // cout<<knapsackGreed(v, 50)<<endl;

    // rev_str("binod");
    // replace_Pi("pipokmcwpmcpoaurppincacfcniuwfn");
    // tower_of_hanoi(3, 'A', 'B', 'C');
    // cout<<remove_duplicates("aaaabbbbccccddddeeeefgggg")<<endl;
    // cout<<move_all_x_to_end("xjhvljxjlxzkjlhslx")<<endl;
    // subseq_str("abcd", "");
    // subseq_str_ascii("ab", "");

    // int arr[] = {1,90,45,900,4,6};
    // int len = sizeof(arr)/sizeof(int);
    // cout<<coinGame(arr, 0, len-1)<<endl;

    // vector<vector<int>> dp(len, vector<int>(len, -1));
    // cout<<coinGameDP(arr, 0, len-1, dp)<<endl;

    return 0;
}