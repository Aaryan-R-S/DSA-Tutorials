#include<iostream>
using namespace std;

// FIND THE MAX SUM SUBARRAY IN O(N) TIME COMPLEXITY for array containing both +ve and -ve integers

// Kadane’s Algorithm can be viewed both as a `greedy` and `DP`. As we can see that we are keeping a running sum of integers and when it becomes less than 0, we reset it to 0 (Greedy Part). This is because continuing with a negative sum is way more worse than restarting with a new range. Now it can also be viewed as a DP, at each stage we have 2 choices: Either take the current element and continue with previous sum OR restart a new range. These both choices are being taken care of in the implementation. 

// `Problems`
// - [Product instead of Sum] https://www.interviewbit.com/problems/max-product-subarray/

int kadane(int a[], int n){
    int currentSum = 0, st = 0, s = 0, end = 0;
    int maxSum = INT16_MIN;

    for (int i = 0; i < n; i++){
        currentSum += a[i];

        if(currentSum > maxSum){
            maxSum = currentSum;
            st = s;
            end = i;
        }

        if (currentSum<0){
            currentSum=0;
            s = i+1;
        }
    }
    
    cout<<maxSum<<endl;
    cout<<st<<endl;
    cout<<end<<endl;
    cout<<endl;

    return maxSum;
}

int main(){
    int n;
    cin>>n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    // --------------- KADANE ALGO on simple array --------------------------------
    kadane(a, n);

    // --------------- KADANE ALGO on circular array --------------------------------
    int nonWrapSum = kadane(a, n);
    int wrapSum;

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