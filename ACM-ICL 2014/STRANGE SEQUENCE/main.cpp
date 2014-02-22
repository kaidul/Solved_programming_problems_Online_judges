#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

struct matrix {
  i64 v[5][5];
  int row, col; // number of row and column
};
i64 mod = 10000007;

// multiplies two matrices and returns the result
matrix multiply(matrix &a, matrix &b) {
  assert(a.col == b.row);
  matrix r;
  r.row = a.row;
  r.col = b.col;
  for (int i = 0; i < r.row; i++) {
    for (int j = 0; j < r.col; j++) {
      i64 sum = 0;
      for (int k = 0; k < a.col;  k++) {
        sum += a.v[i][k] * b.v[k][j];
        sum %= mod;
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

int main() {
    freopen("input.txt", "r", stdin);
  int tcase;
  int a, b, n;

  cin >> tcase;
    a = 1;
    b = 5;
  while (tcase--) {
    // input routine
    scanf("%d", &n);
    // preparing mod value
    matrix mat;
    mat.row = mat.col = 2;
    mat.v[0][0] = mat.v[1][0] = 1;
    mat.v[0][1] = 2;
    mat.v[1][1] = 0;

    if (n < 3) {
      if (n == 1) cout << a << endl;
      if (n == 2) cout << b << endl;
      if (n == 3) cout << (a+b) % mod << endl;
    } else {
      mat = power(mat, n - 2);
      i64 ans = b * mat.v[0][0] + a * mat.v[0][1];
      ans %= mod;
      cout << ans << endl;
    }
  }
  return 0;
}
