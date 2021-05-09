#include<iostream>
#include<limits.h>
using namespace std;

// for array of len = n 
// d = no.of digits in max num
// b = base or radix (e.g. 9 for decimal and 26 for alphabets)
// Time - all cases O(d*(n+b)) 
// Space -  O(n+b)

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

void countSort(int A[], int len, int pos, int base = 10){
    int count[base];

    // Initialize count array with 0s
    for (int i = 0; i < base ; i++)
    {
        count[i]=0;
    }
    
    // Update count array according to no. of times a entry occurs in array
    for (int i = 0; i < len; i++)
    {
        count[(A[i]/pos)%10]++;
    }
    
    // Update count array to get indices by adding previous element to the current element
    for (int i = 1; i < base ; i++)
    {
        count[i]+=count[i-1];
    }

    int B[len];
    // Get array in sorted manner starting from end to ensure stability
    for (int i = len-1; i>=0 ; i--)
    {
        B[--count[(A[i]/pos)%10]] = A[i];
    }

    // Update original array
    for (int i = 0; i < len; i++)
    {
        A[i] = B[i];
    }
};

void radixSort(int A[], int len){
    int max = maximum(A, len);
    for (int pos = 1; max/pos > 0; pos*=10)
    {
        countSort(A, len, pos);
    }
};

int main()
{
    // int A[] = {1,2,3,4,5};
    // int A[] = {1,2,3,5,4};
    // int A[] = {2,3};
    int A[] = {5,4,3,2,1};
    // int A[] = {432,8,530,90,88,231,11,45,677,199};
    // int A[] = {3,2};
    int len = sizeof(A)/sizeof(int);

    printArray(A, len);
    radixSort(A, len);
    printArray(A, len);

    return 0;
}