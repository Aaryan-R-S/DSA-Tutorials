#include<bits/stdc++.h>
using namespace std;

// Euler's totient function, also known as phi-function , counts the number of integers between 1 and n inclusive, which are coprime to n.
// Totient of n or phi(n) = no of coprimes of 'n' less than or equal to n

// Time Complexity - O(sqrt(n))
// Just use it; DO NOT try to understand.
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// Time Complexity same as Sieve - O(n*log(log(n)))
void phi_1_to_n(int N){
    int MOD = 1e9+7;    

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
    
    for (int i = 1; i < N; i++)
    {
        cout<<totient[i]<<" ";
    }

    return;
}

int main()
{
    int n; cin>>n;

    cout<<phi(n)<<endl;

    phi_1_to_n(n+1);
    
    return 0;
}