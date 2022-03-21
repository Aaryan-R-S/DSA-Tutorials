#include<iostream>
using namespace std;

// Array length = n
// Stable but Not Adaptive
// All Cases - O(n*log(n)) 

void printArray(int* A, int len){
    for (int i = 0; i < len; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
};

void merge(int A[], int low, int mid, int high){
    int i=low;
    int j=mid+1;
    int k=low; 
    int B[10]; 

    while (i<=mid && j<=high)
    {
        if (A[i]<=A[j])
        {
            B[k] = A[i];
            i++; 
            k++;
        }
        else
        {
            B[k] = A[j];
            j++; 
            k++;
        }
    }

    while (i<=mid)
    {
        B[k] = A[i];
        k++;
        i++; 
    }
    while (j<=high)
    {
        B[k] = A[j];
        j++; k++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
};

void mergeSort(int A[], int low, int high){
    int mid;
    if (low<high)
    {
        mid = (low+high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }  
};

int main()
{
    // int A[] = {1,2,3,4,5};
    // int A[] = {1,2,3,5,4};
    // int A[] = {2,3};
    int A[] = {5,4,3,2,1};
    // int A[] = {3,2};
    int len = sizeof(A)/sizeof(int);

    printArray(A, len);
    // merge(A, 0, 2, len);
    mergeSort(A, 0, len-1);
    printArray(A, len);

    return 0;
}