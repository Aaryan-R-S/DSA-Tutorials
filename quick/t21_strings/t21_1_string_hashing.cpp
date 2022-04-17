#include<bits/stdc++.h>
using namespace std;

// `Problems`:
// - https://www.interviewbit.com/problems/multiply-strings/
// - https://www.interviewbit.com/problems/roman-to-integer/
// - https://www.interviewbit.com/problems/integer-to-roman/
// - https://www.interviewbit.com/problems/zigzag-string/
// - https://www.interviewbit.com/problems/longest-palindromic-substring/
// - https://www.interviewbit.com/problems/compare-version-numbers/
// - https://www.interviewbit.com/problems/atoi/
// - https://www.interviewbit.com/problems/valid-ip-addresses/
// - https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/ [https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/] [same for appending characters at the end only - https://www.interviewbit.com/problems/minimum-appends-for-palindrome/]
// - https://www.interviewbit.com/problems/convert-to-palindrome/
// - https://www.interviewbit.com/problems/bulls-and-cows/

int MOD = 1e+7;
int base = 31;  // any no greater than 27 as a->1 not 0 (which means empty string)

// String Hashing -- a->1, b->2, ..., z->26
// 31 is preferred as its a sufficiently greater prime than 26

// Find unique strings
// Method 1 - sort array of strings (O(n*m*logn)) and then comparing each ith string with (i-1)th string (O(n*m)) so overall (O(n*m*logn + n*m)) ~ (O(n*m*logn)) where m is size of longest string
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

// Rabin Karp Algo to find the occurences of a string s in string t in O(s+t) where brute force will give you o(s*t)
void occurences(){
    vector<long long> powers(1e5+3);
    powers[0] = 1;
    for (int i = 1; i < powers.size(); i++)
    {
        powers[i] = (powers[i-1]*base)%MOD;
    }

    string s = "na";
    string t = "apnacollegena";
    int S = s.size(), T = t.size();

    vector<long long> hashes(T+1, 0);
    for (int i = 0; i < T; i++)
    {
        hashes[i+1] = (hashes[i] + (t[i]-'a'+1)*powers[i])%MOD;
    }
    
    long long hash_s = 0;
    for (int i = 0; i < S; i++)
    {
        hash_s = (hash_s + (s[i]-'a'+1)*powers[i])%MOD;
    }
    
    for (int i = 0; i+S <= T; i++)
    {
        long long curr_h = (hashes[i+S] - hashes[i] + MOD)%MOD; // To overcome negative ans 
        if(curr_h == (hash_s*powers[i])%MOD){
            cout<<i<<" ";
        }
    }
    
}

int main()
{
    stringHash();

    occurences();
       
    return 0;
}