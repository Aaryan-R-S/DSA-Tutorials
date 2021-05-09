#include<iostream>
using namespace std;

class Node{
    public:
        int num;
        Node* pre;
        Node* nxt;
};

void printList(Node* head) 
{ 
    Node* e = head;
    do{
        printf("%d ", e->num);
        e = e->nxt;
    }while(e->nxt != NULL);
    printf("%d ", e->num);
};

void printListRev(Node* tail) 
{ 
    printf("\n");
    Node* e = tail;
    do{
        printf("%d ", e->num);
        e = e->pre;
    }while(e->pre != tail);
};

Node* insertAtFirst(Node* head, int num) 
{ 
    Node *e = new Node();
    e->num = num;
    e->nxt = head;
    e->pre = NULL;

    Node *p = e->nxt;
    p->pre = e;    

    printf("\n");
    return e;
};

void insertAtLast(Node* head, int num) 
{ 
    Node *e = new Node();
    e->num = num;
    e->nxt = NULL;
    Node *p = new Node();
    p = head;
    while (p->nxt != NULL) { 
        p = p->nxt; 
    } 
    p->nxt = e; 
    printf("\n");
};

void insertAtIndex(Node* head, int num, int index) 
{ 
    Node *e = new Node();
    e->num = num;

    Node *f = head;
    Node *k = head->nxt;
    int i = 0;
    while (i < index-1)
    {
        f = f->nxt;
        k = k->nxt;
        i++;
    };
    f->nxt = e;
    k->pre = e;
    e->nxt = k;
    e->pre = f;
    
    printf("\n");
};

void insertAfter(Node* n, int num) 
{ 
    Node *e = new Node();
    Node *f = n->nxt;
    e->num = num;
    e->nxt = f;
    e->pre = n;
    f->pre = e;
    n->nxt = e;

    printf("\n");
};

Node* deleteFirst(Node* head) 
{ 
    Node* e = head;
    Node* p = head->nxt;
    p->pre = NULL;
    free(e);
    printf("\n");
    return p;
};

void deleteAt(Node* head, int index) 
{ 
    Node* e = head;
    for (int i = 0; i < index-1; i++)
    {
        e = head->nxt;
    }
    Node* f = e->nxt;
    Node* k = f->nxt;
    e->nxt = k;
    k->pre = e;
    free(f);
    printf("\n");
};

void deleteVal(Node* head, int val) 
{ 
    Node* e = head;
    Node* f = head->nxt;
    while (f->num != val && f->nxt != NULL)
    {
        e = e->nxt;
        f = f->nxt;
    }
    if (f->num == val)
    {
        Node* k = f->nxt;
        e->nxt = k;
        k->pre = e; 
        free(f);
    }
    
    printf("\n");
};

void deleteLast(Node* head) 
{ 
    Node* e = head;
    Node* f = head->nxt;
    while (f->nxt != NULL)
    {
        e = e->nxt;
        f = f->nxt;
    }
    e->nxt = NULL;
    free(f);
    printf("\n");
};

Node* reverseLinkedList(Node* n){
    Node* currentNode = n;
    Node* nextNode = n;
    while (currentNode !=NULL)
    {
        nextNode = currentNode->nxt;
        currentNode->nxt = currentNode->pre;
        currentNode->pre = nextNode;
        if (nextNode==NULL){
            break;
        }
        currentNode = nextNode;
    }
    return currentNode; 
};

int main()
{
    Node *a = new Node(), *b = new Node(), *c = new Node(), *d = new Node();   

    a->num = 1;
    a->pre = NULL;
    a->nxt = b;
    
    b->num = 2;
    b->pre = a;
    b->nxt = c;
    
    c->num = 3;
    c->pre = b;
    c->nxt = d;

    d->num = 4;
    d->pre = c;
    d->nxt = NULL;

    Node* head = a;
    Node* tail = d;

    printList(head);
    // printListRev(tail);

    // head = insertAtFirst(head, 5);
    // insertAtLast(head, 5);
    // insertAtIndex(a, 5, 1);
    // insertAfter(b, 5);

    // head = deleteFirst(a);
    // deleteLast(a);
    // deleteVal(a, 3);
    // deleteAt(a, 1);
    // printList(head);

    head = reverseLinkedList(head);
    cout<<endl;
    printList(head);

    return 0;
}