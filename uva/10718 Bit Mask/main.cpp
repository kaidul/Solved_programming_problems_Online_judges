#include <cstdio>
/**
* You're required to find the mask M that, given an integer N, maximizes N|M.
* The optimal solution would be M =~ N. However, you have the restriction L <= M <= R.
* So, we'll build that mask M bit-by-bit (from left to right) in a binary-search fashion keeping in mind the boundaries.
* For each bit in M that we're building we look at the corresponding bit in ~N. There are only two case where we're allowed to place ones in M:
    1. M is still less than R and the corresponding bit in ~N is a one. This is as if we're trying to approach the optimal solution but with caution.
    2. M is less than L. So, we increase it.
If none of those satisfy we place a zero.
**/

typedef unsigned long long int64;
#define I (1ll << 32)

int64 N, L, R, M, m, i;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%lld %lld %lld", &N, &L, &R) == 3) {
        M = 0;
        for (i = I; i > 0; i >>= 1)
            if ( ((m = M | i) <= L) || ((m <= R) && (~N & i)) )
                M = m;

        printf("%lld\n", M);
    }
    return 0;
}
