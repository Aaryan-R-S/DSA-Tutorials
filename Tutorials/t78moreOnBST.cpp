#include<bits/stdc++.h>
using namespace std;

/*
         7
     3        10
   1   5    9   15
      4    8
*/

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

void inOrder(Node* n){
    if (n!=NULL)
    {
        inOrder(n->left);
        cout<<n->data<<" ";
        inOrder(n->right);
    }
};

// Build Balanced BST from sorted array
Node* sortedArrToBST(int arr[], int start, int end){
    if(start>end){
        return NULL;
    }

    int mid = (start+end)/2;
    Node* root = createNode(arr[mid]);

    root->left = sortedArrToBST(arr, start, mid-1);
    root->right = sortedArrToBST(arr, mid+1, end);

    return root;
}

// Zig-zag traversal
void zigZag(Node* root){
    if(root==NULL)
        return;

    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    bool leftToRight = true;

    currLevel.push(root);

    while(!currLevel.empty()){
        Node* temp = currLevel.top();
        currLevel.pop();

        if(temp){
            cout<<temp->data<<" ";
            if(leftToRight){
                if(temp->left!=NULL){
                    nextLevel.push(temp->left);
                }
                if(temp->right!=NULL){
                    nextLevel.push(temp->right);
                }
            }
            else{
                if(temp->right!=NULL){
                    nextLevel.push(temp->right);
                }
                if(temp->left!=NULL){
                    nextLevel.push(temp->left);
                }
            }
        }

        if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }   

    }
    return;
}

int main()
{
    Node* Root = createNode(7);
    Node* N1 = createNode(3);
    Node* N2 = createNode(10);
    Node* N3 = createNode(1);
    Node* N4 = createNode(5);
    Node* N5 = createNode(4);
    Node* N6 = createNode(9);
    Node* N7 = createNode(15);
    Node* N8 = createNode(8);

    Root->setPtr(N1, N2);
    N1->setPtr(N3, N4);
    N4->setPtr(N5, NULL);
    N2->setPtr(N6, N7);
    N6->setPtr(N8, NULL);


    // int arr[] = {1,3,4,5,7,8,9,10,15};
    // Node* Root2 = sortedArrToBST(arr, 0, 8);

    // inOrder(Root2);
    // cout<<endl;

    zigZag(Root);
    cout<<endl;

    return 0;
}