#include<bits/stdc++.h>
using namespace std;

// Find the largest rectangle that can be formed from histogram of each bar's width as 1 and height represented as an array
// Also refer Aditya Verma's approach!

// `Problems`
// - https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

int get_max_rec(vector<int> v){
    stack<int> st;
    v.push_back(0);
    int n = v.size();
    int ans = 0;

    int i = 0;
    while(i<n){
        while(!st.empty() && v[st.top()]>v[i]){
            int t = st.top();
            int h = v[t];
            st.pop();
            if(st.empty()){
                ans = max(ans, h*i);
            }
            else{
                int len = i-st.top()-1;
                ans = max(ans, h*len);
            }
        }
        st.push(i);
        i++;
    }

    v.pop_back();
    return ans;
}

int main()
{
    // vector<int> v = {2,1,5,6,2,3};  //10
    // vector<int> v = {2,4};  //4
    vector<int> v = {2,4,3};  //6
    cout<<get_max_rec(v)<<endl;

    return 0;
}