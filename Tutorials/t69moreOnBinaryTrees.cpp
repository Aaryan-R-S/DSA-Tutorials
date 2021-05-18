#include<bits/stdc++.h>
using namespace std;

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

// Level-order binary tree traversal
void levelOrderTrav(Node* root){
    if(root==NULL){
        cout<<"No Node present!"<<endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* n = q.front();
        q.pop();

        if(n!=NULL){
            cout<<n->data<<" ";
            if(n->left!=NULL)
                q.push(n->left);
            if(n->right!=NULL)
                q.push(n->right);
        }
        else {
            if (!q.empty())
                q.push(NULL);
            
        }
    }
    return;
}

// Sum of all nodes at kth level
int sumAtLevel(Node* root, int k){
    int level = 0;
    int sum = 0;

    if(root==NULL){
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* n = q.front();
        q.pop();

        if(n!=NULL){
            if(level==k){
                sum += n->data;
            }
            if(n->left!=NULL)
                q.push(n->left);
            if(n->right!=NULL)
                q.push(n->right);
        }
        else if (!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

// No. of nodes in a binary tree
int noOFNodes(Node* n){
    if(n==NULL){
        return 0;
    }
    return (noOFNodes(n->left) + noOFNodes(n->right) + 1);
}

// Sum of all nodes in Binary tree
int sumOFNodes(Node* n){
    if(n==NULL){
        return 0;
    }
    return (sumOFNodes(n->left) + sumOFNodes(n->right) + n->data);
}

// Height of a binary tree - O(n)
int height(Node* n){
    if(n==NULL)
        return 0;

    int leftHeight = height(n->left);
    int rightHeight = height(n->right);

    return (max(leftHeight, rightHeight) + 1);
}

// Diameter of a binary tree - O(n^2)
int diameter(Node* n){
    if(n==NULL)
        return 0;

    int leftHeight = height(n->left);
    int rightHeight = height(n->right);
    int currDiameter = leftHeight+rightHeight+1;
    int leftDiameter = diameter(n->left);
    int rightDiameter = diameter(n->right);

    return max(currDiameter, max(leftDiameter, rightDiameter));
}

// Diameter of a binary tree - O(n)
int diameterFast(Node* n, int* height){
    if(n==NULL){
        *height = 0;
        return 0;
    }

    int leftHeight = 0, rightHeight = 0;

    int leftDiameter = diameterFast(n->left, &leftHeight);
    int rightDiameter = diameterFast(n->right, &rightHeight);

    int currDiameter = leftHeight+rightHeight+1;

    *height = max(leftHeight, rightHeight)+1;
    return max(currDiameter, max(leftDiameter, rightDiameter));
}

// Sum replacement
void sumReplacement(Node* n){
    if(n==NULL)
        return;

    sumReplacement(n->left);
    sumReplacement(n->right);

    if(n->left!=NULL)
        n->data += n->left->data;

    if(n->right!=NULL)
        n->data += n->right->data;

    return;
}

// Balanced Height Tree - O(n^2)
bool isBalanced(Node* n){
    if(n==NULL){
        return true;
    }

    if( !(isBalanced(n->left)&&isBalanced(n->right)) ){
        return false;
    }

    int leftHeight = height(n->left);
    int rightHeight = height(n->right);

    return (abs(leftHeight-rightHeight) <= 1);
}

// Balanced Height Tree - O(n)
bool isBalancedFast(Node* n, int* height){
    if(n==NULL){
        *height = 0;
        return true;
    }

    int leftHeight = 0, rightHeight = 0;

    if( !(isBalancedFast(n->left, &leftHeight) && isBalancedFast(n->right, &rightHeight)) ){
        return false;
    }

    *height = max(leftHeight, rightHeight) + 1;
    return (abs(leftHeight-rightHeight) <= 1);
}

// Left view of Tree
void leftView(Node* root){
    if(root==NULL){
        cout<<"No Node present!"<<endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node* curr = q.front();
            q.pop();
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
            if(i==0)
                cout<<curr->data<<" ";
        }
    }

    return;
}

// Right view of Tree
void rightView(Node* root){
    if(root==NULL){
        cout<<"No Node present!"<<endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node* curr = q.front();
            q.pop();
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
            if(i==n-1)
                cout<<curr->data<<" ";
        }
    }

    return;
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

    // cout<<noOFNodes(Root)<<endl;
    // cout<<sumOFNodes(Root)<<endl;

    // levelOrderTrav(Root);
    // cout<<endl;
    // cout<<sumAtLevel(Root, 3)<<endl;

    // cout<<height(Root)<<endl;
    // cout<<diameter(Root)<<endl;

    // int height = 0;
    // cout<<diameterFast(Root, &height)<<endl;

    // inOrderTrav(Root);
    // cout<<endl;
    // sumReplacement(Root);
    // inOrderTrav(Root);
    // cout<<endl;

    // cout<<isBalanced(Root)<<endl;

    // int height = 0;
    // cout<<isBalancedFast(Root, &height)<<endl;

    // rightView(Root);
    // cout<<endl;
    leftView(Root);
    cout<<endl;

    return 0;
}