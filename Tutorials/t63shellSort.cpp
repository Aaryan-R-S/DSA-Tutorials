#include<iostream>
#include<limits.h>
using namespace std;

// modified version of insertion sort
// for array of len = n
// Time - same as insertion sort (Worst-O(n^2) & Best-O(n)) 
// Better than insertion sort as less no. swaps are required

void printArray(int* A, int len){
    for (int i = 0; i < len; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
};

void shellSort(int A[], int len){
    int temp;
    for (int gap = len/2; gap>0; gap/=2)
    {
        for (int j = gap; j < len; j++)
        {
            for (int i = j-gap; i>=0; i-=gap)
            {
                if (A[i+gap]>=A[i])
                {
                    break;
                }
                else{
                    temp = A[i+gap];
                    A[i+gap] = A[i];
                    A[i] = temp;
                }
            }
        }
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
    shellSort(A, len);
    printArray(A, len);

    return 0;
}