#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    int arr_xor = 0;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
        arr_xor ^= arr[i];
    }
    int t; cin>>t;
    cout<<__builtin_popcount(t^arr_xor)<<"\n";
    return 0;
}