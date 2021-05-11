#include<bits/stdc++.h>
using namespace std;

// Given an array of size n find the length of max consec one's such that you can replace atmost k zeros by ones!
// Hint: see the problem as you have to find max sub array of 0's with atmost k zeros which can be convertd to 1's  

int main()
{
    int n;cin>>n;
    int k;cin>>k;

    vector<int> v(n);
    for (auto &i : v)
        cin>>i;

    int zeroCount = 0, i = 0, ans = 0;
    for (int j = 0; j < n; j++)
    {
        if(v[j]==0){
            zeroCount++;
        }
        if(zeroCount>k){
            if(v[i]==0)
                zeroCount--;
            i++;
        }
        ans = max(ans, j-i+1);
    }cout<<ans<<endl;
    
    return 0;
}