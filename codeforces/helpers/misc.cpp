#include<bits/stdc++.h>
using namespace std;

pair<int,int> simplify_fraction(pair<int,int> a){
    int gcd = __gcd(a.first, a.second);
    return make_pair(a.first/gcd, a.second/gcd);
};

int main(){

    pair<int,int> a = make_pair(12,18);
    cout<<a.first<<"/"<<a.second<<endl;
    a = simplify_fraction(a);
    cout<<a.first<<"/"<<a.second<<endl;

    return 0;
}