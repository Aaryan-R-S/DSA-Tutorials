#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Fermat Little Theorem------------------------------------------------------------
// Given a prime 'p' and an integer 'a'
// then a^p === a (mod p)
// OR
// Given a prime 'p' and an integer 'a'
// if p does not divide a (or gcd(a,n)=1)
// then a^(p-1) === 1 (mod p)

// GENRALIZATION
// a^phi(n) === 1 (mod n) if gcd(a,n)=1

// CONCLUSION
// a^(p-2) === a^(-1) (mod p) [MODULO INVERSE]

// Used in calculating (a/b)%m = a%m * (b^-1)%m    where b^-1 is multiplicative modulo inverse
// (b^-1)%m = b^(m-2) mod m    (You can also use Extended Euclidean Algorithm for the same)

// Wilson Theorem--------------------------------------------------------------------
// n>1 is a prime if and only if 
// (n-1)! === -1 (mod n)
// OR
// (n-1)! === n-1 (mod n)

// Used in calculating N! modulo P = ((P-1)! mod p * (n+1)^-1 mod p * (n+2)^-1 mod p *...* (P-1)^-1 mod p
// which is equal to p-1 * product of mod inverse of n+1, n+2, .... to p-1

int main()
{

    return 0;
}