#include<bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>

// Recursion -- O(2^n)
// DP -- O(n)
// To calculate fib(n) in O(log(n))
// Using matrix exponentiation see Apna College Vid
// fib(n)    =  [1 1]^(n-2)   X   fib(2)
// fib(n-1)  =  [1 0]         X   fib(1)

vvi multiplyMatrix(vvi &a, vvi &b){
    vvi ans(a.size(), vector<int>(a.size(), 0));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            for (int k = 0; k < a.size(); k++)
            {
                ans[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return ans;
}

vvi matrixExponentiate(vvi &a, int n){
    if(n==0){
        int sz = a.size();
        vvi ans(sz, vector<int>(sz, 0));
        for (int i = 0; i < sz; i++)
        {
            ans[i][i] = 1;
        }
        return ans;
    }
    if(n==1){
        return a;
    }
    vvi temp = matrixExponentiate(a, n/2);
    vvi ans = multiplyMatrix(temp, temp);
    if(n&1){
        ans = multiplyMatrix(ans, a);
    }
    return ans;
}

int main()
{
    int n; cin>>n;
    vvi a = {{1,1},{1,0}};

    vvi ans = matrixExponentiate(a,n);

    for (int  i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    // ANS - fib(n) is ans[1][1]

    return 0;
}