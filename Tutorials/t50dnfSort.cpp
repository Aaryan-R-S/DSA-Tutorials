#include<iostream>
using namespace std;

// Array length = n
// Total types of elements = 3 
// Every Case - O(n)

void printArray(int* arr, int len){
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};

// Zero's|Ones's|Unkonown|Two's
// 000000 111111 ******** 22222
//        ^      ^        ^
//        low    mid      high

void DNFSort(int* arr, int len, int a=0, int b=1, int c=2){
    int low = 0;
    int mid = 0;
    int high = len-1;

    while (mid<=high)
    {
        if(arr[mid]==a){
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        }
        else if(arr[mid]==b){
            mid++;
        }
        else{
            int temp = arr[high];
            arr[high] = arr[mid];
            arr[mid] = temp;
            high--;
        }
    }
    

};


int main()
{
    int arr[] = {0,0,1,2,2,1,1,2,1,0,2};
    int len = sizeof(arr)/sizeof(int);

    printArray(arr, len);
    DNFSort(arr, len);
    printArray(arr, len);

    return 0;
}