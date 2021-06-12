#include <iostream>
using namespace std;

// LINEAR PATH STARTING FROM S TO E. FIND NO. OF PATHS POSSIBLE WHERE EACH STEPS LENGTH RANGES FROM 1 TO 6
int countPath(int s, int e)
{
    if (s == e)
    {
        return 1;
    }
    if (s > e)
    {
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += countPath(s + i, e);
    }

    return count;
}

// MAZE STARTING FROM (0,0) TO (M,N) FIND NO. OF PATHS POSSIBLE WHERE EACH STEPS LENGTH IS 1 EITHER IN DOWN OR RIGHT DIRECTOIN
int path(int m, int n)
{
    if (m == 1 || n == 1)
    {
        return 1;
    }
    return path(m, n - 1) + path(m - 1, n);
};

// GIVE A BOARD OF SIZE 2XN AND TILE OF SIZE 2X1. FIND NO OF WAYS TO TILE THE GIVEN BOARD USING THESE TILES
// Order doesn't matter that is for n=2 ans should be 1 not 2 as we can rotate tile 90deg to get same configuration
int tilingWays(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    return tilingWays(n - 1) + tilingWays(n - 2);
}

// FIND THE NO OF WAYS IN WHICH N FRIENDS CAN REMAIN SINGLE OR CAN BE PAIRED UP
int pairUp(int n)
{
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }
    return (pairUp(n - 1) + (n - 1) * pairUp(n - 2));
}

// PUT N ITEMS WITH GIVEN WEIGHT AND VALUE IN A KNAPSACK OF CAPACITY W TO GET THE MAX TOTAL VALUE IN THE KNAPSACK
int knapsack(int val[], int wt[], int n, int W)
{
    if (W == 0 || n == 0)
    {
        return 0;
    }

    if(wt[n-1] > W){
        return 0;
    }

    return max(
        knapsack(val, wt, n-1, W-wt[n-1]) + val[n-1], 
        knapsack(val, wt, n-1, W) + 0
    );
}

int main()
{
    // cout<<countPath(0, 3)<<endl;
    // cout<<path(200, 2)<<endl;
    // cout<<tilingWays(4)<<endl;
    // cout<<pairUp(4)<<endl;

    int val[] = {100,50,150};
    int wt[] = {10,20,30};
    cout<<knapsack(val, wt, 3, 50)<<endl;

    return 0;
}