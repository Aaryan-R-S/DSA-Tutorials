#include<bits/stdc++.h>
using namespace std;

// Find sum of subarray of len k from arr of size n with property of having max sum less than X
int maxSumSubArr(int arr[], int n, int k, int x){
    int maxSum = 0, sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum+=arr[i];
    }

    if(sum<x){
        maxSum = sum;
    }

    for (int i = k; i < n; i++)
    {
        sum+=arr[i];
        sum-=arr[i-k];
        if(sum<x){
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}

// For a given array and an integer X find the min subarray size for wich sum>X
int minSubArrSize(int arr[], int n, int x){
    int minSize = INT_MAX, sum = 0;

    int start=0, end=0;
    while(end<n){
        sum+=arr[end];
        end++;
        while(sum>x){
            minSize = min(minSize, end-start);
            sum-=arr[start];
            start++;
        }
    }

    return minSize;
}

// For a given arr and an int k check if there exists a sub arr of size k whose nums when written consec(concatenate) form a no. divisible by 3 (if num sum is div by three then so is concatented num)
void divByThree(vector<int> arr, int k){
    pair<int, int> ans;
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    bool found = false;
    if(sum%3==0){
        ans = make_pair(0, k-1);
        found = true;
    }

    for (int i = k; i < arr.size(); i++)
    {
        if(found){
            break;
        }
        sum += arr[i] - arr[i-k];
        if(sum%3==0){
            ans = make_pair(i-k+1, i);
            found = true;
        }
    }
    
    if(!found){
        ans = make_pair(-1, 0);
    }

    if(ans.first==-1){
        cout<<"No such sub-array exists!"<<endl;
    }
    else{
        for (int i = ans.first; i <= ans.second; i++)
        {
            cout<<arr[i];
        }
        cout<<endl;
    }
}

int main()
{
    // int arr[] = {7,5,4,6,8,9};
    // int n = 6;
    // int k = 3;
    // int x = 20;
    // cout<<maxSumSubArr(arr, n, k, x)<<endl;
    
    // int arr[] = {7,5,4,6,8,9};
    // int n = 6;
    // int x = 20;
    // cout<<minSubArrSize(arr, n, x)<<endl;
    
    vector<int> arr = {7,5,2,1,4,9};
    int k = 3;
    divByThree(arr, k);

    return 0;
}