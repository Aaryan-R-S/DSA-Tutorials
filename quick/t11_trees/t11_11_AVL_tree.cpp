#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int key){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

void preorder(Node* n){
    if(n!=NULL){
        cout<<n->key<<" ";
        preorder(n->left);
        preorder(n->right);
    }
}

void inorder(Node* n){
    if(n!=NULL){
        inorder(n->left);
        cout<<n->key<<" ";
        inorder(n->right);
    }
}

int getHeight(Node* n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

int getBalance(Node* n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->right) - getHeight(n->left);
}

Node* RR(Node* y){
    Node* x = y->right;
    Node* t = x->left;

    // main rotations
    x->left = y;
    y->right = t;

    // reset height of changed pointers
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    // return new parent
    return x;
}

Node* LL(Node* y){
    Node* x = y->left;
    Node* t = x->right;

    // main rotations
    x->right = y;
    y->left = t;

    // reset height of changed pointers
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    // return new parent
    return x;
}

Node* balance(Node* n, int key){
    int balanceFactor = getBalance(n);
    // RR Case
    if(balanceFactor>1 && key > n->right->key){
        return RR(n);
    }
    // LL Case
    else if(balanceFactor<-1 && key < n->left->key){
        return LL(n);
    }
    // RL Case
    else if(balanceFactor>1 && key < n->right->key){
        n->right = LL(n->right);
        return RR(n);
    }
    // LR Case
    else if(balanceFactor<-1 && key > n->left->key){
        n->left = RR(n->left);
        return LL(n);
    }
    return n;
}

Node* insert(Node* n, int key){
    if(n==NULL){
        Node* t = new Node(key);
        return t;
    }
    else if(n->key > key){
        n->left = insert(n->left, key);
    }
    else if(n->key < key){
        n->right = insert(n->right, key);
    }
    else{
        return n;
    }
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    return balance(n, key);
}

Node* balanceDel(Node* n){
    int balanceFactor = getBalance(n);
    int balanceLeft = getBalance(n->left);
    int balanceRight = getBalance(n->right);
    // RR Case
    if(balanceFactor>1 && balanceRight>=0){
        return RR(n);
    }
    // LL Case
    else if(balanceFactor<-1 && balanceLeft<=0){
        return LL(n);
    }
    // RL Case
    else if(balanceFactor>1 && balanceRight<0){
        n->right = LL(n->right);
        return RR(n);
    }
    // LR Case
    else if(balanceFactor<-1 && balanceLeft>0){
        n->left = RR(n->left);
        return LL(n);
    }
    return n;
}

Node* deleteNode(Node* n, int key){
    if(n==NULL){
        return n;
    }
    else if(key > n->key){
        n->right = deleteNode(n->right, key);
    }
    else if(key < n->key){
        n->left = deleteNode(n->left, key);
    }
    else{
        if(n->left==NULL || n->right==NULL){
            Node* t = (n->right!=NULL) ? n->right : n->left;
            if(t==NULL){
                t = n;
                n = NULL;
            }
            else{
                *n = *t;    // copy the values from t to n
            }
            free(t);     // free n or t
        }
        else{
            Node* t = n->right;
            while (t->left!=NULL)
            {
                t = t->left;
            }
            n->key = t->key;
            n->right = deleteNode(n->right, t->key);
        }
    }
    if(n==NULL){
        return n;
    }
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));

    return balanceDel(n);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    preorder(root); // 30 20 10 25 40 50 
    cout<<endl;
    inorder(root);  // 10 20 25 30 40 50 
    cout<<endl;

    root = deleteNode(root, 40);
    root = deleteNode(root, 50);
    preorder(root); // 20 10 30 25 
    cout<<endl;
    inorder(root);  // 10 20 25 30
    cout<<endl;
    root = deleteNode(root, 10);
    preorder(root); // 25 20 30 
    cout<<endl;
    inorder(root);  // 20 25 30
    cout<<endl;
    root = deleteNode(root, 200);
    root = deleteNode(root, 25);
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    preorder(root); // 
    cout<<endl;
    inorder(root);  // 
    cout<<endl;

    return 0;
}