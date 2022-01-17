#include<iostream>
using namespace std;

// Space complexity - O(n)

// Time complexity - O(n*log(log(n)))
// Refer - https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

// -> The number of prime numbers less than or equal to n is approximately n/ln(n)
// -> The k-th prime number approximately equals k*ln(k)

// PRINT ALL PRIME NUMS TILL N  
void sieve(int n){
    int primes[100] = {0};

    for (int i = 2; i <= n; i++)
    {
        if(primes[i]==0){
            for (int j = i*i; j <= n; i==2?j+=i:j+=2*i)
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