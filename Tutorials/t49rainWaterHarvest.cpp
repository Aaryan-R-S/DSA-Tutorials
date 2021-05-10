#include<bits/stdc++.h>
using namespace std;

// Find the volume of all container that can be formed from blocks of each width as 1 and height represented as an array

int get_max_rec(vector<int> v){
    stack<int> st;
    int n = v.size();
    int ans = 0;

    int i = 0;
    while(i<n){
        while(!st.empty() && v[st.top()]<v[i]){
            int cur = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff  = i-st.top()-1;
            ans += (min(v[st.top()], v[i])-v[cur]) * diff;
        }
        st.push(i);
        i++;
    }

    return ans;
}

int main()
{
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1}; //6
    // vector<int> v = {1, 0, 1, 0, 1}; //2
    cout<<get_max_rec(v)<<endl;

    return 0;
}