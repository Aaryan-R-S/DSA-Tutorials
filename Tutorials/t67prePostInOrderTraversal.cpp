#include<iostream>
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

void preOrder(Node* n){
    if (n!=NULL)
    {
        cout<<n->data<<" ";
        preOrder(n->left);
        preOrder(n->right);
    }
};

void inOrder(Node* n){
    if (n!=NULL)
    {
        inOrder(n->left);
        cout<<n->data<<" ";
        inOrder(n->right);
    }
};

void postOrder(Node* n){
    if (n!=NULL)
    {
        postOrder(n->left);
        postOrder(n->right);
        cout<<n->data<<" ";
    }
};

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

    preOrder(Root);
    cout<<endl;
    inOrder(Root);
    cout<<endl;
    postOrder(Root);
    cout<<endl;

    return 0;
}