#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* nxt;

        void printStack() 
        { 
            Node* n = this;
            while (n != NULL) { 
                cout << n->data << " "; 
                n = n->nxt; 
            } 
            cout<<endl;
        };

        bool isEmpty(){
            if (this == NULL)
            {
                return 1;
            }
            return 0;
        };
        bool isFull(){
            Node *p = new Node();
            if (p == NULL)
            {
                return 1;
            }
            return 0;
        };

        Node* push(int n){
            if (isFull())
            {
                printf("Stack Overflow\n");
                return this;
            }
            else
            {
                Node *p = new Node();
                p->data = n;
                p->nxt = this;
                return p;
            }
        };
        Node* pop() 
        { 
            if (isEmpty())
            {
                printf("Stack Underflow\n");
                return this;
            }
            else
            {
                Node *p = this;
                Node *n = p->nxt;
                free(p);
                return n;
            }
        };
        
        void stackTop(){
            printf("%d\n", this->data);
        };

        void stackBottom(){
            Node* p = this;
            Node* n = this->nxt;
            while (n != NULL)
            {
                p = p->nxt;
                n = n->nxt;
            }
            printf("%d\n", p->data);
        };

        void peek(int index){
            Node *p = this;
            int i = 1;
            while (p != NULL and i!=index)
            {
                p = p->nxt;
                i++;
            }
            if(p==NULL){
                printf("Invalid Index\n");
            }
            else{
                printf("%d\n", p->data);
            }
        };
};

int main()
{
    Node *a = NULL;
    Node *myStack = a;

    if(myStack->isEmpty()){
        cout<<"Its's empty..."<<endl;
    };
    if(myStack->isFull()){
        cout<<"Its's full..."<<endl;
    };

    // myStack->printStack();
    // myStack = myStack->pop();
    // myStack->printStack();

    myStack = myStack->push(2);
    myStack = myStack->push(20);
    myStack = myStack->push(200);
    myStack = myStack->push(2000);
    myStack->printStack();

    // myStack = myStack->pop();
    // myStack->printStack();
    
    // myStack = myStack->pop();
    // myStack->printStack();

    // myStack->peek(3);

    // myStack->stackTop();
    myStack->stackBottom();

    return 0;
}