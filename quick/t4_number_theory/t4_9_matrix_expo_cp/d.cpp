#include<bits/stdc++.h>
using namespace std;

// Problemset - https://codeforces.com/gym/102644
// Solutions - https://codeforces.com/blog/entry/80195 

#define REP(i,en) for(int i = 0; i < en; i++)
int MOD = 1e9+7;
int N;

struct Matrix {
    vector<vector<int>> arr = vector<vector<int>>(N, vector<int>(N, 0));
    Matrix operator *(const Matrix &other){
        Matrix product;
        vector<vector<long long>> temp(N, vector<long long>(N, 0LL));
        REP(i,N)REP(j,N)REP(k,N){
            temp[i][j] += arr[i][k] * 1LL * other.arr[k][j];
            if(temp[i][j] >= 8LL*MOD*MOD){
                temp[i][j] -= 8LL*MOD*MOD;
            }
        }
        REP(i,N)REP(j,N){
            product.arr[i][j] = (temp[i][j])%MOD;
        }
        return product;
    }
};

Matrix expo_pow(Matrix &a, long long k){
    Matrix product;
    REP(i,N) product.arr[i][i] = 1;
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
        int u; int v;
        cin>>u>>v;
        u--; v--;
        multiplier.arr[u][v] = 1;
    }

    Matrix ans = expo_pow(multiplier, k);
    int total = 0;
    REP(i,N)REP(j,N) total = (total+ans.arr[i][j])%MOD;
    cout<<total<<"\n";
}

int main(){
    countPaths();
}