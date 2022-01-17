#include<iostream>
using namespace std;

// EUCLID PRINCIPLE ->
// GCD(a, b) = GCD(b, a-b) = GCD(b, a%b) 

// Time complexity - Consecutive Fibonacci numbers are the worst case input for Euclid's algorithm. Given that Fibonacci numbers grow exponentially, we get that the Euclidean algorithm works in O(log(min(a,b)))
// Refer - https://www.geeksforgeeks.org/time-complexity-of-euclidean-algorithm/

// In other words, if
// -> a = q1*b + r1
// -> b = q2*r1 + r2
// -> ...
// -> r(n-2) = qn*r(n-1) + rn
// then gcd(a,b) = gcd(b, r1) = ... = gcd(r(n-1), rn)

int gcd(int a, int b){
    while (b!=0){
        int rem = a%b;
        a = b;
        b = rem;
    }
    return a;
}

// Note that LCM*GCD = a*b 

int lcm(int a, int b){
    // return a * b / gcd(a,b);
    // OR
    // cleverly avoids integer overflows by first dividing `a` with the GCD
    return a / gcd(a,b) * b;
}

int main()
{
    int a, b;
    cin>>a>>b;

    cout<<gcd(a, b)<<endl;
    cout<<lcm(a, b)<<endl;

    return 0;
}