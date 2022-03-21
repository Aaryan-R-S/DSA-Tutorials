#include<iostream>
#include<limits.h>
using namespace std;

// for array of len n and max elem k
// not valid for float but can be made valid for negative by subrtracting MinElem from each elem to make another array of positive no.s then after sorting again add MinElem to each elem to restore the array
// Time - all cases O(n+k) OR O(max(n, k))
// where k must be order of n (like for n=10 it must be less than 100 i.e. O(n) as 100 is O(n^2) )
// Space -  O(n+k)

void printArray(int* A, int len){
    for (int i = 0; i < len; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
};

int maximum(int A[], int len){
    int max = INT_MIN;
    for (int i = 0; i < len; i++)
    {
        if(max<A[i]){
            max = A[i];
        }
    }
    return max;
};

void countSortShortCut(int A[], int len){
    int max = maximum(A, len);
    int* count = new int[max+1];

    for (int i = 0; i < max+1; i++)
    {
        count[i]=0;
    }
    for (int i = 0; i < len; i++)
    {
        count[A[i]]+=1;
    }
    int k=0;
    for (int i = 0; i < max+1; i++)
    {
        int j = count[i];
        while (j!=0)
        {
            A[k] = i;
            j--;
            k++;
        }
    }
};

// Refer Jenny's lecture
void countSort(int A[], int len){
    int max = maximum(A, len);
    int count[max+1];

    // Initialize count array with 0s
    for (int i = 0; i < max+1 ; i++)
    {
        count[i]=0;
    }
    
    // Update count array according to no. of times a rentry occurs in array
    for (int i = 0; i < len; i++)
    {
        count[A[i]]++;
    }
    
    // Update count array to get indices by adding previous element to the current element
    for (int i = 1; i < max+1 ; i++)
    {
        count[i]+=count[i-1];
    }

    int B[len];
    // Get array in sorted manner starting from end to ensure stability
    for (int i = len-1; i>=0 ; i--)
    {
        B[--count[A[i]]] = A[i];
    }

    // Update original array
    for (int i = 0; i < len; i++)
    {
        A[i] = B[i];
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
    // countSortShortCut(A, len);
    countSort(A, len);
    printArray(A, len);

    return 0;
}