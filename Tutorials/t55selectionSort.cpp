#include<iostream>
using namespace std;

// Array length = n
// Total passes = n-1
// Total comparisons in ith pass = n-i 
// Every Case - O(n^2) 
// Not Stable and Not Adaptive
// Sort in min no of swaps

void printArray(int* arr, int len){
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};

void selectionSort(int* arr, int len){
    int minIndex;
    int temp;
    for (int i = 0; i < len-1; i++)
    {
        minIndex = i;
        for (int j = i+1; j <= len-1; j++)
        {
            if (arr[j]<arr[minIndex])
            {
                minIndex = j;
            }
        }
        if(i!=minIndex){
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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
    selectionSort(arr, len);
    printArray(arr, len);

    return 0;
}