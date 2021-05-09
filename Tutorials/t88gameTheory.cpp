#include<iostream>
using namespace std;

int coinGame(int arr[], int l, int r){
    if (l+1>=r)
    {
        return max(arr[l], arr[r]);
    }
    return max(
        arr[l] + min(coinGame(arr, l+2, r), coinGame(arr, l+1, r-1)),
        arr[r] + min(coinGame(arr, l, r-2), coinGame(arr, l+1, r-1))
        );
};

int main()
{
    int arr[] = {1,90,45,900,4,6};
    int len = sizeof(arr)/sizeof(int);
    cout<<coinGame(arr, 0, len-1)<<endl;
    return 0;
}