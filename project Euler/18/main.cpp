#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define INF 1 << 30
#define Row 201
#define Col 101

int cell[Row][Col], dp[Row][Col];

int max_banana(int i, int j) {
    if(cell[i][j] != -1) {
        if(dp[i][j] != -1) return dp[i][j];
        int ret = -INF;
        ret = max(ret, max_banana(i + 1, j) + cell[i][j]);
        ret = max(ret, max_banana(i + 1, j + 1) + cell[i][j]);
        return dp[i][j] = ret;
    }
    return 0;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    memset(cell, -1, sizeof cell);
    memset(dp, -1, sizeof dp);

    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < i + 1; j++) {
            cin >> cell[i][j];
        }
    }
    printf("%d\n", max_banana(0, 0));
    return 0;
}
