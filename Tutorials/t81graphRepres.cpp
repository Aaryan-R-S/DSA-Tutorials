#include <iostream>
using namespace std;

class Stack{
    public:
        int size = 20;
        int top = -1;
        int* arr = new int[size];

    void display(bool reverse = false){
        if(reverse==true){
            int i = this->top;
            while (i>=0)
            {
                printf("%d ", this->arr[i]);
                i--;
            }
        }
        else{
            int i = 0;
            while (i <= this->top)
            {
                printf("%d ", this->arr[i]);
                i++;
            }
        }
        printf("\n");
    };
    bool present(int k){
        int i = 0;
        while (i <= this->top)
        {
            if(this->arr[i]==k){
                return true;
            };
            i++;
        }
        return false;
    };
    bool checkEmpty(){
        if(this->top == -1){
            return 1;
        }
        return 0;
    };
    bool checkFull(){
        if(this->top == this->size-1){
            return 1;
        }
        return 0;
    };

    Stack* push(int n){
        if(this->checkFull()){
            return this;
        }
        else{
            this->top++;
            this->arr[top] = n;
            return this;
        };
    };
    Stack* pop(){
        if(this->checkEmpty()){
            return this;
        }
        else{
            this->top--;
            return this;
        };
    };

};

class Queue{
    public:
        int size = 20;
        int start = -1;
        int p = -1;
        int end = -1;
        int* arr = new int[size];

    void display(bool reverse = false){
        if(reverse==true){
            int i = this->end;
            while (i >= this->start+1)
            {
                printf("%d ", this->arr[i]);
                i--;
            }
        }
        else{
            int i = this->start+1;
            while (i <= this->end)
            {
                printf("%d ", this->arr[i]);
                i++;
            }
        }
        printf("\n");
    };

    bool present(int k){
        int i = this->start+1;
        while (i <= this->end)
        {
            if(this->arr[i]==k){
                return true;
            };
            i++;
        }
        return false;
    };

    bool checkEmpty(){
        if(this->end == this->start){
            return 1;
        }
        return 0;
    };
    bool checkFull(){
        if(this->end == this->size-1){
            return 1;
        }
        return 0;
    };

    Queue* queue(int n){
        if(this->checkFull()){
            return this;
        }
        else{
            this->end++;
            this->arr[end] = n;
            return this;
        };
    };
    int dequeue(){
        if(this->checkEmpty()){
            return -1;
        }
        else{
            this->start++;
            return this->arr[this->start];
        };
    };
};

void displayMatrix(int vertArr[5][5], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << vertArr[i][j] << " ";
        }
        cout << endl;
    }
}

void setArr(int vertArr[5][5], int v, int k)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            vertArr[i][j] = k;
            vertArr[j][i] = k;
        }
    }
}

void add_edge(int vertArr[5][5], int wtArr[5][5], int u, int v, int w=1, bool direct = false)
{
    if (direct)
    {
        vertArr[u-1][v-1] = 1;
        wtArr[u-1][v-1] = w;
    }
    else{
        vertArr[u-1][v-1] = 1;
        vertArr[v-1][u-1] = 1;
        wtArr[u-1][v-1] = w;
        wtArr[v-1][u-1] = w;
    }
}

void bfs(int vertArr[5][5], Queue* myQueue, int v, int l){
    int ll;
    if(!myQueue->present(l+1))
    {
        myQueue->queue(l+1);
    }
    for (int j = 0; j < v; j++)
    {
        if (vertArr[l][j]!=0 && !myQueue->present(j+1)){
            myQueue->queue(j+1);
        }
    }
    cout<<myQueue->arr[myQueue->p+1]<<" ";
    myQueue->p++;
    if (myQueue->p!=myQueue->end)
    {
        ll = myQueue->arr[myQueue->p+1];
        bfs(vertArr, myQueue, 5, ll-1);
    }
};

void dfs(int vertArr[5][5], Stack* myStack, int v, int l){
    if (!myStack->present(l+1))
    {
        myStack->push(l+1);
        cout<<l+1<<" ";
        for (int j = 0; j < v; j++)
        {
            if ( vertArr[l][j]!=0 && !(myStack->present(j+1)) ){
                dfs(vertArr, myStack, 5, j);
            }
        }
    }
};

/*
int main()
{
    int vertArr[5][5]; 
    setArr(vertArr, 5, 0);
    int wtArr[5][5]; 
    setArr(wtArr, 5, 0);

    // add_edge(vertArr, wtArr, 1, 3);
    // add_edge(vertArr, wtArr, 1, 5);
    // add_edge(vertArr, wtArr, 2, 3);
    // add_edge(vertArr, wtArr, 4, 5);
    add_edge(vertArr, wtArr, 1, 2, 9);
    add_edge(vertArr, wtArr, 1, 3, 12);
    add_edge(vertArr, wtArr, 2, 3, 6);
    add_edge(vertArr, wtArr, 2, 5, 20);
    add_edge(vertArr, wtArr, 3, 5, 15);
    add_edge(vertArr, wtArr, 4, 2, 18);
    cout<<"Done\n"<<endl;

    displayMatrix(vertArr, 5);
    cout<<"Done\n"<<endl;

    displayMatrix(wtArr, 5);
    cout<<"Done\n"<<endl;

    Queue* myQueue = new Queue();
    bfs(vertArr, myQueue, 5, 0);
    free(myQueue);
    cout<<endl;
    cout<<"Done\n"<<endl;

    Stack* myStack = new Stack();
    dfs(vertArr, myStack, 5, 0);
    free(myStack);
    cout<<endl;
    cout<<"Done\n"<<endl;

    return 0;
}
*/