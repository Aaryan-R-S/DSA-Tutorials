#include<bits/stdc++.h>
using namespace std;

int MOD = 1e+7;
int base = 31;  // any no greater than 27 as a->1 not 0 (which means empty string)

// String Hashing -- a->1, b->2, ..., z->26
// Find unique strings
// Method 1 - sort array of strings (O(n*m*logn)) and then comparing each ith string with (i-1)th string (O(n)) so overall (O(n*m*logn + n)) ~ (O(n*m*logn)) where m is size of longest string
// Method 2 - String hashing (O(n*logn + n*m + n)) ~ (O(n*m))
long long calHash(string s, vector<long long> powers){
    long long hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash += ((s[i]-'a'+1)*powers[i])%MOD;
    }
    return hash;
}

void stringHash(){
    vector<long long> powers(1e5+3);
    powers[0] = 1;
    for (int i = 1; i < powers.size(); i++)
    {
        powers[i] = (powers[i-1]*base)%MOD;
    }
    
    vector<string> words = {"aa","ab","aa","b","cc","aa"};
    vector<long long> hashes;
    for (auto &w : words){
        hashes.push_back(calHash(w, powers));
    }
    sort(hashes.begin(), hashes.end());

    int distinct = 0;
    for (int i = 0; i < hashes.size(); i++)
    {
        if(i==0 or hashes[i]!=hashes[i-1]){
            distinct++;
        }
    }
    cout<<distinct<<endl;
}

int main()
{
    stringHash();
       
    return 0;
}