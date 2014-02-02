#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 500

int c[N+1][N+1];
char x[N], y[N], temp[N];

int LCSLength(int m , int n) {
    int i, j;

    for (i = 1; i <= m; ++i) {
        for (j = 1; j <= n; ++j) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
            } else {
                c[i][j] = c[i][j - 1];
            }
        }
    }
    return c[m][n];
}

int main() {
    int i, j, m, n, cases = 0;

    while( gets(x) && gets(y) != NULL) {
        if( strcmp(x, "#") == 0)
            break;

        m = strlen(x);
        n = strlen(y);

        int len = LCSLength(m, n);
        printf("Case #%d: you can visit at most %d cities.\n",++cases,c[m][n]);
    }
    return 0;
}
