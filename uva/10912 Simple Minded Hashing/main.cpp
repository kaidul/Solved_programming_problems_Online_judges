#include <stdio.h>
#include <string.h>

/**
Each case consists of 2 integers L and S. (0 < L, S < 10000). - this is a trap.
dp[i][j][k] denotes the total number of strings of length j that starts with letter i which maps to an integer k
i.e. dp[1][3][10] = 4 (abg, acf, ade, bce)
**/
// (26 * 27) / 2 = 351
#define MaxS 351
#define MaxL 26

bool visited[MaxL + 1] [MaxL + 1] [MaxS + 1];
int dp[MaxL + 1] [MaxL + 1] [MaxS + 1];

int solve(int ascii, int length, int sum) {

    if (length == 0)
        return sum == 0 ? 1 : 0;

    if (sum < 0 or ascii > MaxL or length > MaxL or sum > MaxS )
        return 0;

    if (visited[ascii] [length] [sum])
        return dp[ascii] [length] [sum];

    visited[ascii] [length] [sum] = true;

    int ans = 0;
    for (int i = ascii; i <= MaxL; i++)
        ans += solve(i + 1, length - 1, sum - i);

    return dp[ascii][length][sum] = ans;
}

int main(void) {
    int L, S, tcase;
    memset( visited, false, sizeof visited );

    for ( tcase = 1; scanf("%d %d", &L, &S) == 2 and L > 0; tcase++ )
        printf("Case %d: %d\n", tcase, solve(1, L, S) );

    return 0;
}
