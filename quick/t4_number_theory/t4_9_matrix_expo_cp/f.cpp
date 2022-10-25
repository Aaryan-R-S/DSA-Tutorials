#include<bits/stdc++.h>
using namespace std;

// Problemset - https://codeforces.com/gym/102644
// Solutions - https://codeforces.com/blog/entry/80195 

#define REP(i,en) for(int i = 0; i < en; i++)
const long long INF = 3e18L+5;
int N;

struct Matrix {
    vector<vector<long long>> arr = vector<vector<long long>>(N, vector<long long>(N, INF));
    Matrix operator *(const Matrix &other){
        Matrix product;
        REP(i,N)REP(j,N)REP(k,N){
            product.arr[i][j] = min(product.arr[i][j], arr[i][k] + other.arr[k][j]);
        }
        return product;
    }
};

Matrix expo_pow(Matrix &a, int k){
    Matrix product;
    REP(i,N) product.arr[i][i] = 0;
    while(k>0){
        if(k&1){
            product = product*a;
        }
        a = a*a;
        k>>=1;
    }
    return product;
}

void countPaths(){
    int m, k;
    cin>>N>>m>>k;

    Matrix multiplier;
    REP(i,m){
        int u, v, c;
        cin>>u>>v>>c;
        multiplier.arr[u-1][v-1] = c;
    }

    Matrix ans = expo_pow(multiplier, k);
    long long minDist = INF;
    REP(i,N) REP(j,N) minDist = min(minDist, ans.arr[i][j]);
    if(minDist>=1e18L+5){
        cout<<"IMPOSSIBLE"<<"\n";
    }
    else{
        cout<<minDist<<"\n";
    }
}

int main(){
    countPaths();
}