#include<bits/stdc++.h>
using namespace std;

int main(){

    // ------------------------------------------------------------------------------
    // Primes -> 1e9+7, 1e5+3, 1e3+9
    // Important ranges:
    //     -1e9 < int < 1e9
    //     -1e12 < long int < 1e12
    //     -1e18 < long long int < 1e18
    //     1D array max size, arr[n]: n_max = 1e5  (global array: 1e7)
    //     2D array max size, arr[n][n]: n_max = 1e3
    
    // ------------------------------------------------------------------------------
    // fixed<<setprecision(decimal_places)<<variable
    // double n1 = 2.0/3;
    // cout<<fixed<<setprecision(2)<<n1<<endl;

    // ------------------------------------------------------------------------------
    // int l = 1e9;
    // int b = 1e9;
    // cout<<l*b<<endl;    // wrong due to int overflow
    // cout<<l*1LL*b<<endl;    // will work in long long
    // cout<<(long long)l*b<<endl;    // will work in long long

    // ------------------------------------------------------------------------------
    // int t; cin>>t;
    // cin.ignore();   // without this \n (after the t in input) will be taken, input wastage

    // while(t--){
    //     string s;
    //     getline(cin, s);
    //     cout<<s<<endl;
    // }

    // ------------------------------------------------------------------------------
    // Logic -- 5th bit difference in small case and upper case letters
    // 'A' - 1000001
    // 'a' - 1100001
    // ' ' - 0100000
    // '_' - 1011111

    // Convert to lowercase - set 5th bit
    char A = 'A';
    cout<<char(A|' ')<<endl;

    // Convert to uppercase - reset 5th bit
    char a = 'a';
    cout<<char(a&'_')<<endl;

    return 0;
}