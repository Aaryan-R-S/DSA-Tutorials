#include<bits/stdc++.h>
using namespace std;

// `Problems:`
// - https://www.interviewbit.com/problems/median-of-array/ [https://youtu.be/LPFhl65R7ww]
// - https://www.interviewbit.com/problems/rotated-array/ 
// - https://www.interviewbit.com/problems/matrix-median/ [https://youtu.be/79S7C6pvl2E]
// - https://www.interviewbit.com/problems/woodcutting-made-easy/
// - https://www.interviewbit.com/problems/search-in-bitonic-array/
// - https://www.interviewbit.com/problems/simple-queries/
// - https://www.interviewbit.com/problems/request-x-chocolates/
// - https://www.interviewbit.com/problems/red-zone/

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

    while(left<=right){
        int mid = (left+right)/2;
        if(isFeasible(mid, arr, n, k)){
            result = max(result, mid);
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return result;
}

// Divide n books (given an array of size n showing no of pages in each book in sorted order) to m students such that max pags allocated to a student is minimum
bool isPossible(int arr[], int n, int m, int mid){
    int students = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>mid){
            return false;
        }
        if(sum+arr[i] > mid){
            students++;
            sum = arr[i];
            if(students>m){
                return false;
            }
        }
        else{
            sum += arr[i];
        }
    }
    return true;
}

int allocateMinPages(int arr[], int n, int m){
    int sum = 0;

    if(n<m){
        return -1;
    }

    if(n==m){
        return (arr[n-1]);
    }

    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }

    int start = arr[0], end = sum, ans = INT_MAX;

    while(start<=end){
        int mid = (start+end)/2;
        if(isPossible(arr, n, m, mid)){
            ans = min(ans, mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

// n - len of n different boards
// m - no of painters available
// A painter paints 1 unit of board in 1 unit of time & each painter will paint consecutive boards. Find the min time that will be required to paint all the boards.(same as above ques)
bool isGood(int arr[], int n, int m, int mid){
    int painters = 1, area = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>mid){
            return false;
        }
        if(area+arr[i] > mid){
            painters++;
            area = arr[i];
            if(painters>m){
                return false;
            }
        }
        else{
            area += arr[i];
        }
    }
    return true;
}

int minTimeToPaint(int arr[], int n, int m){
    int area = 0;

    for (int i = 0; i < n; i++)
    {
        area+=arr[i];
    }

    int start = arr[0], end = area, ans = INT_MAX;

    while(start<=end){ 
        int mid = (start+end)/2;
        if(isGood(arr, n, m, mid)){
            ans = min(ans, mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

// We are given an ascending sorted arr that has been rotated from a pivot point (unknown) and an elem X. Search for X in the arr with complexity less than linear search
int searchInRotatedArr(int arr[], int key, int left, int right){
    if(left>right){
        return -1;
    }

    int mid = (left+right)/2;
    if(arr[mid]==key){
        return mid;
    }
    
    if(arr[left]<=arr[mid]){
        if(key>= arr[left] && key<= arr[mid]){
            return searchInRotatedArr(arr, key, left, mid-1);
        }
        return searchInRotatedArr(arr, key, mid+1, right);
    }

    if(key>= arr[mid] && key<= arr[right]){
        return searchInRotatedArr(arr, key, mid+1, right);
    }
    return searchInRotatedArr(arr, key, left, mid-1);
}

// Find the peak elem of an array which is elem greater than its immediate neighbours
// Following algo is guaranteed to work as for exactly one peak to exist the remaining arr must be in either ascending or descending order
int findPeak(int arr[], int n, int low, int high){
    if(low>high){
        return -1;
    }

    int mid = low+(high-low)/2;  
    // === (low+high)/2 but latter one has disadvantage of integer overflow for larger n

    if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid])){
        return mid;
    }

    else if(mid>0 && arr[mid-1]>arr[mid]){
        return findPeak(arr, n, low, mid-1);
    }
    
    return findPeak(arr, n, mid+1, high);
}

int main()
{
    // int arr[] = {1,2,8,5,9};
    // int n = 5;
    // int k = 3;
    // cout<<largestMinDistance(arr, n, k)<<endl;

    // int arr[] = {12,34,67,90};
    // int n = 4;
    // int m = 2;
    // cout<<allocateMinPages(arr, n, m)<<endl;

    // int arr[] = {10,20,30,40,50,60};
    // int n = 6;
    // int m = 3;
    // cout<<minTimeToPaint(arr, n, m)<<endl;

    // int arr[] = {6,7,8,9,10,1,2,5};
    // int n = 8;
    // int key = 5;
    // cout<<searchInRotatedArr(arr, key, 0, n-1)<<endl;

    // int arr[] = {6,3,0,2,5};
    // int n = 5;
    // cout<<findPeak(arr, n, 0, n-1)<<endl;

    return 0;
}