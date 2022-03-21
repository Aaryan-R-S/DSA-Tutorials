#include<iostream>
using namespace std;

// Array length = n
// Total passes = n-1
// Total comparisons in ith pass = n-i (Every Case)
// Every Case(if not adaptive) - O(n^2) Best case if(adaptive)- O(n)
// Stable and Not Adaptive by default (but can be made)

void printArray(int* arr, int len){
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};

void bubbleSort(int* arr, int len){
    int temp;
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;   
            }
        }
    }
};

void bubbleSortAdaptive(int* arr, int len){
    int temp;
    bool sorted;
    for (int i = 0; i < len-1; i++)
    {
        sorted = true;
        for (int j = 0; j < len-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;   
                sorted = false;
            }
            
        }
        if(sorted){
            printf("Pass No. %d\n",i+1);
            return;
        }
    }
};

int main()
{
    int arr[] = {1,23,43,4,5};
    // int arr[] = {1,2,3,5,4};
    // int arr[] = {2,3,1,5,4};
    // int arr[] = {5,4,3,2,1};
    int len = sizeof(arr)/sizeof(int);

    printArray(arr, len);
    // bubbleSort(arr, len);
    bubbleSortAdaptive(arr, len);
    printArray(arr, len);

    return 0;
}