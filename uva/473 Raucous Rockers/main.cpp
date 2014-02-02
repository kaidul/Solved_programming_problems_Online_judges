#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

/**

Type: DP
Algorithm:
* Let f(i, j, k) be the largest amount of songs from 1 to k can be written into the disks from 1 to i with disk i having space j
* There are 3 cases:
    1. j = 0: This mean disk i has space of 0, hence it cannot carry any song, there for
       f(i, j, k) for this case is f(i - 1, t, k), that is, the number of songs were written in
       the previous i - 1 disk. Of course the previous disks can carry song k since the
       current disk doesnt have any space to carry it.

    2. songs[k] <= j: The space of disk i is enough to carry the song k. There are two choices
       for us now: choose k or not choose k. If we choose song k, f(i, j, k) is equal to
       f(i, j- songs[k], k - 1) + 1. That is, before we choose k, the space is j - songs[k],
       and the set of songs is 1 to k - 1 because we cannot choose k twice. If we dont choose song k,
       f(i, j, k) is equal to f(i, j, k-1). That is, if we dont choose song k, the space is still j,
       and the set of song is 1 to k-1 excluding song k. Hence:

       f(i, j, k) = max(f(i, j - songs[k], k - 1) + 1, f(i, j, k - 1)) for songs[k] <= j;

    3. songs[k] > j: The space of disk i is not enough to carry song k. There are two cases now:
       If before k there are no songs has been chosen for disk i, this mean f(i, j, k) now is
       f(i - 1, t, k), now there are only songs that were chosen in the previous disks.
       If there are songs that has been chosen for disk i, this mean f(i, j, k) now is
       f(i, j, k - 1), that is, the set of songs now is only from 1 to k - 1. Hence:
       f(i, j, k) = max( f(i - 1, t, k), f(i, j, k - 1)) for songs[k] > j;

 So we have complete our DP algorithm, the next tricky thing is the bound of n, m, t.
 I think they are quiet large so I give them 10000, 200, 200. This takes quiet a lot of
 memory space. Maybe we can use the space saving trick to fix this, 2 matrixs of (t * m)
 size is ok since we only consider the number of songs to the previous disk only. The complexity
 is O(n * m * t).

**/

int songs[10241];
int dp[200][200][10241];
int n, m, t;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tcase;
    scanf("%d", &tcase);
    while(tcase--) {
        scanf("%d %d %d", &n, &t, &m);
        string num;
        scanf("%d", &songs[1]);
        for (int i = 2; i <= n; i++) {
            scanf(", %d", &songs[i]);
        }

        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= t; j++)
                for (int k = 0; k <= n; k++)
                    dp[i][j][k] = 0;

        for (int i = 1; i <= m; i++)
            for (int j = 0; j <= t; j++)
                for (int k = 1; k <= n; k++)
                    if (j == 0) dp[i][j][k] = dp[i - 1][t][k];
                    else if (songs[k] <= j)
                            dp[i][j][k] = max(dp[i][j][k - 1], dp[i][ j - songs[k] ][k - 1] + 1);
                    else if (songs[k] > j)
                            dp[i][j][k] = max(dp[i - 1][t][k], dp[i][j][k - 1]);

        printf("%d\n", dp[m][t][n]);
        if (tcase) printf("\n");
    }
    return 0;
}
