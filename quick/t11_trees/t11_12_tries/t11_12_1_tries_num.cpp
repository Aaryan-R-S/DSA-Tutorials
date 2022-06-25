#include<bits/stdc++.h>
using namespace std;

// `Problems`:
// - [!]https://youtu.be/akoIMy9NmFc
// - https://www.interviewbit.com/problems/shortest-unique-prefix/
// - https://www.interviewbit.com/problems/xor-between-two-arrays/

#define INT_SIZE 32
class Node{
public:
    Node *next[2];
    Node(){
        this->next[0] = NULL;
        this->next[1] = NULL;
    }
};

Node* buildTrie(vector<int> &a){
    Node* root = new Node();
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        Node* curr = root;
        for (int j = INT_SIZE; j >= 0; j--)
        {
            int bit = (num>>j)&1;
            if(curr->next[bit] == NULL){
                curr->next[bit] = new Node();
            }
            curr = curr->next[bit];
        }
    }
    return root;
}

// Find max xor of two nums from a arr
int xorTwoNums(Node* root, vector<int> &a){
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int num = a[i];
        Node* it = root;
        int curr_max = 0;
        for (int j = INT_SIZE; j >= 0; j--)
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
    Node* root = buildTrie(a);
    cout<<xorTwoNums(root, a)<<endl;

    return 0;
}