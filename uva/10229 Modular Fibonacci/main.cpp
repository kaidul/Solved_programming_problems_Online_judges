#include <cstdio>
#include <vector>
#define FOR(i, n) for (int i = 1; i <= n; i++)
using namespace std;

typedef long long int64;
typedef vector< vector<int64> > matrix;

int MOD;
#define K 2

// computes A * B
matrix multiply(matrix A, matrix B) {
    matrix C(K + 10, vector <int64> (K + 10));
    FOR(i, K) {
        FOR(j, K) {
            FOR(k, K) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// computes A ^ p
matrix pow(matrix A, int p) {
    if (p == 1)
        return A;
    if (p % 2)
        return multiply(A, pow(A, p - 1));
    matrix X = pow(A, p / 2);
    return multiply(X, X);
}

// returns the N-th term of Fibonacci sequence
int64 fib(int N) {
    // create vector F1
    vector <int64> F1(K + 1);
    F1[1] = 1;
    F1[2] = 1;

    // create matrix T
    matrix T( K + 10, vector <int64> (K + 10) );
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;

    // raise T to the (N-1)th power
    if (N == 1)
        return 1;
    T = pow(T, N - 1);

    // the answer is the first row of T . F1
    int64 ans = 0;
    FOR(i, K) {
        ans = (ans + T[1][i] * F1[i]) % MOD;
    }
    return ans;
}
// Runtime Error :/
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    while ( scanf("%d %d", &n, &m) == 2 ) {
        MOD = (1 << m);
        printf("%lld\n", fib(n) );
    }
    return 0;
}
