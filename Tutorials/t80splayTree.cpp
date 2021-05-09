#include<iostream>
using namespace std;


class Node{
    public:
        Node* parent;
        Node* left;
        int data;
        Node* right;
        
        void setData(int data){
            this->data = data;
        };

        void setPtr(Node* l, Node* r, Node* p){
            this->left = l;
            this->right = r;
            this->parent = p;
        };
};

Node* rightRot(Node* root, Node* nr){
    Node* l = nr->left;
    nr->left = l->right;
    l->right = nr;
    l->parent = nr->parent;
    nr->parent = l;
    if(nr->left!=NULL){
        nr->left->parent = nr;
    }
    if (l->parent==NULL)
    {
        return l;
    }
    else
    {
        if(l->parent->data>l->data){
            l->parent->left=l;
        }
        else{
            l->parent->right=l;
        }
        return root;
    }
};

Node* leftRot(Node* root, Node* nr){
    Node* r = nr->right;
    nr->right = r->left;
    r->left = nr;
    r->parent = nr->parent;
    nr->parent = r;
    if(nr->right!=NULL){
        nr->right->parent = nr;
    }
    if (r->parent==NULL)
    {
        return r;
    }
    else
    {
        if(r->parent->data>r->data){
            r->parent->left=r;
        }
        else{
            r->parent->right=r;
        }
        return root;
    }
};

Node* splay(Node* root, Node* n){
    while (n->parent!=NULL)
    {
        if(n->parent==root){
            if(n==root->left){
                root=rightRot(root, root);
            }
            else{
                root=leftRot(root, root);
            }
        }
        else{
            Node* p = n->parent;
            Node* g = p->parent;
            if (n==p->left && p==g->left)
            {
                root=rightRot(root, g);
                root=rightRot(root, p);
            }
            else if (n==p->right && p==g->right)
            {
                root=leftRot(root, g);
                root=leftRot(root, p);
            }
            else if (n==p->left && p==g->right)
            {
                root=rightRot(root, p);
                root=leftRot(root, g);
            }
            else if (n==p->right && p==g->left)
            {
                root=leftRot(root, p);
                root=rightRot(root, g);
            }
            else{
                cout<<"ah ";
            }
        }
    }
    return n;
};

Node* insertNode(Node* root, int data){
    Node* n = new Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    Node* temp = root;
    Node* tempP = NULL;

    while (temp!=NULL)
    {
        tempP = temp;
        if (n->data==temp->data)
        {
            return root;
        }
        else if (n->data<temp->data)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }       
    }
    n->parent = tempP;
    if (tempP==NULL)
    {
        return n;
    }
    else if(n->data<tempP->data){
        tempP->left = n;
    }
    else{
        tempP->right = n;
    }
    n = splay(root, n);
    return n;
};

Node* del(Node* root, Node* n, bool l){
    if (n->left==NULL && n->right==NULL)
    {
        l==1?n->parent->left=NULL:n->parent->right=NULL;
        n->parent=NULL;
        free(n);
    }
    else if (n->left!=NULL){
        Node* k = n->left;
        int i = 1;
        while (k->right!=NULL)
        {
            k=k->right;
            i=0;
        }
        n->data = k->data;
        root = del(root, k, i);
    }
    else if (n->right!=NULL)
    {
        Node* k = n->right;
        int i = 0;
        while (k->left!=NULL)
        {
            k=k->left;
            i=1;
        }
        n->data = k->data;
        root = del(root, k, i);
    }
    return root;
};

Node* delNode(Node* root, int data){
    Node* temp = root;
    Node* tempP = NULL;

    while (temp!=NULL)
    {
        if (data==temp->data)
        {
            break;
        }
        else if (data<temp->data)
        {
            tempP = temp;
            temp=temp->left;
        }
        else
        {
            tempP = temp;
            temp=temp->right;
        }       
    }
    if(temp!=NULL){
        root = del(root, temp, tempP!=NULL?(tempP->left==temp?1:0):1);
    }
    if (tempP!=NULL)
    {
        root = splay(root, tempP);
    }
    return root;
};

void inOrder(Node* n){
    if (n!=NULL)
    {
        inOrder(n->left);
        cout<<n->data<<" ";
        inOrder(n->right);
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

/*
         7
     3        10
   1   5    9   15
      4    8
*/
    //Inorder - 1 3 4 5 7 8 9 10 15

    Node* Root = insertNode(NULL, 7);
    Root = insertNode(Root, 3);
    Root = insertNode(Root, 1);
    Root = insertNode(Root, 4);
    Root = insertNode(Root, 5);
    Root = insertNode(Root, 9);
    Root = insertNode(Root, 10);
    Root = insertNode(Root, 15);
    Root = insertNode(Root, 8);
    Root = delNode(Root, 0);
    Root = delNode(Root, 16);
    Root = delNode(Root, 1);
    Root = delNode(Root, 7);

    inOrder(Root);
    cout<<endl;

    cout<<isBST(Root)<<endl;

    cout<<"Root: "<<Root->data<<endl;


    return 0;
}