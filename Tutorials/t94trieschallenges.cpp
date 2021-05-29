#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode *next[2];
    TrieNode(){
        this->next[0] = NULL;
        this->next[1] = NULL;
    }
};

TrieNode* buildTrie(vector<int> &a){
    TrieNode* root = new TrieNode();
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        TrieNode* curr = root;
        for (int j = 31; j >= 0; j--)
        {
            int bit = (num>>j)&1;
            if(curr->next[bit] == NULL){
                curr->next[bit] = new TrieNode();
            }
            curr = curr->next[bit];
        }
    }
    return root;
}

int xorSubarr(TrieNode* root, vector<int> &a){
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int num = a[i];
        TrieNode* it = root;
        int curr_max = 0;
        for (int j = 31; j >= 0; j--)
        {
            int bit = (num>>j)&1 ? 0 : 1;
            if(it->next[bit]){
                curr_max <<= 1;  // left shift
                curr_max |= 1;  // set last bit to 1
                it = it->next[bit];
            }
            else{
                curr_max <<= 1;
                curr_max |= 0;  // set last bit to 0 // no effect, so absurd to write
                it = it->next[bit^1];
            }
        }
        ans = max(ans, curr_max);        
    }
    
    return ans;
}

int main()
{
    vector<int> a = {3,10,5,15,2};
    TrieNode* root = buildTrie(a);
    cout<<xorSubarr(root, a)<<endl;

    return 0;
}