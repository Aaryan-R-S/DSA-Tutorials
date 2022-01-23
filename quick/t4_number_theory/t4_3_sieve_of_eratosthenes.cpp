#include<bits/stdc++.h>
using namespace std;

// Space complexity - O(n)

// Time complexity - O(n*log(log(n)))
// Refer - https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

// -> The number of prime numbers less than or equal to n is approximately n/ln(n)
// -> The k-th prime number approximately equals k*ln(k)

// Basic - PRINT ALL PRIME NUMS TILL N  
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

// Q(1.1) PRIME FACTORS OF N using Sieve - O(n*log(log(n)))
// Also, Smallest and Largest PRIME FACTORS till N using Sieve - O(n*log(log(n)))
void primeFactorSieve(int n){
    int smallestPrimeFactor[100] = {0};
    int largestPrimeFactor[100] = {0};

    for (int i = 2; i <= n; i++){
        if(smallestPrimeFactor[i]==0){
            smallestPrimeFactor[i] = largestPrimeFactor[i] = i;
            for (int j = 2*i; j <= n; j+=i){
                largestPrimeFactor[j] = i;
                if (smallestPrimeFactor[j]==0){
                    smallestPrimeFactor[j] = i;    
                }
            }
        }
    }

    cout<<"Prime Factorisation of N"<<endl;
    int a = n;
    while (a!=1){
        cout<<smallestPrimeFactor[a]<<" ";
        a /= smallestPrimeFactor[a]; 
    }cout<<endl;

    cout<<"{smallestPrimeFactor,largestPrimeFactor}"<<endl;
    for (int i = 2; i<=n; i++){
        cout<<"{"<<smallestPrimeFactor[i]<<","<<largestPrimeFactor[i]<<"} "<<endl;        
    }

}

// Q(1.2) PRIME FACTORS OF N - O(sqrt(n))
void primeFactorN(int n){
    vector<int> primeFact;
    for (int i = 2; i*i <= n; i++){
        while(n%i==0){
            primeFact.push_back(i);
            n/=i;
        }
    }
    if(n!=1){
        primeFact.push_back(n);
    }
    for(auto i:primeFact){
        cout<<i<<" ";
    }cout<<endl;
}

// Q(2.1) Print divisors of numbers (with their sum) till N - O(n*log(log(n)))
void divisorsSieve(int n){
    vector<int> divs[n+1];
    vector<int> sums(n+1);
    for (int i = 1; i <= n; i++){
        divs[i].push_back(1);
        sums[i] = 1;
    }
    

    for (int i = 2; i <= n; i++){
        for (int j = i; j <= n; j+=i){
            divs[j].push_back(i);
            sums[j] += i;
        }
    }

    for (int j = 1; j <= n; j++){
        cout<<sums[j]<<": ";
        for(auto i:divs[j]){
            cout<<i<<" ";
        }cout<<endl;
    }
    
}

// Q(2.2) Count number of divisors of N and sum of its divisors - O(sqrt(n))
void divisorsN(int n){
    vector<int> divs;
    int cntDiv = 0;
    int sumDiv = 0;
    for (int i = 1; i*i <= n; i++){
        if(n%i==0){
            divs.push_back(i);
            cntDiv+=1;
            sumDiv+=i;
            if(n/i!=i){
                divs.push_back(n/i);
                cntDiv+=1;
                sumDiv+=n/i;
            }
        }
    }
    sort(divs.begin(), divs.end());
    cout<<cntDiv<<" "<<sumDiv<<endl;
    for(auto i:divs){
        cout<<i<<" ";
    }cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    sieve(n);
    cout<<endl;
    primeFactorSieve(n);
    cout<<endl;
    primeFactorN(n);
    cout<<endl;
    divisorsSieve(n);
    cout<<endl;
    divisorsN(n);
    cout<<endl;
    
    return 0;
}