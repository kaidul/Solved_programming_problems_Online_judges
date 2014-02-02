#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ui64;

#define Max 512

static int n, an1;
static ui64 dp[Max][Max];
static bool found[Max][Max];

static ui64 solve(int i, int j) {
    int k;
    ui64 sum1 = 0, sum2 = 0, sum = 0, ret;

    if (found[i][j])
        return dp[i][j];

    if (i < j) {
        for (k = i; k < j; k++) {
            ret = solve(i, k) + solve(k + 1, j);
            sum = max(sum, ret);
        }

        found[i][j] = true;
        return dp[i][j] = sum;
    }

    if (i < n) {
        for (k = i + 1; k <= n; k++) {
            ret = solve(k, 1) + solve(k, j);
            sum2 = max(sum2, ret);
        }
    } else { // i = n
        sum2 = 0;
    }

    if (j > 1) { // j > 0 is not possible because k = 1 and k < j
        for (k = 1; k < j; k++) {
            ret = solve(i, k) + solve(n, k);
            sum1 = max(sum1, ret);
        }
    } else { // j = 0
        sum1 = 0;
    }

    found[i][j] = true;
    return dp[i][j] = sum1 + sum2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d %d", &n, &an1) == 2) {
        memset( found, 0, sizeof found );

        found[n][1] = true;
        dp[n][1] = an1;

        printf("%lld\n", solve(1, n) );
    }

    return 0;
}
