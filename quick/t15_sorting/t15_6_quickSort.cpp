#include<iostream>
using namespace std;

// Array length = n
// Not Stable and Not Adaptive
// Worst Case (Sorted Array)- O(n^2) 
// Best Case - O(n*log(n)) 
// Average Case - O(n*log(n)) 
// Not Stable and Not Adaptive 
// Inplace algorithm

void printArray(int* arr, int len){
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int temp;
    int i = low+1;
    int j = high;

    // do while two avoid clash when there are only two elems in sorted manner
    do
    {
        while (arr[i]<=pivot && i<high)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        
        if (i<j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    while (i<j);
        
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
};

void quickSort(int arr[], int low, int high){
    int partionIndex;  // Index of pivot after partition

    if (low<high){
        partionIndex = partition(arr, low, high);
        quickSort(arr, low, partionIndex-1);  // sort left sub-array
        quickSort(arr, partionIndex+1, high);   // sort right sub-array
    }
};

int main()
{
    // int arr[] = {1,2,3,4,5};
    // int arr[] = {1,2,3,5,4};
    // int arr[] = {2,3,1,5,4};
    int arr[] = {5,4,3,2,1};
    // int arr[] = {3,2};
    // int arr[] = {2,3};
    int len = sizeof(arr)/sizeof(int);

    printArray(arr, len);
    quickSort(arr, 0, len-1);
    printArray(arr, len);

    return 0;
}