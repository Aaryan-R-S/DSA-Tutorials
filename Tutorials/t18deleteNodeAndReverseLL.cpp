#include<iostream>
using namespace std;

// NOTE: Always maintain a Head and tail node in all types of linked lists 
// Point them initially to NULL
// Then update them as nodes are created in dynamic way(asking user) not static way(code)

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

node* deleteFirst(node* n) 
{ 
    node* e = n;
    node* f = n->next;
    e->next = f->next;
    free(f);
    printf("\n");
    return n;
};

void deleteAt(node* n, int index) 
{ 
    node* e = n;
    for (int i = 0; i < index-1; i++)
    {
        e = e->next;
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
    while (f->num != val && f->next != NULL)
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
    while (f->next != NULL)
    {
        e = e->next;
        f = f->next;
    }
    e->next = NULL;
    free(f);
    printf("\n");
};

node* reverseLinkedList(node* n){
    node* prevNode = NULL;
    node* currentNode = n;
    node* nextNode = n;
    while (nextNode!=NULL)
    {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode; 
};

node* reverseLinkedListIter(node* n){
    node* prevNode = NULL;
    node* currentNode = n;
    node* nextNode = n;
    while (nextNode!=NULL)
    {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode; 
};

node* reverseLinkedListRec(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newHead = reverseLinkedListRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
};

node* reverseK(node* &head, int k){
    node* prevNode = NULL;
    node* currentNode = head;
    node* nextNode;

    int count = 0;
    while (currentNode!=NULL && count<k)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
        count++;
    }
    if(currentNode!=NULL){
        head->next = reverseK(currentNode, k);
    }
    return prevNode; 
}


int main()
{
    // Or u can create a head node which points to first node of linked list
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

    // a = deleteFirst(a);
    // printList(a);
    // printf("\n%d", b->num);

    // deleteAt(a, 1);
    // printList(a);
    // printf("\n%d", b->num);

    // deleteVal(a, 5);
    // printList(a);
    // printf("\n%d", c->num);

    // deleteLast(a);
    // printList(a);
    // printf("\n%d", d->num);
    // a = reverseLinkedList(a);
    // cout<<endl;
    // printList(a);

    // a = reverseLinkedListIter(a);
    a = reverseK(a, 2);
    cout<<endl;
    printList(a);

    return 0;
}