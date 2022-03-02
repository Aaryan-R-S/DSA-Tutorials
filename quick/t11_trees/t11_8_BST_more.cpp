#include<bits/stdc++.h>
using namespace std;

// `Problems`:
// - https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
// - https://www.interviewbit.com/problems/2sum-binary-tree/
// - https://www.interviewbit.com/problems/valid-bst-from-preorder/
// - https://www.interviewbit.com/problems/construct-bst-from-preorder/

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

// Find the size of largest BST in a BT
struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node* root){
    if(root==NULL){
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if(root->left == NULL && root->right == NULL){
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info currInfo;
    currInfo.size = (1 + leftInfo.size + rightInfo.size);
    
    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data){
        currInfo.min = min(leftInfo.min, min(rightInfo.min, root->data));
        currInfo.max = max(rightInfo.max, max(leftInfo.max, root->data));
        currInfo.ans = currInfo.size;
        currInfo.isBST = true;
        return currInfo;
    }

    currInfo.ans = max(leftInfo.ans, rightInfo.ans);
    currInfo.isBST = false;
    return currInfo;
}

// Correct a BST whose two nodes are swapped
void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

void calcPointers(Node* root, Node** first,  Node** mid, Node** last, Node** prev){
    if(root==NULL){
        return;
    }
    calcPointers(root->left, first, mid, last, prev);

    if(*prev && root->data < (*prev)->data){
        if(!*first){
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }
    }

    *prev = root;
    calcPointers(root->right, first, mid, last, prev);
    return;
}

void correctBST(Node* root){
    Node *first, *mid, *last, *prev;
    first = mid = last = prev = NULL;

    calcPointers(root, &first, &mid, &last, &prev);

    // case 1 - not adjacent in inorder
    if(first && last){
        swap(&(first->data), &(last->data));
    }
    // case 2 - adjacent in inorder
    else if(first && mid){
        swap(&(first->data), &(mid->data));
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

    inOrder(Root);
    cout<<endl;

    // int arr[] = {1,3,4,5,7,8,9,10,15};
    // Node* Root2 = sortedArrToBST(arr, 0, 8);

    // inOrder(Root2);
    // cout<<endl;

    // zigZag(Root);
    // cout<<endl;

    // cout<<largestBSTinBT(Root).ans<<endl;

    // correctBST(Root);
    // inOrder(Root);
    // cout<<endl;

    return 0;
}