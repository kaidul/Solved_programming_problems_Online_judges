#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define Max 20
static int sticks[Max + 1], side, n, maxN;
unsigned dp[((1 << Max) >> 5)];

int Set(int N, int pos) {
    return N = N | (1 << pos);
}
bool Check(int N, int pos) {
    return (bool)(N & (1 << pos));
}

bool square(int s, int mask) {
    if ( Check(dp[mask >> 5], mask & 31) )
        return false;
    dp[mask >> 5] = Set(dp[mask >> 5], mask & 31);
    if (mask == maxN)
        return true;
    if (s > side)
        return false;
    if (s == side)
        s = 0;
    for (int j = 0; j < n; j++)
        if ( !Check(mask, j) and square(s + sticks[j], Set(mask, j) ) )
            return true;
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tcase;
    scanf("%d", &tcase);
    while(tcase--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &sticks[i]);
        side = 0;
        for (int i = 0; i < n; i++)
            side += sticks[i];

        if ((side % 4) != 0) {
            printf("no\n");
            continue;
        }
        side /= 4;
        maxN = (1 << n) - 1;
        memset(dp, false, sizeof(dp));
        printf(square(0, 0) ? "yes\n" : "no\n");
    }

    return 0;
}
