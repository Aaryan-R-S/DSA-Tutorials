#include<iostream>
using namespace std;

// Array length = n
// Sort in wave manner -  big small big small big small big - like this
// Every Case - O(n/2) ~ O(n)

void printArray(int* arr, int len){
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};

void waveSort(int* arr, int len){
    for (int i = 1; i < len; i+=2)
    {
        if(arr[i]>arr[i-1]){
            int temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
        }
        if(!(i==len-1) && arr[i]>arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
};

int main()
{
    int arr[] = {1,3,4,7,5,6,2};
    int len = sizeof(arr)/sizeof(int);

    printArray(arr, len);
    waveSort(arr, len);
    printArray(arr, len);

    return 0;
}