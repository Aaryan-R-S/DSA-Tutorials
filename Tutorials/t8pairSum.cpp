#include<iostream>
using namespace std;

// FIND INDICES OF THOSE PAIR OF ELEMENTS IN SORTED ARRAY 'A' OF LEN 'N' WHOSE SUM IS EQUAL TO 'K' 
bool pairSum(int a[], int n, int k){
    int low = 0;
    int high = n-1;

    while (low<high)
    {
        if(a[low]+a[high] == k){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(a[low]+a[high] > k){
            high--;
        }
        else{
            low++;
        }
    }
    return false;

}

int main()
{
    int n, k;
    cin>>n;
    cin>>k;

    // ARRAY MUST BE SORTED 
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    cout<<pairSum(a, n, k)<<endl;
    
    return 0;
}