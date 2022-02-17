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

Node* searchBSTrec(Node* root, int key){
    if (root==NULL)
    {
        cout<<"No\n";
        return NULL;
    }
    else if (root->data==key)
    {
        cout<<"Yes\n";
        return root;
    }
    else if (root->data>key)
    {
        return searchBSTrec(root->left, key);
    }
    else
    {
        return searchBSTrec(root->right, key);
    }
};

Node* searchBSTiter(Node* root, int key){
    while (root!=NULL)
    {
        if (root->data==key)
        {
            cout<<"Yes\n";
            return root;
        }
        else if (root->data>key)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }   
    }
    cout<<"No\n";
    return NULL;
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

    searchBSTrec(Root, 5);
    searchBSTrec(Root, 2);

    searchBSTiter(Root, 5);
    searchBSTiter(Root, 2);

    return 0;
}