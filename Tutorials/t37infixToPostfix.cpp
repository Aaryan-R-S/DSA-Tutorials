#include<iostream>
#include<cmath>
using namespace std;

// 1. infix to postfix
// 2. postfix eval value
// 3. create a binary tree using postfix
// 4. tree inorder = infix
// 5. tree preorder = prefix
// 6. tree postorder = postfix


class Stack{
    public:

    int size = 20;
    int topVar = -1;
    char* varArr = new char[size];
    int topOpt = -1;
    char* optrArr = new char[size];

    void check(char c){
        if(c=='*'||c=='/'){
            this->push(c, 2);
        }
        else if(c=='+'||c=='-'){
            this->push(c, 1);
        }
        else if(c=='^'){
            this->push(c,3);
        }
        else if(c=='('){
            this->push(c,4);
        }
        else if(c==')'){
            this->push(c,4);
        }
        else{
            this->push(c, 0);
        }
    };
    void pop(char c){
        this->topOpt-=2;
        if(c!='('){
            this->topVar++;
            this->varArr[this->topVar] = c;
        }
    };
    void push(char c, int b){
        if(b==0){
            this->topVar++;
            this->varArr[this->topVar] = c;
            return;
        }
        else if (this->topOpt!=-1){
            if (b==4)
            {
                if(c==')'){
                    while(this->optrArr[this->topOpt-1] != '('){
                        pop(this->optrArr[this->topOpt-1]);
                    }
                    pop(this->optrArr[this->topOpt-1]);
                    return;
                }
            }
            else if (b==3)
            {
                while(int(this->optrArr[this->topOpt]) > b && this->topOpt!=-1){
                    pop(this->optrArr[this->topOpt-1]);
                }
            }
            else{
                while(int(this->optrArr[this->topOpt]) >= b && this->topOpt!=-1 && this->optrArr[this->topOpt-1] != '('){
                    pop(this->optrArr[this->topOpt-1]);
                }
            }
            
        }
        this->topOpt++;
        this->optrArr[topOpt] = c;
        this->topOpt++;
        this->optrArr[topOpt] = b;
    };

    string conversion(string myExpression){
        string converted = "";
        for (int i=0; i<myExpression.length(); ++i)
        {
            check(myExpression[i]);
        }
        while (this->topOpt!=-1)
        {
            this->topVar++;
            this->varArr[this->topVar] = this->optrArr[topOpt-1];
            this->topOpt-=2;
        }
        
        for (int i = 0; i <= this->topVar; i++)
        {
            converted+=this->varArr[i];
        }
        
        return converted;
    };
};

class StackEval{
public:
    int top=-1;
    float *arr = new float[20];

    void push(float f){
        this->top++;
        this->arr[this->top] = f;
    };

    float pop(char op){
        float op1, op2;
        op1 = this->arr[this->top-1];
        op2 = this->arr[this->top];
        this->top-=2;
        if(op=='*'){
            return op1*op2;
        }
        else if(op=='/'){
            return op1/op2;
        }
        else if(op=='+'){
            return op1+op2;
        }
        else if(op=='-'){
            return op1-op2;
        }
        else{
            return pow(op1, op2);
        }
    };
    float ans(string myExpression){
        for (int i=0; i<myExpression.length(); i++)
        {
            if (myExpression[i]=='*'||myExpression[i]=='/'||myExpression[i]=='^'||myExpression[i]=='+'||myExpression[i]=='-')
            {
                float a = pop(myExpression[i]);
                push(a);
            }else{
                int ia = myExpression[i] - '0';
                push(float(ia));
            }
        }
        return this->arr[this->top];
    };
};

class Node{
    public:
        Node* left;
        char data;
        Node* right;
        
        void setData(char data){
            this->data = data;
        };

        void setPtr(Node* l, Node* r){
            this->left = l;
            this->right = r;
        };
};

Node* createNode(char data, Node* left = NULL, Node* right = NULL){
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

class StackTree{
public:
    int top=-1;
    Node **arr = new Node*[20];

    void push(Node* n){
        this->top++;
        this->arr[this->top] = n;
    };

    Node* pop(char op){
        Node* op1 = this->arr[this->top-1];
        Node* op2 = this->arr[this->top];
        this->top-=2;
        return createNode(op, op1, op2);
    };
    Node* ans(string myExpression){
        for (int i=0; i<myExpression.length(); i++)
        {
            if (myExpression[i]=='*'||myExpression[i]=='/'||myExpression[i]=='^'||myExpression[i]=='+'||myExpression[i]=='-')
            {
                Node* a = pop(myExpression[i]);
                push(a);
            }else{
                Node* a = createNode(myExpression[i]);
                push(a);
            }
        }
        return this->arr[this->top];
    };
};


int main()
{
    Stack* inToPo = new Stack();

    printf("Enter the infix: ");
    string myExpression;
    cin>>myExpression;

    printf("Postfix: ");
    string converted = inToPo->conversion(myExpression);
    cout<<converted<<endl;

    StackEval* myStack = new StackEval();
    printf("Eval: ");
    float a = myStack->ans(converted);
    cout<<a<<endl;

    StackTree* myS = new StackTree();
    Node* Root = myS->ans(converted);

    printf("Tree(In-order) or Infix: ");
    inOrder(Root);
    cout<<endl;

    printf("Tree(Pre-order) or Prefix: ");
    preOrder(Root);
    cout<<endl;

    printf("Tree(Post-order) or Postfix: ");
    postOrder(Root);
    cout<<endl;

    cout<<Root->data<<endl;

    return 0;
}