#include<bits/stdc++.h>
using namespace std;

// Problemset - https://codeforces.com/gym/102644
// Solutions - https://codeforces.com/blog/entry/80195 

#define REP(i,en) for(int i = 0; i < en; i++)
int MOD = 1e9+7;

struct Matrix {
    int arr[2][2] = {{0,0},{0,0}};
    Matrix operator *(const Matrix &other){
        Matrix product;
        REP(i,2)REP(j,2)REP(k,2){
            product.arr[i][j] = (product.arr[i][j] + arr[i][k] * 1LL * other.arr[k][j])%MOD;
        }
        return product;
    }
};

Matrix expo_pow(Matrix &a, long long k){
    Matrix product;
    REP(i,2) product.arr[i][i] = 1;
    while(k>0){
        if(k&1){
            product = product*a;
        }
        a = a*a;
        k>>=1;
    }
    return product;
}

void stringMood(){
    long long n;
    cin>>n;

    Matrix multiplier;
    multiplier.arr[0][0] = 19;
    multiplier.arr[0][1] = 7;
    multiplier.arr[1][0] = 6;
    multiplier.arr[1][1] = 20;

    Matrix ans = expo_pow(multiplier, n);
    cout<<ans.arr[0][0]<<"\n";
}

int main(){
    stringMood();
}