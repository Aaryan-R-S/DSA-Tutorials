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

void inOrderTrav(Node* n){
    if (n!=NULL)
    {
        inOrderTrav(n->left);
        cout<<n->data<<" ";
        inOrderTrav(n->right);
    }
};

int search(int inOrder[], int start, int end, int curr){
    for (int i = start; i <= end; i++)
    {
        if(inOrder[i]==curr){
            return i;
        }
    }
    cout<<"Oops"<<endl;
    return -1;
}

// Binary Tree Build -----
Node* buildTreePre(int preOrder[], int inOrder[], int start, int end){
    static int index = 0;

    if(start>end){
        return NULL;
    }

    int curr = preOrder[index];
    index++;

    Node* n = new Node();
    n->data = curr;

    if(start==end){
        return n;
    }

    int pos = search(inOrder, start, end, curr);
    n->left = buildTreePre(preOrder, inOrder, start, pos-1);
    n->right = buildTreePre(preOrder, inOrder, pos+1, end);
    return n;
}

Node* buildTreePos(int posOrder[], int inOrder[], int start, int end){
    static int index = 8;

    if(start>end){
        return NULL;
    }

    int curr = posOrder[index];
    index--;

    Node* n = new Node();
    n->data = curr;

    if(start==end){
        return n;
    }

    int pos = search(inOrder, start, end, curr);
    n->right = buildTreePos(posOrder, inOrder, pos+1, end);
    n->left = buildTreePos(posOrder, inOrder, start, pos-1);
    return n;
}

// BST Build -------
Node* buildBSTfromPre(int preOrder[], int start, int end){
    if(start > end){
        return NULL;
    }
    Node* n = createNode(preOrder[start]);
    if(start==end){
        return n;
    }
    int i;
    for(i=start; i<=end; i++){
        if(preOrder[i] > n->data){
            break;
        }
    }
    n->left = buildBSTfromPre(preOrder, start+1, i-1);
    n->right = buildBSTfromPre(preOrder, i, end);
    return n;
}

Node* buildBSTfromPos(int posOrder[], int start, int end){
    if(start > end){
        return NULL;
    }
    Node* n = createNode(posOrder[end]);
    if(start==end){
        return n;
    }
    int i;
    for(i=end; i>=start; i--){
        if(posOrder[i] < n->data){
            break;
        }
    }
    n->right = buildBSTfromPos(posOrder, i+1, end-1);
    n->left = buildBSTfromPos(posOrder, start, i);
    return n;
}

int main()
{
    // ------------------- FOR BT -------------------------
    int preOrder[] = {7,4,1,2,9,5,0,8,3};
    int inOrder[] = {1,4,9,2,7,8,0,5,3};
    int posOrder[] = {1,9,2,4,8,0,3,5,7};

    Node* rootPre = buildTreePre(preOrder, inOrder, 0, 8);
    inOrderTrav(rootPre);
    cout<<endl;

    Node* rootPos = buildTreePos(posOrder, inOrder, 0, 8);
    inOrderTrav(rootPos);
    cout<<endl;

    // ------------------- FOR BST ------------------------
    int preOrderBST[] = {3,1,2,5,4,6};
    int inOrderBST[] = {1,2,3,4,5,6};
    int posOrderBST[] = {2,1,4,6,5,3};

    Node* rootPreBST = buildBSTfromPre(preOrderBST, 0, 5);
    inOrderTrav(rootPreBST);
    cout<<endl;

    Node* rootPosBST = buildBSTfromPos(posOrderBST, 0, 5);
    inOrderTrav(rootPosBST);
    cout<<endl;

    return 0;
}