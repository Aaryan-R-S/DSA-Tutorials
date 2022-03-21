#include<iostream>
using namespace std;

// Array length = n
// Total passes = n-1
// Total comparisons in ith pass = i (Worst Case)
// Worst - O(n^2) 
// Best - O(n) 
// Stable and Adaptive

void printArray(int* arr, int len){
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};

void insertionSort(int* arr, int len){
    int key;
    int j;
    for (int i = 1; i <= len-1; i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = key;
        // printf("%d\n",i);
    }
    
};

int main()
{
    // int arr[] = {1,2,3,4,5};
    int arr[] = {1,2,3,5,4};
    // int arr[] = {2,3,1,5,4};
    // int arr[] = {5,4,3,2,1};
    int len = sizeof(arr)/sizeof(int);

    printArray(arr, len);
    insertionSort(arr, len);
    printArray(arr, len);

    return 0;
}