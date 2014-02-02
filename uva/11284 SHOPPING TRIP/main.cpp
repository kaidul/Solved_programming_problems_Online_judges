#include <cstdio>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;
/**
non-classic TSP problem, Floyd for shortest path and DP are used here
matrix 'distance' is used to maintain shortest path of all point pairs
matrix 'cost' is used to maintain actually cost, because we don't need to traverse all points

state:
    dp[i][j] - maximum money saved when point i is visited, j is the bitmask, all have the same
    meaning with tradition TSP problem except we are maximizing how much money saved

transition:
    dp[i][j] = max( dp[i][j], dp[i][Set(j, k)], dp[k][Set(j, k)] - cost[i][k] + discount[k - 1])
    because now we have 2 choices, to buy or not to buy at store k
**/

bool Check(int N, int pos) {
    return (bool)(N & (1 << pos));
}

int Set(int N, int pos) {
    return N | (1 << pos);
}

#define eps 1e-9

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tcase, n, m, p;
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d %d", &n, &m);
        n++;
        double distance[n][n];
        for (int i = 0; i < n; i++)
            fill(distance[i], distance[i] + n, (double)INT_MAX);

        for (int i = 0; i < m; i++) {
            int a, b;
            double c;
            scanf("%d %d %lf", &a, &b, &c);
            distance[a][b] = distance[b][a] = min(distance[a][b], c);
        }
        scanf("%d", &p);
        int store[p];
        double discount[p];
        double cost[p + 1][p + 1];
        double dp[p + 1][(1 << (p + 1) )];

        for (int i = 0; i < p; i++)
            scanf("%d %lf", store + i, discount + i);

        /* Floyd warshell */
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    distance[i][j] = min( distance[i][j], distance[i][k] + distance[k][j] );

        // cost from/to home to/from every store where a opera is available
        for (int i = 0; i < p; i++)
            cost[0][i + 1] = cost[i + 1][0] = distance[0][ store[i] ];

        // cost between stores where a opera is available
        for (int i = 1; i <= p; i++)
            for (int j = 1; j <= p; j++)
                cost[i][j] = distance[ store[i - 1] ][ store[j - 1] ];

        for (int i = 0; i <= p; i++) {
            fill(dp[i], dp[i] + (1 << (p + 1)), (double)INT_MIN);
            dp[i][(1 << (p + 1)) - 1] = -cost[i][0];
        }

        /* TSP */
        for (int mask = (1 << (p + 1)) - 1; mask >= 0; mask--)
            for (int i = 0; i <= p; i++)
                if (Check(mask, i))
                    for (int j = 0; j <= p; j++)
                        if ( !Check(mask, j) )
                            dp[i][mask] = max(dp[i][mask],
                                              max(dp[i][ Set(mask, j) ],
                                                  dp[j][ Set(mask, j) ] - cost[i][j] + discount[j - 1]));

        ( abs(dp[0][1]) > eps ) and (dp[0][1] > 0) ?
        printf("Daniel can save $%.2lf\n", dp[0][1]):
        printf("Don't leave the house\n");
    }
}
