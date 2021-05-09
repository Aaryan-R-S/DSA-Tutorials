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

int connected(int vertArr[5][5], Stack* myStack, int v){
    int c = 0;
    for (int i = 0; i < v; i++)
    {
        if (!myStack->present(i+1)){
            c++;
            cout<<c<<": ";
            dfs(vertArr, myStack, 5, i);
            cout<<endl;
        }
    }
    return c;
};

int main()
{
    int vertArr[5][5]; 
    setArr(vertArr, 5, 0);
    int wtArr[5][5]; 
    setArr(wtArr, 5, 0);

    add_edge(vertArr, wtArr, 1, 3);
    // add_edge(vertArr, wtArr, 1, 5);
    add_edge(vertArr, wtArr, 2, 3);
    add_edge(vertArr, wtArr, 4, 5);
    // add_edge(vertArr, wtArr, 1, 2, 9);
    // add_edge(vertArr, wtArr, 1, 3, 12);
    // add_edge(vertArr, wtArr, 2, 3, 6);
    // add_edge(vertArr, wtArr, 2, 5, 20);
    // add_edge(vertArr, wtArr, 3, 5, 15);
    // add_edge(vertArr, wtArr, 4, 2, 18);
    cout<<"Done\n"<<endl;

    displayMatrix(vertArr, 5);
    cout<<"Done\n"<<endl;

    displayMatrix(wtArr, 5);
    cout<<"Done\n"<<endl;

    Stack* myStack = new Stack();
    cout<<connected(vertArr, myStack, 5)<<endl;
    free(myStack);
    cout<<"Done\n"<<endl;

    return 0;
}