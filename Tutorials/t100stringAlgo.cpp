#include<bits/stdc++.h>
using namespace std;

// KMP Algorithm builds prefix array
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
// Application of this func is find occurences of pattern s in t like Rabin Karp
// Hint: compute prefix array for s+'#'+t 

int main()
{

    return 0;
}