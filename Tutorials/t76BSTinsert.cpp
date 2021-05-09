#include<iostream>
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

void insertBST(Node* root, int key){
    Node* prev = NULL;
    while (root!=NULL)
    {
        if (root->data==key)
        {
            cout<<"Already Exists\n";
            return;
        }
        else if (root->data>key)
        {
            prev=root;
            root=root->left;
        }
        else
        {
            prev=root;
            root=root->right;
        }
    }
    Node* n = createNode(key);
    if (prev->data>key)
    {
        prev->left=n;
    }
    else{
        prev->right=n;
    }
};


int isBST(Node* root){
    static Node* prev = NULL;
    if(root!=NULL){
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev!=NULL && root->data<=prev->data)
        {
            return 0;
        }
        prev = root;      // first left node is set as prev, then root 
        return isBST(root->right);
    }
    else{
        return 1;
    }
};


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

    insertBST(Root, 6);

    inOrder(Root);
    cout<<endl;
    cout<<isBST(Root)<<endl;

    return 0;
}