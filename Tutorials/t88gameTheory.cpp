#include<bits/stdc++.h>
using namespace std;

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

int main()
{
    int arr[] = {1,90,45,900,4,6};
    int len = sizeof(arr)/sizeof(int);
    cout<<coinGame(arr, 0, len-1)<<endl;

    vector<vector<int>> dp(len, vector<int>(len, -1));
    cout<<coinGameDP(arr, 0, len-1, dp)<<endl;

    return 0;
}