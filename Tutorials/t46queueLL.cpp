#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* nxt;

        void print() 
        { 
            Node* n = this;
            while (n != NULL) { 
                cout << n->data << " "; 
                n = n->nxt; 
            } 
            cout<<endl;
        };

        bool isEmpty(){
            if (this->data == -1)
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

        Node* queue(int num){
            if (isFull())
            {
                printf("Queue Overflow\n");
                return this;
            }
            if(this->data==-1){
                this->data = num;
                this->nxt = NULL;
                return this;
            } 
            else
            {
                Node* p = this;
                while (p->nxt != NULL)
                {
                    p = p->nxt;
                }
                Node* n = new Node();
                n->data = num;
                n->nxt = NULL;
                p->nxt = n;
                return this;
            }
        };
        Node* dequeue() 
        { 
            if (isEmpty())
            {
                printf("Queue Underflow\n");
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
        
        void queueTop(){
            printf("%d\n", this->data);
        };

        void queueBottom(){
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
    Node *myQueue = new Node();
    myQueue->data = -1;

    // if(myQueue->isEmpty()){
    //     cout<<"Its's empty..."<<endl;
    // };
    // if(myQueue->isFull()){
    //     cout<<"Its's full..."<<endl;
    // };

    // myQueue->print();
    // myQueue = myQueue->dequeue();
    // myQueue->print();

    myQueue = myQueue->queue(2);
    myQueue = myQueue->queue(20);
    myQueue = myQueue->queue(200);
    myQueue = myQueue->queue(2000);
    myQueue->print();
    myQueue->peek(3);

    // myQueue = myQueue->dequeue();
    // myQueue = myQueue->dequeue();
    // myQueue->print();


    myQueue->queueTop();
    myQueue->queueBottom();

    return 0;
}