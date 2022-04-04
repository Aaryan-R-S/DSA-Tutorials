#include<bits/stdc++.h>
using namespace std;

// `Problems`:
// - https://www.interviewbit.com/problems/min-stack/
// - https://www.interviewbit.com/problems/simplify-directory-path/
// - Find the largest rectangle that can be formed from histogram of each bar's width as 1 and height represented as an array [https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/] [Refer Aditya Verma's approach]
// - https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

// Also refer Aditya Verma's Approach of NGL, NGR, NSL, NSR 
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

// REVERSE A SENTENCE
void reverseSentence(string s)
{
    stack<string> st;
    int i = 0;
    while (i < s.length())
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);
        i++;
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}

// REVERSE A STACK
void insertAtBottom(stack<int> &st, int elem){
    if(st.empty()){
        st.push(elem);
        return;
    }
    int topElem = st.top();
    st.pop();
    insertAtBottom(st, elem);
    st.push(topElem);
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int elem = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, elem);
}

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
    // string s = "Hey, how are you doing?";
    // reverseSentence(s);

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }cout<<endl;
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;

    vector<int> prices = {100,80,60,70,60,75,85};
    vector<int> res = stockSpan(prices);

    for (auto &i : res)
    {
        cout<<i<<" ";
    }cout<<endl;
    
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1}; //6
    // vector<int> v = {1, 0, 1, 0, 1}; //2
    cout<<get_max_rec(v)<<endl;

    return 0;
}