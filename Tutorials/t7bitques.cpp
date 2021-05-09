#include<iostream>
using namespace std;

int uniqueOne(int arr[], int n){
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }
    return xorsum;
}

void uniqueTwo(int arr[], int n){
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }

    int setbit = 0;
    int pos = 0;
    while(!setbit){
        setbit = xorsum&(1<<pos);
        pos++;
    }
    pos--;

    int newXorSum = 0;
    for (int i = 0; i < n; i++)
    {
        if( (arr[i]&(1<<pos)) != 0 ){
            newXorSum ^= arr[i];
        }
    }

    cout<<newXorSum<<endl;
    cout<<(xorsum^newXorSum)<<endl;   
}

int uniqueThree(int arr[], int n){
    int result = 0;
    for (int i = 0; i < 64; i++)    // signifies there are 64 bit representation
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if( arr[j]&(1<<i) ){   // getBit()
                sum++;
            }
        }
        if(sum%3!=0){
            result = result | (1<<i) ;  // setBit()
        }
    }
    return result;
}

int main()
{
    // All nums are present twice except ONE, find that one num
    // int arr[] = {2,4,6,3,4,6,2};
    // cout<<uniqueOne(arr, 7)<<endl;

    // All nums are present twice except TWO, find that two nums
    // int arr[] = {2,4,6,7,4,5,6,2};
    // uniqueTwo(arr, 8);

    // All nums are present thrice except ONE, find that one num
    int arr[] = {1,3,2,3,4,2,1,1,3,2};
    cout<<uniqueThree(arr, 10)<<endl;

    return 0;
}