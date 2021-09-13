#include<bits/stdc++.h>
using namespace std;
const int mod = 1002;

// 1. Ubounded Knapsack:
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
                   val[n-1] + knapsack_memoization(val, wt, n, w-wt[n-1]),
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
                    val[i-1] + dp1[i][j-wt[i-1]],   // change here dp1[i-1] -> dp1[i]
                    dp1[i-1][j]);
            }
            else{
                dp1[i][j] = dp1[i-1][j];
            }
        }
    }
    return dp1[n][w];
}

// 2. Rod Cutting Problem:
// Given price of cutting a given rod of len L into different pieces (of same or different lenghts) given in len_arr[], find the maximum profit possible
int dp2[mod][mod] = {-1};

int rod_cutting_tabulation(int profit[], int len_arr[], int rod_len, int N){
    for (int i = 0; i < N + 1; i++){
        for (int j = 0; j < rod_len + 1; j++){
            if (i==0||j==0){
                dp2[i][j] = 0;
            }
            else if(len_arr[i-1]<=j){
                dp2[i][j] = max(
                    profit[i-1] + dp2[i][j-len_arr[i-1]],  
                    dp2[i-1][j]);
            }
            else{
                dp2[i][j] = dp2[i-1][j];
            }
        }
    }
    return dp2[N][rod_len];
}

// 3. Coin Change Problem (Total number of ways to get sum):
int dp3[mod][mod] = {-1};
int max_coin_change_tabulation(int coin[], int sum, int n){
    for (int i = 0; i < n + 1; i++){
        for (int j = 0; j < sum + 1; j++){
            if (j==0){
                dp3[i][j] = 1;
            }
            else if (i==0){
                dp3[i][j] = 0;
            }
            else if(coin[i-1]<=j){
                dp3[i][j] = dp3[i][j-coin[i-1]] + dp3[i-1][j];
            }
            else{
                dp3[i][j] = dp3[i-1][j];
            }
        }
    }
    return dp3[n][sum];
}

// 4. Coin Change Problem (Minimum coins to get sum):
int dp4[mod][mod] = {-1};
int min_coin_change_tabulation(int coin[], int sum, int n){
    for (int i = 0; i < n + 1; i++){
        for (int j = 0; j < sum + 1; j++){
            if (j==0){
                dp4[i][j] = 0;
            }
            else if (i==0){
                dp4[i][j] = INT_MAX-1;
            }
            else if(i==1){
                if(j%coin[i-1]==0){
                    dp4[i][j] = j/coin[i-1];
                }
                else{
                    dp4[i][j] = INT_MAX-1;
                }
            }
            else if(coin[i-1]<=j){
                dp4[i][j] = min(
                    dp4[i][j-coin[i-1]]+1,
                    dp4[i-1][j]);
            }
            else{
                dp4[i][j] = dp4[i-1][j];
            }
        }
    }
    return dp4[n][sum];
}


int main()
{
    
    return 0;
}