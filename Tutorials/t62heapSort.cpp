#include<iostream>
#include<limits.h>
using namespace std;

// For heapify O(logn) and we call it two times for each elem so O(2n*logn) = O(n*logn)
// So total Time complexity =  O(n*log(n)) 
// Heapify for Max heap - Ascending order
// Heapify for Min heap - Descending order
// refer Jenny's lecture

void printArray(int* A, int len){
    for (int i = 0; i < len; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
};

void maxHeapify(int A[], int len, int index){
    int largest = index;
    int left = (2*index)+1;
    int right = (2*index)+2;
    if (left<len && A[left]>A[largest])
    {
        largest = left;
    }
    if (right<len && A[right]>A[largest])
    {
        largest = right;
    }
    if(largest != index){
        int temp = A[largest];
        A[largest] = A[index];
        A[index] = temp;
        maxHeapify(A, len, largest);
    }
};

void heapSort(int A[], int len){
    // BUILD MAX HEAP starting from last non-leaf index
    for (int i = (len/2)-1; i >=0; i--)
    {
        maxHeapify(A, len, i);
    }

    // Delete MAX HEAP head and push it to the end of array being maxHeapified
    int temp;
    for (int i = len-1; i>=1; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        maxHeapify(A, i, 0);
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
    heapSort(A, len);
    printArray(A, len);

    return 0;
}