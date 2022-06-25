#include <bits/stdc++.h>
using namespace std;
const int mod = 1002;

// Refer Aditya Verma Playlist -- 
// https://www.youtube.com/watch?v=F7wqWbqYn9g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go

// Dynamic Programming -
// 1. Memoization = Top-down = Enhanced recursion
// 2. Tabulation = Bottom-up = Enhanced for-loop

// A. Knapsack Problems:
// Three types -
// 1. Fractional Knapsack (see Greedy)
// 2. 01 Knapsack (DP)
// 3. Unbound Knapsack (DP)
int dp1[mod][mod] = {-1};

int knapsack_memoization(int val[], int wt[], int n, int w){
    if (w==0||n==0){
        return 0;
    }
    if (dp1[n][w] != -1){
        return dp1[n][w];
    }
    if (wt[n-1]<=w){
        return dp1[n][w] = max(
                   val[n-1] + knapsack_memoization(val, wt, n-1, w-wt[n-1]),
                   knapsack_memoization(val, wt, n-1, w));
    }
    else{
        return dp1[n][w] = knapsack_memoization(val, wt, n - 1, w);
    }
}

int knapsack_tabulation(int val[], int wt[], int n, int w){
    for (int i = 0; i < n + 1; i++){
        for (int j = 0; j < w + 1; j++){
            if (i==0||j==0){
                dp1[i][j] = 0;
            }
            else if(wt[i-1]<=j){
                dp1[i][j] = max(
                    val[i-1] + dp1[i-1][j-wt[i-1]],
                    dp1[i-1][j]);
            }
            else{
                dp1[i][j] = dp1[i-1][j];
            }
        }
    }
    return dp1[n][w];
}

// B. Subset Sum Problem:
// Check if there exists a subset whose sum is equal to given sum
bool dp2[mod][mod] = {false};

bool subset_sum_tabulation(int arr[], int n, int sum){
    for (int i=0; i<n+1; i++){
        for (int j=0; j<sum+1; j++){
            if (j==0){
                dp2[i][j] = true;
            }
            else if(i==0){
                dp2[i][j] = false;
            }
            else if(arr[i-1]<=j){
                dp2[i][j] = (dp2[i-1][j-arr[i-1]]) || dp2[i-1][j];
            }
            else{
                dp2[i][j] = dp2[i-1][j];
            }
        }
    }
    return dp2[n][sum];
}

// C. Equal Sum Partition Problem:
// Check if it is possible to divide arr into equal sum
bool dp3[mod][mod] = {false};

bool equal_sum_tabulation(int arr[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    if(sum%2!=0){
        return false;
    }
    sum/=2;
    // Same as subset problem
    for (int i=0; i<n+1; i++){
        for (int j=0; j<sum+1; j++){
            if (j==0){
                dp3[i][j] = true;
            }
            else if(i==0){
                dp3[i][j] = false;
            }
            else if(arr[i-1]<=j){
                dp3[i][j] = (dp3[i-1][j-arr[i-1]]) || dp3[i-1][j];
            }
            else{
                dp3[i][j] = dp3[i-1][j];
            }
        }
    }
    return dp3[n][sum];
}

// D. Count of Subset with given sum Problem:
// Count no of subsets whose sum is equal to given sum
int dp4[mod][mod] = {-1};
// No need to handle the case for zeros as we are couting "subsets" (unique elements) not the "partition" (where duplicate is allowed)
int count_subsets_tabulation(int arr[], int n, int sum){
    for (int i=0; i<n+1; i++){
        for (int j=0; j<sum+1; j++){
            if (j==0){
                dp4[i][j] = 1;
            }
            else if(i==0){
                dp4[i][j] = 0;
            }
            else if(arr[i-1]<=j){
                dp4[i][j] = dp4[i-1][j-arr[i-1]] + dp4[i-1][j];
            }
            else{
                dp4[i][j] = dp4[i-1][j];
            }
        }
    }
    return dp4[n][sum];
}

// E. Minimum Subset Difference:
// Find a partition whose difference of sum is minimum and report this minimum difference.
int min_subset_diff_tabulation(int arr[], int n){
    // s2-s1 must be minimum
    // but s2+s1 = sum
    // so sum-s1-s1 = sum-(2*s1) must be minimum
    // It means we have to look at max value of s1 which is less than sum/2
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    subset_sum_tabulation(arr, n, sum);
    // Now check last line from dp2[n][sum/2] to dp2[n][0]
    int sum_till = sum/2;
    while(sum_till>=0){
        if(dp2[n][sum_till]){
            return abs(sum-(2*sum_till)); 
        }
        sum_till--;
    }
}

// F. Count Subset Difference:
// Find no of partitions whose difference of sum is equal to given diff
int count_subset_diff(int arr[], int n, int diff){
    // s2-s1 = diff
    // but s2+s1 = sum
    // so s2 = (sum+diff)/2
    // Also you have to handle the case when we encounter zero because we can fix each zero in any partition in two ways
    // {0,0,2} = {+0,+0,2}, {+0,-0,2}, {-0,+0,2},{-0,-0,2}  Ans: 4
    // So get zeroCnt and add *= pow(2, zeroCnt) to the ans
    int sum = 0, zeroCnt = 0;
    for (int i = 0; i < n; i++){
        if(arr[i]==0){
            zeroCnt++;
        }
        sum += arr[i];
    }
    // Edge cases --
    if(diff>sum){
        return 0;
    }
    if((diff+sum)%2!=0){
        return 0;
    }
    sum = (diff+sum)/2;
    // Main Algo same as count subsets but slight modified for zero case also
    for (int i=0; i<n+1; i++){
        for (int j=0; j<sum+1; j++){
            if (j==0){
                dp4[i][j] = 1;
            }
            else if(i==0){
                dp4[i][j] = 0;
            }
            else if(arr[i-1]==0){
                dp4[i][j] = dp4[i-1][j];
            }
            else if(arr[i-1]<=j){
                dp4[i][j] = dp4[i-1][j-arr[i-1]] + dp4[i-1][j];
            }
            else{
                dp4[i][j] = dp4[i-1][j];
            }
        }
    }
    return pow(2, zeroCnt) * dp4[n][sum];
}

int main()
{

    return 0;
}