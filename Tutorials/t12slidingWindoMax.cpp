#include<bits/stdc++.h>
using namespace std;

// Assume a sliding window of size k moving over an array of size n such that only k elems are visible at a time, find the max elems from that window each time
// E.g. n=5 k=2
// Array: 2 3 1 -5 6
// Ans: 3 3 1 6

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin>>i;
    }
    
    vector<int> ans;
    deque<int> q;
    for (int i = 0; i < k; i++)
    {
        while (!q.empty() && v[q.back()]<v[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(v[q.front()]);

    for (int i = k; i < n; i++)
    {
        if(q.front()==i-k){
            q.pop_front();
        }
        while (!q.empty() && v[q.back()]<v[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(v[q.front()]);
    }
    

    for (auto &i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}