#include<iostream>
using namespace std;

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

int main()
{
    Node* Root = createNode(7);
    Node* N1 = createNode(4);
    Node* N2 = createNode(5);

    Root->setPtr(N1, N2);


    return 0;
}