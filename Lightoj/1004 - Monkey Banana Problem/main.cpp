#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define INF 1 << 30
#define Row 201
#define Col 101

int n, cell[Row][Col], dp[Row][Col];

int max_banana(int i, int j) {
    if(cell[i][j] != -1) {
        if(dp[i][j] != -1) return dp[i][j];
        int ret = -INF;
        if(i < n - 1) {
            ret = max(ret, max_banana(i + 1, j) + cell[i][j]);
            ret = max(ret, max_banana(i + 1, j + 1) + cell[i][j]);
        } else {
            ret = max(ret, max_banana(i + 1, j) + cell[i][j] );
            ret = max(ret, max_banana(i + 1, j - 1) + cell[i][j] );
        }
        return dp[i][j] = ret;
    }
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tcase, caseNo = 0, banana;
    scanf("%d", &tcase);

    while(tcase--) {
        scanf("%d", &n);
        memset(cell, -1, sizeof cell);
        memset(dp, -1, sizeof dp);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i + 1; j++) {
                scanf("%d", &banana);
                cell[i][j] = banana;
            }
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n - i; j++) {
                scanf("%d", &banana);
                cell[n + i - 1][j] = banana;
            }
        }
        printf("Case %d: %d\n", ++caseNo, max_banana(0, 0));
    }
    return 0;
}
