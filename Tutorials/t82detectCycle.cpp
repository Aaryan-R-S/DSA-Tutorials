#include <iostream>
#include "t81graphRepres.cpp"
using namespace std;

bool detectCycle(int vertArr[5][5], Stack* myStack, int *a, int v, int l , int p=-1){
    if (!myStack->present(l+1))
    {
        myStack->push(l+1);
        for (int j = 0; j < v; j++)
        {
            if ( vertArr[l][j]!=0 && !(myStack->present(j+1) ) ){
                bool v = detectCycle(vertArr, myStack, a, 5, j, l);
                if(v){
                    return true;
                }
            }
        }
        for (int j = 0; j < v; j++)
        {
            if (vertArr[l][j]!=0 && myStack->present(j+1) && j!=p&& a[j]!=1 )
            {
                return true;
            }
        }
        myStack->pop();
        a[l] = 1;
    }
    return false;
};

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

    Stack* myStack = new Stack();
    dfs(vertArr, myStack, 5, 0);
    free(myStack);
    cout<<endl;
    cout<<"Done\n"<<endl;

    Stack* myStack1 = new Stack();
    int a[5]={-1,-1,-1,-1,-1};
    cout<<detectCycle(vertArr, myStack1, a, 5, 0)<<endl;
    free(myStack1);
    cout<<"Done\n"<<endl;

    return 0;
}
