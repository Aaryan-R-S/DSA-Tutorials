#include<bits/stdc++.h>
using namespace std;

// You are given an array of size N with numbers from 1 to N
// But some nums are missing and some other nums (range from 1 to N) are placed in place of them
// Task is to report duplicates and missing nums

// First approach is to use map that will take O(n) space and time complexity
// 1 5 4 4 3
// e.g. myMap[4] = 2 && myMap[2] = 0; so duplicate is 4 and missing is 2

// Another approach is swap sort that will O(n) time complexity but space complexity is O(1) only

void swapSort(int* arr, int len){
    int i = 0;
    while(i<len){
        if(arr[i]!=arr[arr[i]-1]){
            swap(arr[i], arr[arr[i]-1]);
        }
        else{
            i++;
        }
    }
}

void reportDuplicateandMissing(int* arr, int len){
    swapSort(arr, len);
    for (int i = 0; i < len; i++)
    {
        if(arr[i]!=i+1){
            cout<<"Missing-> "<<i+1<<" Duplicate-> "<<arr[i]<<endl;
        }
    }
}

int main()
{
    int arr[] = {4,2,5,5,3,5,2,8,8};
    reportDuplicateandMissing(arr, sizeof(arr)/sizeof(int));
    
    return 0;
}