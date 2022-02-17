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

Node* deleteBST(Node* root, int key){
    if(root==NULL){
        return root;
    }
    if(root->data>key){
        root->left = deleteBST(root->left, key);
    }
    else if(root->data<key){
        root->right = deleteBST(root->right, key);
    }
    else{
        if(root->left==NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            Node* temp = root->right;
            while(temp->left!=NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
            return root;
        }
    }
    return root;
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
    insertBST(Root, 6);

    inOrder(Root);
    cout<<endl;
    
    deleteBST(Root, 4);
    inOrder(Root);
    cout<<endl;

    deleteBST(Root, 9);
    inOrder(Root);
    cout<<endl;

    deleteBST(Root, 7);
    inOrder(Root);
    cout<<endl;

    return 0;
}