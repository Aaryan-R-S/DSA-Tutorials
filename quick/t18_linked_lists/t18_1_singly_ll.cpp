#include<iostream>
using namespace std;

// NOTE: Always maintain a Head and tail node in all types of linked lists 
// Point them initially to NULL
// Then update them as nodes are created in dynamic way(asking user) not static way(code)

// `Problems:`
// - https://www.interviewbit.com/problems/reorder-list/
// - https://www.interviewbit.com/problems/sort-list/
// - https://www.interviewbit.com/problems/add-two-numbers-as-lists/
// - https://www.interviewbit.com/problems/insertion-sort-list/
// - https://www.interviewbit.com/problems/palindrome-list/
// - https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

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

// Hare and Tortoise ALgo OR Floyd's Algo
bool detectCycle(node* &head){
    node* slowptr = head;
    node* fastptr = head;

    while(fastptr!=NULL && fastptr->next!=NULL){
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        
        if(fastptr==slowptr){
            return true;
        }
    }
    return false;
}

void removeCycle(node* &head){
    node* slowptr = head;
    node* fastptr = head;

    do{
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }while(slowptr!=fastptr);

    fastptr = head;

    while (slowptr->next!=fastptr->next){
        slowptr = slowptr->next;
        fastptr = fastptr->next;
    }
    slowptr->next = NULL;
}

// Append last k node to start
node* appendK(node* &head, int k){
    int len = 0;
    node* temp = head;
    while (temp!=NULL)
    {
        temp=temp->next;
        len++; 
    }

    node* newHead;
    node* newTail;
    node* tail = head;

    int count = 1;
    while(tail->next!=NULL){
        if(count == len-k){
            newTail = tail;
            newHead = newTail->next;
        }
        tail=tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;
    
    return newHead;
}

int length(node* &head){
    int len = 0;
    node* temp = head;
    while (temp!=NULL)
    {
        temp=temp->next;
        len++; 
    }
    return len;
}

int intersection(node* &head1, node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);

    int d;
    node* longPtr;
    node* shortPtr;

    if(l1>l2){
        d = l1-l2;
        longPtr = head1;
        shortPtr = head2;
    }else{
        d = l2-l1;
        longPtr = head2;
        shortPtr = head1;
    }

    while(d){
        longPtr = longPtr->next;
        if (longPtr==NULL)
        {
            return -1;
        }
        d--;
    }

    while (longPtr!=NULL && shortPtr!=NULL)
    {
        if(longPtr==shortPtr){
            return longPtr->num;
        }
        longPtr=longPtr->next;
        shortPtr=shortPtr->next;
    }
    return -1;
}

// put all nodes at odd positions before those nodes at even positions
// e.g. ->   1,2,3,4,5,6  to 1,3,5,2,4,6
void evenAfterOdd(node* &head){
    node* odd = head;
    node* even = head->next;
    node* evenStart = even;

    while(odd->next!=NULL && even->next!=NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    // if(odd->next!=NULL){
    //     even->next = NULL;
    // }        
    odd->next = evenStart;
    return;
}

int main()
{
    // Or u can create a head node which points to first node of linked list
    node *a = new node(), *b = new node(), *c = new node(), *d = new node(); 
    node *e = new node(), *f = new node();;   

    a->num = 1;
    a->next = b;
    
    b->num = 2;
    b->next = c;
    
    c->num = 3;
    c->next = d;

    d->num = 4;
    // d->next = NULL;  
    d->next = e;  

    e->num = 5;
    e->next = f;
    // e->next = NULL;

    f->num = 6;
    // f->next = b;
    f->next = NULL;

    printList(a);
    cout<<endl;
    // printList(e);
    // cout<<endl;

    // cout<<intersection(a, e)<<endl;

    evenAfterOdd(a);
    printList(a);

    return 0;
}