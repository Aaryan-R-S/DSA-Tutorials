#include<iostream>
using namespace std;

// PRINT ALL PRIME NUMS TILL N  
void sieve(int n){
    int primes[100] = {0};

    for (int i = 2; i <= n; i++)
    {
        if(primes[i]==0){
            for (int j = i*i; j <= n; j+=i)
            {
                primes[j] = 1;    
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if(primes[i]==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

// PRIME FACTORS OF N
void factor(int n){
    int smallestPrimeFactor[100] = {0};

    for (int i = 2; i <= n; i++)
    {
        if(smallestPrimeFactor[i]==0){
            smallestPrimeFactor[i] = i;
            for (int j = i*i; j <= n; j+=i)
            {
                if (smallestPrimeFactor[j]==0)
                {
                    smallestPrimeFactor[j] = i;    
                }
            }
        }
    }

    while (n!=1)
    {
        cout<<smallestPrimeFactor[n]<<" ";
        n /= smallestPrimeFactor[n]; 
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    sieve(n);
    factor(n);
    
    return 0;
}