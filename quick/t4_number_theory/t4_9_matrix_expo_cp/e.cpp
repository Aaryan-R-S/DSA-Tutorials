#include<bits/stdc++.h>
using namespace std;

// Problemset - https://codeforces.com/gym/102644
// Solutions - https://codeforces.com/blog/entry/80195 

#define REP(i,en) for(int i = 0; i < en; i++)
int N = 65;

struct Matrix {
    vector<vector<unsigned int>> arr = vector<vector<unsigned int>>(N, vector<unsigned int>(N, 0));
    Matrix operator *(const Matrix &other){
        Matrix product;
        REP(i,N)REP(j,N)REP(k,N){
            product.arr[i][j] += arr[i][k] * other.arr[k][j];
        }
        return product;
    }
};

Matrix expo_pow(Matrix &a, int k){
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

bool inside(int row, int col){
    if(min(row,col)>=0 && max(row,col)<8){
        return true;
    }
    return false;
}

void countPaths(){
    int k;
    cin>>k;
    k++;

    Matrix multiplier;
    REP(row,8){
        REP(col,8){
            for(int dr: {-2,-1,1,2}){
                for(int dc: {-2,-1,1,2}){
                    if(abs(dr)==abs(dc)){
                        continue;
                    }
                    int new_row = row+dr;
                    int new_col = col+dc;
                    if(inside(new_row, new_col)){
                        multiplier.arr[8*row+col][8*new_row+new_col] = 1;
                    }
                }
            }
        }
    }
    REP(i,65){
        multiplier.arr[i][64] = 1;
    }

    Matrix ans = expo_pow(multiplier, k);
    cout<<ans.arr[0][64]<<"\n";
}

int main(){
    countPaths();
}