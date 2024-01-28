#include<bits/stdc++.h>
using namespace std;

// Tutorial - https://youtu.be/qIXg9vJ6hZM?si=209n05kT6_yh2yA0
// CF Blog - https://codeforces.com/blog/entry/68953

// You have been given N non-negative integers:

// Problem 1 - Number of different XOR values possible
// Solution - 2 ^ (size of basis)

// Problem 2 - Largest XOR value you can make
// Problem 3 - Kth Largest XOR value you can make 

const int d = 10; // Highest non-zero bit position in XOR space

int basis[d]; // basis[i] keeps the mask of the vector whose f value is i

int sz; // Current size of the basis

void insertVector(int mask) {
	for (int i = 0; i < d; i++) {
		if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)

		if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
			basis[i] = mask;
			++sz;
			
			return;
		}

		mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
	}
}

int main(){

    return 0;
}