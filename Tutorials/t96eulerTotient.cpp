#include<bits/stdc++.h>
using namespace std;

// Refer Apna College -- Lect 37.3
// Totient of n or phi(n) = no of coprimes 'm' till n where (1<=m<n)

int main()
{
    int MOD = 1e9+7;    
    int N = 1e5+2;    

    int totient[N];

    for (int i = 0; i < N; i++)
    {
        totient[i] = i;
    }

    for (int i = 2; i < N; i++)
    {
        if(totient[i]==i){
            for (int j = 2*i; j < N; j+=i)
            {
                totient[j] *= i-1;
                totient[j] /= i;
            }
            totient[i] = i-1;
        }
    }
    
    for (int i = 1; i < 11; i++)
    {
        cout<<totient[i]<<" ";
    }
    
    
    return 0;
}