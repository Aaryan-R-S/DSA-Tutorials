#include<iostream>
using namespace std;

// COUNT NO OF INVERSIONS WHERE AN INVERSION IS SAID TO BE DONE IF:
// arr[i]>arr[j] && i<j 

void printArray(int* A, int len){
    for (int i = 0; i < len; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
};

int merge(int A[], int low, int mid, int high){
    int inv = 0;
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

            // a[i]>a[j] && i<j
            inv += mid-low+1-i;  
            // mid-low+1 = no. of elems in left sub-array(sorted)
            // -i signifies if a[i]>a[j] so is true for i+1,i+2,...,mid as left sub-array is sorted

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
    return inv;
};

int mergeSort(int A[], int low, int high){
    int inv = 0;
    int mid;
    if (low<high)
    {
        mid = (low+high)/2;
        inv += mergeSort(A, low, mid);
        inv += mergeSort(A, mid+1, high);
        inv += merge(A, low, mid, high);
    }  
    return inv;
};

int main()
{
    // int A[] = {3,2,1};
    int A[] = {3,5,6,9,1,2,7,8};
    int len = sizeof(A)/sizeof(int);

    printArray(A, len);
    // merge(A, 0, 2, len);
    cout<<mergeSort(A, 0, len-1)<<" inversions"<<endl;
    printArray(A, len);

    return 0;
}