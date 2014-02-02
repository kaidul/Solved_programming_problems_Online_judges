#include <string.h>
#include <stdio.h>

#define Max 101
#define Mod 1000000
int dp[Max][Max];
/**
dp[N][K] = number of ways K numbers less than N add up to N
base case:
    1. number of ways 0 numbers add up to i is 0
        dp[i][0] = 0 for all i
    2. number of ways j numbers add up to 0 is 1
        dp[0][j] = 1 for all j ( i.e. j = 3, 0 + 0 + 0 = 0 )
transition:
    dp[N][K] += dp[i][K - 1] for i = 0....N
**/

void Calc() {
    // base cases
    for (int i = 0; i < Max; i++)
        dp[i][0] = 0;
    for (int j = 0; j < Max; j++)
        dp[0][j] = 1;

    // transitions
    for (int i = 1; i < Max; i++) {
        for (int j = 1; j < Max; j++) {
            dp[i][j] = 0;
            for (int k = 0; k <= i; k++)
                dp[i][j] = (dp[i][j] % Mod + dp[k][j - 1] % Mod) % Mod;
        }
    }
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    Calc();
    int N, K;
    while (scanf("%d%d", &N, &K)) {
        if(!N and !K)
            break;
        printf("%d\n", dp[N][K]);
    }
    return 0;
}
