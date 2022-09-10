#include<bits/stdc++.h>
using namespace std;

// Space complexity - O(n)

// Time complexity - O(n*log(log(n)))
// Refer - https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

// -> The number of prime numbers less than or equal to n is approximately n/ln(n)
// -> The k-th prime number approximately equals k*ln(k)
// -> Goldbach’s conjecture: Each even integer n > 2 can be represented as a sum n = a+b so that both a and b are primes. [https://codeforces.com/problemset/problem/584/D]

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

// Q(2.1) Print divisors of numbers (with their sum) till N - O(n^2))
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

// Avoiding TLE on CF - O(sqrt(N))
int fastFactorization(int n) {
    int factorization=0;
    for (int d : {2, 3, 5}) {
        while ((n % d) == 0) {
            factorization++;
            n /= d;
        }
    }
    vector<int> increments{4, 2, 4, 2, 4, 6, 2, 6};
    
    int i = 0;
    for (int d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization++;
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization++;
    return factorization;
}

// Q(2.3) Primality Test - O(k*log(n)) << O(sqrt(n))
// - https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/
#define ll long long
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

bool millerTest(ll d, ll n){
    ll a = 2 + rand() % (n - 4);
    ll x = expo(a, n-1, n);
    if(x==1 || x==n-1){
        return true;
    }
    while(d != n-1){
        x = mod_mul(x,x,n);
        d *= 2;
        if(x==1) return false;
        if(x==n-1) return true;
    }
    return false;
}

void primesTill(){
    ll N; cin>>N;
    ll K; cin>>K;
    vector<ll> a;
    a.push_back(2);
    a.push_back(3);
    bool prime;
    for (int i = 5; i <= N; i++){
        prime = true;
        ll d = i-1;
        while(d%2==0){
            d/=2;
        }
        for (int j = 0; j < K; j++){
            if(millerTest(d, i)==false){
                prime = false;
                break;
            }   
        }
        if(prime){
            a.push_back(i);
        }
    }

    for(auto i:a){
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