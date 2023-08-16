#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int a; cin>>a;
        int b; cin>>b;
        cout<<__gcd(abs(a), abs(b))<<"\n";
    }
    return 0;
}