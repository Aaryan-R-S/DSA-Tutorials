#include<iostream>
#define m 10
#define n 6
using namespace std;

// driver func
bool isValid(int a[m][m], int x1, int y1, bool vis[m][m]){
    return x1>=0 && y1>=0 && x1<m && y1<m && a[x1][y1]==1 && !vis[x1][y1] ;
};

// main func
int shortestPath(int a[m][m], int x1, int y1, int x2, int y2, bool vis[m][m]){
    if (!isValid(a, x1, y1, vis)) { return 1000000; }
    if (x1==x2 && y1== y2) { return 0; }

    vis[x1][y1] = true;

    int left = shortestPath(a, x1, y1-1, x2, y2, vis) + 1;  
    int up = shortestPath(a, x1-1, y1, x2, y2, vis) + 1;  
    int right = shortestPath(a, x1, y1+1, x2, y2, vis) + 1;  
    int down = shortestPath(a, x1+1, y1, x2, y2, vis) + 1;  

    vis[x1][y1] = false;

    return min(min(left, right), min(up, down));
};

int shortestPath(int a[m][m], int x1, int y1, int x2, int y2){
    bool vis[m][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
        }
    }
    return shortestPath(a, x1, y1, x2, y2, vis);
};

// second e.g.
bool partition(int a[n], int i, int sum, int subArr[n], int sIndex=0){
    if(sum==0){ return true; }
    if(i>=n || sum<0){ return false; }

    subArr[sIndex] = a[i];

    bool leftPossible = partition(a, i+1, sum-a[i], subArr, sIndex+1);
    if (leftPossible){return true;}
    
    subArr[sIndex] = -1;
    return partition(a, i+1, sum, subArr, sIndex);
};

int main()
{
    // int arr[m][m] = {
    //     {1,1,1,1,1,0,0,1,1,1},
    //     {0,1,1,1,1,1,0,1,0,1},
    //     {0,0,1,0,1,1,1,0,0,1},
    //     {1,0,1,1,1,0,1,1,0,1},
    //     {0,0,0,1,0,0,0,1,0,1},
    //     {1,0,1,1,1,0,0,1,1,0},
    //     {1,1,1,1,1,0,0,1,1,1},
    //     {0,0,0,0,1,0,0,1,0,1},
    //     {1,1,1,1,1,0,0,1,1,1},
    //     {0,0,1,0,0,1,1,0,0,1}
    // };

    // int dist = shortestPath(arr, 0, 0, 8, 0);
    // int dist = shortestPath(arr, 0, 0, 0, 8);
    // int dist = shortestPath(arr, 0, 0, 9, 9);
    // if (dist>=1000000)
    // {
    //     cout<<"No path possible!"<<endl;
    // }
    // else{
    //     cout<<dist<<endl;
    // }
    

    int myArr[n] = {2,1,2,3,4,8};

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=myArr[i];
    }
    int subArr[n];
    for (int i = 0; i<n; i++)
    {
        subArr[i] = -1;
    }

    bool isPossible = (sum%2 == 0) && partition(myArr, 0, sum/2, subArr);

    if (isPossible)
    {
        for (const auto &i :subArr)
        {
            if (i!=-1)
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    else{
        cout<<"Not possible"<<endl;
    }

    return 0;
}