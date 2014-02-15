#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
#define Max 41

struct matrix {
    int64 v[Max][Max];
    int64 row, col; // number of row and column
}sum;
int64 mod;
int n, k;

// multiplies two matrices and returns the result
matrix multiply(matrix &a, matrix &b) {
    assert(a.col == b.row);
    matrix ret;
    ret.row = a.row;
    ret.col = b.col;
    for (int64 i = 0; i < ret.row; i++) {
        for (int64 j = 0; j < ret.col; j++) {
            int64 sum = 0;
            for (int64 k = 0; k < a.col;  k++) {
                sum += a.v[i][k] * b.v[k][j];
                sum %= mod;
            }
            ret.v[i][j] = sum;
        }
    }
    return ret;
}

void sum_matrix(matrix &a, matrix &b) {
    for(int i = 0; i < a.row; ++i) {
        for(int j =0; j < a.col; ++j) {
            a[i][j] += b[i][j];
        }
    }
}

// returns mat^p
matrix power(matrix mat, int64 p) {
    assert(p >= 1);
    if (p == 1) return mat;
    if (p & 1) return multiply(mat, power(mat, p - 1));
    matrix ret = power(mat, p / 2);
    ret = multiply(ret, ret);
    return ret;
}

void calculate() {


}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tcase;
    matrix mat;
    while ( cin >> n >> k ) {
        sum.row = mat.row = sum.col = mat.col = n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j)
                sum.v[i][j] = 0;
        }
        for(int i =0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> mat.v[i][j];
            }
        }
        calculate();
    }
    return 0;
}
