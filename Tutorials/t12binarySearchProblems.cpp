#include<bits/stdc++.h>
using namespace std;

// Given an array of size n find the k elems such that dist b/w any 2 elems is max possible
bool isFeasible(int mid, int arr[], int n, int k){
    int pos = arr[0], elem = 1;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]-pos>=mid){
            pos = arr[i];
            elem++;
            if(elem==k){
                return true;
            }
        }
    }
    return false;
}

int largestMinDistance(int arr[], int n, int k){
    sort(arr, arr+n);
    
    int result = -1;
    int left = 1, right = arr[n-1]-arr[0];

    while(left<right){
        int mid = (left+right)/2;
        if(isFeasible(mid, arr, n, k)){
            result = max(result, mid);
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return result;
}

int main()
{
    int arr[] = {1,2,8,5,9};
    int n = 5;
    int k = 3;
    cout<<largestMinDistance(arr, n, k)<<endl;

    return 0;
}