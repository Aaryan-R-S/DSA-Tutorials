#include<bits/stdc++.h>
using namespace std;

// `Problems`:
// - [!]https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
// - [!]https://www.interviewbit.com/problems/find-duplicate-in-array/
// - [!]https://www.interviewbit.com/problems/repeat-and-missing-number-array/ OR [Use Swap sort if array is not constant or read-only]
// - [!]https://www.interviewbit.com/problems/set-matrix-zeros/
// - [!]https://www.interviewbit.com/problems/maximum-consecutive-gap/ [https://youtu.be/wB-JSSNphI4]
// - [!]https://www.interviewbit.com/problems/n3-repeat-number/ [Moore's Voting Algorithm | https://www.geeksforgeeks.org/n3-repeated-number-array-o1-space/]
// - [!]https://www.interviewbit.com/problems/hotel-bookings-possible/
// - [!]https://www.interviewbit.com/problems/next-permutation/
// - [!]https://www.interviewbit.com/problems/max-distance/
// - [!]https://www.interviewbit.com/problems/find-permutation/
// - [!]https://www.interviewbit.com/problems/maximum-absolute-difference/
// - [!]https://www.interviewbit.com/problems/maximum-unsorted-subarray/
// - [!]https://www.interviewbit.com/problems/partitions/
// - [!]https://www.interviewbit.com/problems/set-intersection/
// - [!]https://www.interviewbit.com/problems/maximum-area-of-triangle/ [https://www.geeksforgeeks.org/maximum-area-triangle-different-vertex-colors/]
// - https://www.interviewbit.com/problems/merge-intervals/
// - https://www.interviewbit.com/problems/largest-number/
// - https://www.interviewbit.com/problems/first-missing-integer/
// - https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/
// - https://www.interviewbit.com/problems/make-equal-elements-array/
// - https://www.interviewbit.com/problems/segregate-0s-and-1s-in-an-array/
// - https://www.interviewbit.com/problems/rotate-matrix/
// - https://www.interviewbit.com/problems/sort-array-with-squares/
// - https://www.interviewbit.com/problems/maximum-sum-square-submatrix/
// - https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
// - https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
// - https://www.interviewbit.com/problems/array-3-pointers/ [https://youtu.be/BlXTlC6_Xv4]
// - https://www.interviewbit.com/problems/container-with-most-water/
// - https://www.interviewbit.com/problems/3-sum-zero/
// - https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
// - https://www.interviewbit.com/problems/subarrays-with-distinct-integers/ [https://youtu.be/akwRFY2eyXs]
// - https://www.interviewbit.com/problems/pair-with-given-difference/
// - https://www.interviewbit.com/problems/hotel-service/
// - https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/ [https://youtu.be/T3C7g8NohKw]
// - https://www.interviewbit.com/problems/counting-triangles/

// FIND INDICES OF THOSE PAIR OF ELEMENTS IN SORTED ARRAY 'A' OF LEN 'N' WHOSE SUM IS EQUAL TO 'K' 
bool pairSum(int a[], int n, int k){
    int low = 0;
    int high = n-1;

    while (low<high)
    {
        if(a[low]+a[high] == k){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(a[low]+a[high] > k){
            high--;
        }
        else{
            low++;
        }
    }
    return false;

}

// Find sub-array of desired sum   
void desiredSum(){
    int n;
    cin>>n;

    int ans;
    cin>>ans;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    
    int start = 0;
    int end = 0;
    int sum = arr[start];
    bool flag = 0;

    while (start!=n-1 || end!=n-1)
    {
        if (start!=end)
        {
            if (sum == ans)
            {
                cout<<start<<" "<<end<<endl;
                flag = 1;
                break;
            }
            else if(sum < ans){
                end++;
                sum += arr[end];
            }
            else{
                sum -= arr[start];
                start++;
            }
        }
        else{
            end++;
            sum += arr[end];
        }    
    }

    if (!flag)
    {
        if (sum == ans)
        {
            cout<<start<<" "<<end<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    
}

// Find min (first) index of repeating element   
void repeatingElem(){
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }    


    int N = 1e5;
    int indxArr[N];
    for (int i = 0; i < N; i++)
    {
        indxArr[i] = -1;
    }
    int minIndex = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        if (indxArr[arr[i]] != -1)
        {
            minIndex = min(minIndex, indxArr[arr[i]]);
        }
        else{
            indxArr[arr[i]] = i;
        }
    }
    if (minIndex == INT16_MAX)
    {
        cout<<"-1"<<endl;
    }
    else{
        cout<<minIndex<<endl;
    }
}

// FIND THREE ELEM FROM AN ARRAY OF SIZE N WHOSE SUM IS T
// O(n^2) -> Reduce the problem to two sum problem [O(n)] by traversing the array once [O(n)] after sorting it [O(n*logn)]
void threePointerSum(){
    int n, t;
    cin>>n;
    cin>>t;

    vector<int> v(n);
    for (auto &i : v)
    {
        cin>>i;
    }

    sort(v.begin(), v.end());

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        int low = i+1;
        int high = n-1;
        while(low<high){
            int sum = v[i] + v[low] + v[high];
            if(sum==t){
                found = true;
                break;
            }
            else if(sum<t){
                low++;
            }
            else{
                high--;
            }
        }
        if(found){
            break;
        }
    }
    cout<<(found==true?"True":"False")<<endl;
    

}

int main()
{
    // int n, k;
    // cin>>n;
    // cin>>k;

    // // ARRAY MUST BE SORTED 
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>a[i];
    // }
    
    // cout<<pairSum(a, n, k)<<endl;
    


    return 0;
}