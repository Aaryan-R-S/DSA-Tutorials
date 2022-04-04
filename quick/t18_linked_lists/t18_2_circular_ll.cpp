#include<iostream>
using namespace std;

class node{
    public:
        int num;
        node *next;
};

void printList(node* n) 
{ 
    node* e = n;
    do{
        printf("%d ", e->num);
        e = e->next;
    }while(e != n);
};

node* insertAtFirst(node* n, int num) 
{ 
    node *e = new node();
    e->num = num;
    e->next = n;

    node *p = new node();
    p = n->next;
    while (p->next!=n)
    {
        p = p->next;
    };

    p->next = e;    

    printf("\n");
    return e;
};

void insertAtLast(node* n, int num) 
{ 
    node *e = new node();
    e->num = num;
    e->next = n;
    node *p = new node();
    p = e->next;
    while (p->next != n) { 
        p = p->next; 
    } 
    p->next = e; 
    printf("\n");
};

void insertAtIndex(node* n, int num, int index) 
{ 
    node *e = new node();
    e->num = num;

    int i = 0;
    while (i < index-1)
    {
        n = n->next;
        i++;
    }
    e->next = n->next;
    n->next = e;
    printf("\n");
};

void insertAfter(node* n, int num) 
{ 
    node *e = new node();
    e->num = num;
    e->next = n->next;
    n->next = e;
    printf("\n");
};

node* deleteFirst(node* n) 
{ 
    node* e = n;
    node* p = e->next;
    while (p->next != n) { 
        p = p->next; 
    } 
    p->next = e->next;
    free(e);
    printf("\n");
    return p->next;
};

void deleteAt(node* n, int index) 
{ 
    node* e = n;
    for (int i = 0; i < index-1; i++)
    {
        e = n->next;
    }
    node* f = e->next;
    e->next = f->next;
    free(f);
    printf("\n");
};

void deleteVal(node* n, int val) 
{ 
    node* e = n;
    node* f = n->next;
    while (f->num != val && f->next != n)
    {
        e = e->next;
        f = f->next;
    }
    if (f->num == val)
    {
        e->next = f->next;
        free(f);
    }
    
    printf("\n");
};

void deleteLast(node* n) 
{ 
    node* e = n;
    node* f = n->next;
    while (f->next != n)
    {
        e = e->next;
        f = f->next;
    }
    e->next = f->next;
    free(f);
    printf("\n");
};

node* reverseLinkedList(node* n){
    node* prevNode = n;
    node* currentNode = n->next;
    node* nextNode = n->next;
    while (currentNode != n)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    currentNode->next = prevNode;
    return prevNode; 
};

int main()
{
    node *a = new node(), *b = new node(), *c = new node(), *d = new node();   

    a->num = 1;
    a->next = b;
    
    b->num = 2;
    b->next = c;
    
    c->num = 3;
    c->next = d;

    d->num = 4;
    d->next = a;

    printList(a);
    // a = insertAtFirst(a, 5);
    // insertAtLast(a, 5);
    // insertAtIndex(a, 5, 1);
    // insertAfter(a, 5);

    // a = deleteFirst(a);
    // deleteLast(a);
    // deleteVal(a, 3);
    // deleteAt(a, 3);
    // printList(a);

    cout<<endl;
    a = reverseLinkedList(a);
    printList(a);

    return 0;
}