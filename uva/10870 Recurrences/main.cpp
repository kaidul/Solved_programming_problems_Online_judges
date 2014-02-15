#include <bits/stdc++.h>
using namespace std;

#define Max 16
typedef long long int64;

struct matrix {
    int64 v[Max][Max];
    int row, col; // number of row and column
};
int d, n, m;

// multiplies two matrices and returns the result
matrix multiply(matrix &a, matrix &b) {
    matrix r;
    r.row = r.row = d;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            int64 sum = 0;
            for (int k = 0; k < d;  k++) {
                sum += a.v[i][k] * b.v[k][j];
                sum %= m;
            }
            r.v[i][j] = sum;
        }
    }
    return r;
}

string binary(int p) {
  string ret = "";
  while (p > 0) {
    ret += (p % 2 == 0) ? "0" : "1";
    p /= 2;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

matrix power(matrix mat, int p) {
  string bin = binary(p);
  matrix ret = mat;
  for (int i = 1; i < bin.size(); i++) {
    ret = multiply(ret, ret);
    if (bin[i] == '1') {
      ret = multiply(ret, mat);
    }
  }
  return ret;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tcase;
    int a;
    int f[Max];
    while (cin >> d >> n >> m) {
        if(!d and !n and !m) break;
        matrix mat;
        mat.row = mat.col = d;
        for(int i = 0; i < d; ++i) {
            cin >> mat.v[0][i];
        }
        for(int i = 1; i < d; ++i) {
            for(int j = 0; j < d; ++j) {
                if(i == j + 1) {
                    mat.v[i][j] = 1;
                    continue;
                }
                mat.v[i][j] = 0;
            }
        }
        for(int i = 0; i < d; ++i) {
            cin >> f[i];
        }
        if (n <= d) {
            cout << f[n - 1] << endl;
        } else {
            mat = power(mat, n - d);
            int64 ans = 0;
            for(int i = 0; i < d; ++i) {
                ans += f[d - i - 1] * mat.v[0][i];
                ans %= m;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
