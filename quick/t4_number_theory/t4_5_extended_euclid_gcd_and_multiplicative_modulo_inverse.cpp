#include<bits/stdc++.h>
using namespace std;

// Time complexity same as Euclidean Algorithm - O(log(min(a,b)))

// Diophantine Equations--
// Polynomial equations for which integral solution exists e.g. ax+by=c where
// GCD of a, b has properety that -- gcd(a,b) divides c then
// ax+by=gcd(a,b) for eqn to be Diophantine (or solvable)

struct triplet{
    int x, y, gcd;
};

triplet extendedEuclidAlgo(int a, int b){
    if(b==0){
        triplet ans;
        ans.x = 1;
        ans.y = 0;  // any value u can give
        ans.gcd = a;
        return ans;
    }
    triplet smallAns = extendedEuclidAlgo(b, a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x-(a/b)*smallAns.y;
    return ans;
}

// Multiplicative Modulo Inverse
// Find B such that (A*B)%m = 1  (Note A and m must be co-prime for B to exist)
// Above eqn can be written as Ax+qm = 1 where x = B and q = -(A*B)/m 
int multModInverse(int A, int m){
    triplet ans = extendedEuclidAlgo(A, m);
    // a%m = (a+m)%m so use this in return to avoid -ve x if any;
    return ((ans.x<0) ? (ans.x+m) : (ans.x));  
}

// Given x, y are solutions of ax+by = c then x1 = x + b/g * m and y1 = y - a/g * m are general solutions of this equation for some integer k

// What is min possible value of |x| + |y|?
// We know that x1 = x + b/g * m and y1 = y - a/g * m
// now min(x1+y1) = x + y + m*(b/g-a/g) and we do the case work
// 1)if a>b then choose for max value of m
// 2)ifa<b then choose the min value of m
// 3)if a==b then min(x1+y1) = x+y

int main()
{
    int a, b;
    cin>>a>>b;

    triplet ans = extendedEuclidAlgo(a,b);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;

    cout<<multModInverse(a,b)<<endl;
    cout<<multModInverse(b,a)<<endl;

    return 0;
}