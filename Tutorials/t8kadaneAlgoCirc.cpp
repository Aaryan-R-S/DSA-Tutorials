#include<iostream>
using namespace std;

// FIND THE MAX SUM SUBARRAY IN O(N) TIME COMPLEXITY fpr a circular array 

int kadane(int a[], int n){
    int currentSum = 0;
    int maxSum = INT16_MIN;

    for (int i = 0; i < n; i++)
    {
        currentSum += a[i];
        if (currentSum<0)
        {
            currentSum=0;
        }
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int wrapSum;
    int nonWrapSum = kadane(a, n);

    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum+=a[i];
        a[i] = -a[i];
    }
    
    // applying kadane on negative of array will give sum of non contributing elems which will be positive but in actual arr it will be negative so
    // wrapSum = totalSum - (sum of non contributing elems)
    // wrapSum = totalSum - (-kadane(a, n));  
    wrapSum = totalSum + kadane(a, n);  

    cout<<max(wrapSum, nonWrapSum)<<endl;
    
    return 0;
}