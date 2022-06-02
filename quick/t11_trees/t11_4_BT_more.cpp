#include<bits/stdc++.h>
using namespace std;

// `Problems`:
// - https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
// - https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/
// - https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
// - https://www.interviewbit.com/problems/symmetric-binary-tree/
// - [Non Recursive BT Traversal]
// - Preorder-Inorder-Postorder Traversals in One Traversal [https://youtu.be/ySp2epYvgTE]
// - Preorder [https://www.interviewbit.com/problems/preorder-traversal/] [https://youtu.be/Bfqd8BsPVuw]
// - Inorder [https://youtu.be/lxTGsVXjwvM]
// - Postorder [https://www.interviewbit.com/problems/postorder-traversal/] [https://youtu.be/2YBhNLodD8Q] [https://youtu.be/NzIGLLwZBS8]
// - https://www.interviewbit.com/problems/bst-iterator/ [https://youtu.be/4L5seG1d2dA]
// - https://www.interviewbit.com/problems/populate-next-right-pointers-tree/ [https://youtu.be/vy2mnT3TEXQ] [Not a Perfect BT]
// - https://www.interviewbit.com/problems/next-pointer-binary-tree/ [https://youtu.be/30Bqbk-Vk3Q] [A Perfect BT]
// - https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
// - https://www.interviewbit.com/problems/order-of-people-heights/
// - https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
// - https://www.interviewbit.com/problems/hotel-reviews/
// - https://www.interviewbit.com/problems/diagonal-traversal/
// - https://www.interviewbit.com/problems/cousins-in-binary-tree/
// - https://www.interviewbit.com/problems/maximum-edge-removal/ [Graph | Improper Ques]
// - https://www.interviewbit.com/problems/burn-a-tree/
// - https://www.interviewbit.com/problems/nodes-at-distance-k/
// - https://www.interviewbit.com/problems/last-node-in-a-complete-binary-tree/
// - https://leetcode.com/problems/kth-ancestor-of-a-tree-node/ [https://youtu.be/oib-XsjFa-M]
// - https://www.spoj.com/problems/LCASQ/ [https://youtu.be/dOAxrhAUIhA]
// - Morris Traversal (Inorder traversal in O(1) space i.e. without recursion) [https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/]
/*
         7
     4      5
   1   2    0   3
      9    8
*/

//Preorder - 7 4 1 2 9 5 0 8 3
//Inorder - 1 4 9 2 7 8 0 5 3
//Postorder - 1 9 2 4 8 0 3 5 7

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

void inOrderTrav(Node* n){
    if (n!=NULL)
    {
        inOrderTrav(n->left);
        cout<<n->data<<" ";
        inOrderTrav(n->right);
    }
};

// Get Lowest Common Ancestor - O(n)
bool getPath(Node* root, int key, vector<int> &path){
    if(root==NULL){
        return false;
    }

    path.push_back(root->data);
    
    if(root->data == key){
        return true;
    }
    
    if(getPath(root->left, key, path) || getPath(root->right, key, path)){
        return true;
    }
    
    path.pop_back();
    return false;
}

int lowestCommonAncestor(Node* root, int key1, int key2){
    vector<int> path1, path2;

    if(!getPath(root, key1, path1) || !getPath(root, key2, path2)){
        return -1;
    }

    int commmon = -1;
    for (int i = 0; i<path1.size() && i<path2.size(); i++)
    {
        if(path1[i] != path2[i]){
            break;
        }
        commmon++;
    }
    
    return path1[commmon];
}

// Get Lowest Common Ancestor - O(n) - Another way faster
// Also check if the key k1 and k2 exist or not in BT, if any one of them do not exist then return -1
Node* LCA(Node* n, int k1, int k2){
    if(n==NULL){
        return NULL;
    }

    if(n->data == k1 || n->data == k2){
        return n;
    }

    Node* leftLCA = LCA(n->left, k1, k2);
    Node* rightLCA = LCA(n->right, k1, k2);

    if(leftLCA && rightLCA){
        return n;
    }
    else if(leftLCA){
        return leftLCA;
    }
    return rightLCA;
}

// Shortest dist b/w two nodes
int findDist(Node* lca, int k, int dist){
    if(lca==NULL){return -1;}
    if(lca->data==k){return dist;}

    int leftDist = findDist(lca->left, k, dist+1);
    if(leftDist != -1){return leftDist;}

    return findDist(lca->right, k, dist+1);
}

int dist(Node* root, int k1, int k2){
    Node* lca = LCA(root, k1, k2);

    int d1 = findDist(lca, k1, 0);
    int d2 = findDist(lca, k2, 0);

    return (d1+d2);
}

// Flatten a binary tree to a LL such that left pf each node is NULL and right is that node which happens to be next in preorder sequence
void flatten(Node* root){
    if(root == NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->left != NULL){
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* rightTail = root->right;
        while (rightTail->right!=NULL)
        {
            rightTail = rightTail->right;
        }
        
        rightTail->right = temp;
    }

    flatten(root->right);
}

// find all the nodes at dist k from a given node
void inSubtree(Node* root, int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    inSubtree(root->left, k-1);
    inSubtree(root->right, k-1);
}

int nodesAtK(Node* root, int target, int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==target){
        inSubtree(root, k);
        return 0;
    }

    int dl = nodesAtK(root->left, target, k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }else{
            inSubtree(root->right, k-dl-2);
        }
        return dl+1;
    }

    int dr = nodesAtK(root->right, target, k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }else{
            inSubtree(root->left, k-dr-2);
        }
        return dr+1;
    }

    return -1;
}

// Find max path sum possible from any node to any node
int maxPathSumUtil(Node* root, int &ans){
    if(root==NULL){
        return 0;
    }
    // returns path sum till that node only from any node
    int pathLeft = maxPathSumUtil(root->left, ans);
    int pathRight = maxPathSumUtil(root->right, ans);

    int getMax = max(max(root->data, root->data + pathLeft + pathRight),
              max(root->data + pathLeft, root->data + pathRight));

    ans = max(getMax, ans);

    return max(root->data, max(pathLeft + root->data, pathRight + root->data));
}

int maxPathSum(Node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

// Find max path sum possible from the leaf to leaf node
int maxPathSumUtil2(Node* root, int &ans){
    if(root==NULL){
        return 0;
    }
    // returns max path sum till that node only from the leaf node
    int pathLeft = maxPathSumUtil(root->left, ans);
    int pathRight = maxPathSumUtil(root->right, ans);

    ans = max(ans, root->data + pathLeft + pathRight);

    return max(pathLeft + root->data, pathRight + root->data);
}

int maxPathSum2(Node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

int main()
{
    Node* Root = createNode(7);
    Node* N1 = createNode(4);
    Node* N2 = createNode(5);
    Node* N3 = createNode(1);
    Node* N4 = createNode(2);
    Node* N5 = createNode(9);
    Node* N6 = createNode(0);
    Node* N7 = createNode(3);
    Node* N8 = createNode(8);

    Root->setPtr(N1, N2);
    N1->setPtr(N3, N4);
    N4->setPtr(N5, NULL);
    N2->setPtr(N6, N7);
    N6->setPtr(N8, NULL);

    // inOrderTrav(Root);
    // cout<<endl;

    // int k1 = 8;
    // int k2 = 3;
    // cout<<lowestCommonAncestor(Root, k1, k2)<<endl;

    // Node* n = LCA(Root, k1, k2);
    // if(n)
    //     cout<<n->data<<endl;
    // else
    //     cout<<"No Common Ancestor"<<endl;

    // cout<<dist(Root, k1, k2)<<endl;

    // flatten(Root);
    // inOrderTrav(Root);
    // cout<<endl;

    // nodesAtK(Root, 7, 2);
    // cout<<endl;

    cout<<maxPathSum(Root)<<endl;

    return 0;
}