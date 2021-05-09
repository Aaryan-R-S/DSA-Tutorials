#include <iostream>
#include <limits>
#define m 5
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

void displayMatrix(int vertArr[m][m])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vertArr[i][j] << " ";
        }
        cout << endl;
    }
}

void setArr(int vertArr[m], int k)
{
    for (int i = 0; i < m; i++)
    {
        vertArr[i] = k;
    }
}
void setArr(int vertArr[m][m], int k)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vertArr[i][j] = k;
            vertArr[j][i] = k;
        }
    }
}

void add_edge(int vertArr[m][m], int wtArr[m][m], int u, int v, int wt=1, bool direct = false)
{
    if (direct)
    {
        vertArr[u][v] = 1;
        wtArr[u][v] = wt;
    }
    else{
        vertArr[u][v] = 1;
        vertArr[v][u] = 1;
        wtArr[u][v] = wt;
        wtArr[v][u] = wt;
    }
}

void dfs(int vertArr[m][m], Stack* myStack, int l){
    if (!myStack->present(l))
    {
        myStack->push(l);
        cout<<l<<" ";
        for (int j = 0; j < m; j++)
        {
            if ( vertArr[l][j]!=0 && !(myStack->present(j)) ){
                dfs(vertArr, myStack, j);
            }
        }
    }
};

int minIndex(int distArr[m], Stack* myStack, int p){
    int k = p;
    for (int i = 0; i < m; i++)
    {
        if (distArr[i]<distArr[k] && !(myStack->present(i)) )
        {
            k = i;
        }
    }
    return k;
};

void distUpdate(int distArr[m], int wtArr[m][m], int indexMin, int j){
    if (distArr[indexMin]+wtArr[indexMin][j]<distArr[j])
    {
        distArr[j] = distArr[indexMin] + wtArr[indexMin][j];
    }
};

int siblings(int distArr[m], int vertArr[m][m], int wtArr[m][m], Stack* myStack, int indexMin){
    myStack->push(indexMin);
    int sib = 0;
    for (int j = 0; j < m; j++)
    {
        if ( vertArr[indexMin][j]!=0 && !(myStack->present(j)) ){
            distUpdate(distArr, wtArr, indexMin, j);
            sib = j;
        }
    }
    return sib;
};

void oneToAllDist(int vertArr[m][m], int wtArr[m][m], Stack* myStack, int src){
    int inf = numeric_limits<int>::max();  // Infinite or max
    int distArr[m];
    setArr(distArr, inf);
    distArr[src] = 0;
    int sib = src;
    for (int i = 0; i < m; i++)
    {
        int k = minIndex(distArr, myStack, sib);
        sib = siblings(distArr, vertArr, wtArr, myStack, k);
    }
    for (int i = 0; i < m; i++)
    {
        cout<<distArr[i]<<" ";
    }
    cout<<endl;
};

int main()
{
    int vertArr[m][m]; 
    setArr(vertArr, 0);
    int wtArr[m][m]; 
    setArr(wtArr, 0);

    // add_edge(vertArr, wtArr, 0, 1, 4);
    // add_edge(vertArr, wtArr, 0, 4, 8);
    // add_edge(vertArr, wtArr, 1, 2, 8);
    // add_edge(vertArr, wtArr, 1, 4, 11);
    // add_edge(vertArr, wtArr, 4, 8, 7);
    // add_edge(vertArr, wtArr, 4, 5, 1);
    // add_edge(vertArr, wtArr, 2, 3, 7);
    // add_edge(vertArr, wtArr, 2, 6, 4);
    // add_edge(vertArr, wtArr, 2, 8, 2);
    // add_edge(vertArr, wtArr, 8, 5, 6);
    // add_edge(vertArr, wtArr, 5, 6, 2);
    // add_edge(vertArr, wtArr, 3, 6, 14);
    // add_edge(vertArr, wtArr, 3, 7, 9);
    // add_edge(vertArr, wtArr, 6, 7, 10);
    add_edge(vertArr, wtArr, 0, 1, 10, true);
    add_edge(vertArr, wtArr, 0, 2, 5, true);
    add_edge(vertArr, wtArr, 1, 3, 1, true);
    add_edge(vertArr, wtArr, 2, 1, 3, true);
    add_edge(vertArr, wtArr, 2, 3, 9, true);
    add_edge(vertArr, wtArr, 2, 4, 2, true);
    add_edge(vertArr, wtArr, 4, 0, 2, true);
    cout<<"Done\n"<<endl;

    displayMatrix(vertArr);
    cout<<"Done\n"<<endl;

    displayMatrix(wtArr);
    cout<<"Done\n"<<endl;

    Stack* myStack = new Stack();
    oneToAllDist(vertArr, wtArr, myStack, 0);
    free(myStack);
    cout<<"Done\n"<<endl;

    return 0;
}