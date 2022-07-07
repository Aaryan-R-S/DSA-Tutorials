#include<bits/stdc++.h>
using namespace std;

// Pattern Matching - Find positions/occurences of string S in the string T 
// Bruteforce - O(S*T)
// Rabin Karp Algo - O(S+T)
// KMP Algo - O(S+T)

// KMP Algorithm builds *prefix array* table or *pi* table or Longest Prefix Suffix (*LPS*) table
// Explanation Refer -- Abdul Bari: KMP Algoritm Lecture;  CP-Algorithms
// prefix[i] is length of the longest *proper* prefix of the substring s[0....i] which is also a suffix of this substring
// prefix[0] = 0, because of the word proper. A proper prefix of a string is a prefix that is not equal to the string itself.
// prefix[i] = maximum k(<=i) such that s[0...k-1] = s[i-(k-1)...i]

// Naive Algorithm - O(S^3)
vector<int> prefix_function_naive(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 0; i < n; i++)
        for (int k = 0; k <= i; k++)
            if (s.substr(0, k) == s.substr(i-k+1, k))
                pi[i] = k;
    return pi;
}

// Prefix Func - O(S)
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++){
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// KMP ALGO = Prefix of "S" O(S) + Search in "T" O(T)  ===  O(S+T)
// Find if S occurs in T
void kmp(){
    string s = "aba";
    vector<int> ans_naive = prefix_function_naive(s);
    vector<int> ans = prefix_function(s);

    for (auto &i : ans_naive){
        cout<<i<<" ";
    }cout<<"\n";
    for (auto &i : ans){
        cout<<i<<" ";
    }cout<<"\n";
    
    string t = "apnaababacollegeaba";
    int i = 0, j = 0, pos = -1;
    while(i<t.size()){
        if(t[i]==s[j]){
            j++;
            i++;
        }
        else{
            if(j!=0){
                j = ans[j-1];
            }
            else{
                i++;
            }
        }
        if(j==s.size()){
            pos = i-s.size();
            break;
        }
    }
    cout<<pos<<endl;
}

// Find no of occurrences (and their positions) of S in T (Alt. Rabin Karp Algo)
void kmp2(){
    string s = "aba";
    string t = "apnaababacollegeaba";
    string combined = s+'#'+t;
    vector<int> ans_naive = prefix_function_naive(combined);
    vector<int> ans = prefix_function(combined);

    cout<<"[ ";
    for (auto &i : ans_naive){
        cout<<i<<" ";
    }cout<<"]\n";
    
    vector<int> pos;
    int found = 0;
    cout<<"[ ";
    for (int i=0;i<ans.size();i++){
        if(ans[i]==s.size()){
            pos.push_back(i-2*s.size());    // index = i+1 - len(s+'#') - len(s) = i - 2*len(s)
            found++;
        }
        cout<<i<<" ";
    }cout<<"]\n";
    
    cout<<found<<endl;

    cout<<"[ ";
    for (auto &i : pos){
        cout<<i<<" ";
    }cout<<"]\n";
    
}

int main()
{
    kmp();
    cout<<endl;
    kmp2();
    return 0;
}