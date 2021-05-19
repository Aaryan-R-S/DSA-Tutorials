#include<bits/stdc++.h>
using namespace std;

// Indian Coin change problem
int minCoins(vector<int> arr, int amt){
    int num = 0;
    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 0; i < arr.size(); i++)
    {
        num += amt/arr[i];
        amt -= amt/arr[i] * arr[i];
    }
    return num;
}

// Activity selection problem - calculate max no of activites that can be selected without overlapping
int selection(vector<vector<int>> &v, int n){
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });

    int take = 1;
    int end = v[0][1];

    for (int i = 1; i < n; i++)
    {
        if(v[i][0]>=end){
            take++;
            end = v[i][1];
        }
    }
    return take;
}

// Fractional knapsack - same as that of recursion one but fraction is also allowed
int fracKnapsack(vector<pair<int,int>> &v, int w){
    sort(v.begin(), v.end(), [&](pair<int,int> &p1, pair<int,int> &p2){
        double v1 = (double) p1.first/p1.second;
        double v2 = (double) p2.first/p2.second;
        return v1>v2;
    });

    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if(w >= v[i].second){
            ans += v[i].first;
            w -= v[i].second;
            continue;
        }

        double vw = (double) v[i].first/v[i].second;
        ans += vw*w;
        w = 0;
        break;
    }
    return ans;
}

// You are given an arr of n files with their computation times, choose any two files add their time and append it to tje list of the computation times , repeat the process to obtain min comp. time at end
int minTime(vector<int> v){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < v.size(); i++)
    {
        minHeap.push(v[i]);
    }
    int ans = 0;
    while(minHeap.size()>1){
        int t1 = minHeap.top();
        minHeap.pop();
        int t2 = minHeap.top();
        minHeap.pop();
        ans += t1+t2;
        minHeap.push(t1+t2);
    }
    return ans;
}

int main()
{
    // int n; cin>>n;
    // vector<int> v(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>v[i];
    // }
    // int amt; cin>>amt;
    // cout<<minCoins(v, amt)<<endl;

    // int n; cin>>n;
    // vector<vector<int>> v(n);
    // for (int i = 0; i < n; i++)
    // {
    //     int st, end;
    //     cin>>st>>end;
    //     v[i].push_back(st);
    //     v[i].push_back(end);
    // }
    // cout<<selection(v, n)<<endl;

    // int n; cin>>n;
    // vector<pair<int, int>> v(n);
    // for (int i = 0; i < n; i++)
    // {
    //     int val, wt;
    //     cin>>val>>wt;
    //     v[i].first = val;
    //     v[i].second = wt;
    // }
    // int w; cin>>w;
    // cout<<fracKnapsack(v, w)<<endl;

    int n; cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    cout<<minTime(v)<<endl;

    return 0;
}