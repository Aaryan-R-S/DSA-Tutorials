#include<bits/stdc++.h>
using namespace std;

// `Problems`
// - https://www.interviewbit.com/problems/unique-binary-search-trees/
// - [Catalan Num in 3 Ways] https://www.geeksforgeeks.org/program-nth-catalan-number/ | https://stackoverflow.com/questions/27371612/catalan-numbers-recursive-function-time-complexity

// Recursion - Very High Time complexity
int catalan(int n){
    if(n<=1){
        return 1;
    }

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        result += catalan(i)*catalan(n-1-i);
    }

    return result;
}

class Node{
    public:
        Node* left;
        int data;
        Node* right;
        
        void setData(int data){
            this->data = data;
        };

        void setPtr(Node* l, Node* r){
            this->left = l;
            this->right = r;
        };
};

Node* createNode(int data, Node* left = NULL, Node* right = NULL){
    Node* n = new Node();
    n->left = left;
    n->data = data;
    n->right = right;
    return n;
};

void preOrder(Node* n){
    if (n!=NULL)
    {
        cout<<n->data<<" ";
        preOrder(n->left);
        preOrder(n->right);
    }
};

// Construct all possible BST from given nodes
vector<Node*> constructBST(int start, int end){
    vector<Node*> trees;

    if(start>end){
        trees.push_back(NULL);    
        return trees;    
    }

    for(int i=start; i<=end; i++){
        vector<Node*> leftSubTrees = constructBST(start, i-1);
        vector<Node*> rightSubTrees = constructBST(i+1, end);

        for (int j = 0; j < leftSubTrees.size(); j++)
        {
            Node* left = leftSubTrees[j];
            for (int k = 0; k < rightSubTrees.size(); k++)
            {
                Node* right = rightSubTrees[k];

                Node* root = createNode(i);
                root->left = left;
                root->right = right;
                trees.push_back(root);
            }
        }
    }
    return trees;
}

int main()
{
    // for (int i = 0; i < 10; i++)
    // {
    //     cout<<catalan(i)<<" ";
    // }
    // cout<<"Done"<<endl;

    cout<<"Done"<<endl;
    vector<Node*> allPossibleBST = constructBST(1, 3);
    for (int i = 0; i < allPossibleBST.size(); i++)
    {
        cout<<i+1<<" -> ";
        preOrder(allPossibleBST[i]);
        cout<<endl;
    }
    cout<<"Done"<<endl;
    

    return 0;
}