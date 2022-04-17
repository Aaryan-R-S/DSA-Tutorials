#include<bits/stdc++.h>
using namespace std;

// Refer William Fest YT Playlist

// 1.
// A suffix array is an array which contains all the *sorted* suffixes of a string
// E.g. "camel" -> ["amel","camel","el","l","mel"]
// Actual suffix array -> [1,0,3,4,2]
// E.g.  "ABABBAB"
//     Suffix array   Suffixes (sorted)
//          1          "amel"
//          0          "camel"
//          3          "el"
//          4          "l"
//          2          "mel"

// 2.
// LCP array = Longest common prefix array
// It is an array in which every index tracks how many common characters two sorted adjacent suffixes have (in a suffix array) 
// LCP[0] = 0
// E.g.  "ABABBAB"
//     Suffix array         LCP Value            Suffixes (sorted)
//          5                   0                 "AB"
//          0                   2                 "ABABBAB"
//          2                   2                 "ABBAB"
//          6                   0                 "B"
//          4                   1                 "BAB"
//          1                   3                 "BABBAB"
//          3                   1                 "BBAB"


// Application: finding number of unique substrings in a given substring
// Total no of unique substrings = {s*(s+1)/2} - {sum of LCP[i] from i=0 to n-1}
// E.g. "AZAZA", s = 5
// Unique substrings = 5*6/2 - (1+3+0+2+0) = 15-6 = 9

// Time complexity - O(n*log(n)) 
// Space complexity - O(n) 
// Implementation of Suffix Array only (Just copy paste; no read)
void printArr(vector<int> arr){
    cout<<"[ ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "]\n";
}
 
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

int main()
{
    string s = "ABABBAB";
    vector<int> sa = suffix_array_construction(s); 
    printArr(sa);

    return 0;
}
