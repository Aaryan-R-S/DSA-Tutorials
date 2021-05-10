#include<bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int> prices){
    vector<int> res;
    stack<pair<int, int>> st;

    for (auto &price : prices)
    {
        int days = 1;
        while(!st.empty() && st.top().first<=price){
            days += st.top().second;
            st.pop();
        }
        st.push({price, days});
        res.push_back(days);
    }

    return res;
}

int main()
{
    vector<int> prices = {100,80,60,70,60,75,85};
    vector<int> res = stockSpan(prices);

    for (auto &i : res)
    {
        cout<<i<<" ";
    }cout<<endl;
    
    return 0;
}