#include <iostream>
#define m 4
using namespace std;

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

void intialD(int wtArr[m][m], int dPos[m][m])
{
    int inf = 10000;  // Infinite or max
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (wtArr[i][j]==0 && i!=j){
                dPos[i][j] = inf;
            }else{
                dPos[i][j] = wtArr[i][j];
            }
        }
    }
}

void setEqual(int dPre[m][m], int dPos[m][m])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dPre[i][j] = dPos[i][j];
        }
    }
}

void setdPos(int dPre[m][m], int dPos[m][m], int k){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dPos[i][j] = dPre[i][k]+dPre[k][j] < dPre[i][j] ? dPre[i][k]+dPre[k][j] : dPre[i][j];
        }
    }
};

void allToallDist(int vertArr[m][m], int wtArr[m][m]){
    int dPre[m][m];
    int dPos[m][m];
    intialD(wtArr, dPos);
    for (int i = 0; i < m; i++)
    {
        setEqual(dPre, dPos);
        setdPos(dPre, dPos, i);
        displayMatrix(dPre);
        cout<<"D"<<i<<": Done\n"<<endl;
    }
    displayMatrix(dPos);
    cout<<"D"<<m<<": Done"<<endl;
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
    add_edge(vertArr, wtArr, 0, 1, 9, true);
    add_edge(vertArr, wtArr, 0, 2, -4, true);
    add_edge(vertArr, wtArr, 1, 0, 6, true);
    add_edge(vertArr, wtArr, 1, 3, 2, true);
    add_edge(vertArr, wtArr, 2, 1, 5, true);
    add_edge(vertArr, wtArr, 3, 2, 1, true);
    cout<<"Done\n"<<endl;

    displayMatrix(vertArr);
    cout<<"Done\n"<<endl;

    displayMatrix(wtArr);
    cout<<"Done\n"<<endl;

    allToallDist(vertArr, wtArr);
    cout<<"Done\n"<<endl;

    return 0;
}