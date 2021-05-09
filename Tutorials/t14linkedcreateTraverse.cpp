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
}

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

    return 0;
}