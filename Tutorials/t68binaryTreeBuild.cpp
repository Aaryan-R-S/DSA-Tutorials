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

int main()
{
    int preOrder[] = {7,4,1,2,9,5,0,8,3};
    int inOrder[] = {1,4,9,2,7,8,0,5,3};
    int posOrder[] = {1,9,2,4,8,0,3,5,7};

    Node* rootPre = buildTreePre(preOrder, inOrder, 0, 8);
    inOrderTrav(rootPre);
    cout<<endl;

    Node* rootPos = buildTreePos(posOrder, inOrder, 0, 8);
    inOrderTrav(rootPos);
    cout<<endl;


    return 0;
}