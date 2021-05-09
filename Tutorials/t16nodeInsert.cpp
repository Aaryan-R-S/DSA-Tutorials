#include<iostream>
using namespace std;

class node{
    public:
        int num;
        node *next;
};

void printList(node* n) 
{ 
    while (n != NULL) { 
        cout << n->num << " "; 
        n = n->next; 
    } 
};

node* insertAtFirst(node* n, int num) 
{ 
    node *e = new node();
    e->num = num;
    e->next = n;
    printf("\n");
    return e;
};

void insertAtLast(node* n, int num) 
{ 
    node *e = new node();
    e->num = num;
    e->next = NULL;
    while (n->next != NULL) { 
        n = n->next; 
    } 
    n->next = e; 
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
    d->next = NULL;

    printList(a);

    a = insertAtFirst(a, 0);
    printList(a);
    
    insertAtLast(a, 5);
    printList(a);
    
    insertAtIndex(a, 9, 1);
    printList(a);

    insertAfter(c, 8);
    printList(a);

    return 0;
}