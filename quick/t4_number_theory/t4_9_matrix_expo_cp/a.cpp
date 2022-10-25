#include<bits/stdc++.h>
using namespace std;

// Problemset - https://codeforces.com/gym/102644
// Solutions - https://codeforces.com/blog/entry/80195 

#define ld long double
#define REP(i,en) for(int i = 0; i < en; i++)

struct Matrix {
    ld arr[2][2] = {{0,0},{0,0}};
    Matrix operator *(const Matrix &other){
        Matrix product;
        REP(i,2)REP(j,2)REP(k,2){
            product.arr[i][j] += arr[i][k] * other.arr[k][j];
        }
        return product;
    }
};

Matrix expo_pow(Matrix &a, int k){
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

void randomMood(){
    int n; ld p;
    cin>>n>>p;

    Matrix multiplier;
    multiplier.arr[0][0] = 1-p;
    multiplier.arr[0][1] = p;
    multiplier.arr[1][0] = p;
    multiplier.arr[1][1] = 1-p;

    Matrix ans = expo_pow(multiplier, n);
    cout<<setprecision(10)<<fixed<<ans.arr[0][0]<<"\n";
}

int main(){
    randomMood();
}