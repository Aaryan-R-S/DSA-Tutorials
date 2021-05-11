#include<bits/stdc++.h>
using namespace std;

// Find the len of largest substr without any repeating char

int main()
{
    string s; cin>>s;
    vector<int> v(256, 0);

    int len = 1, start = 0, currLen = 0;
    for (int i = 0; i < s.length(); i++)
    {
        while(v[s[i]]!=0){
            v[s[start]] = 0;
            start++;
            currLen--;
        }
        currLen++;
        v[s[i]] = 1;
        len = max(len, currLen);
    }
    cout<<len<<endl;

    return 0;
}