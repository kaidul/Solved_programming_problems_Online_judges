#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std ;

#define MaxN 1005
#define INF (1 << 30)

int n;
int weight[MaxN],load[MaxN];
int dp[MaxN][MaxN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while(scanf("%d", &n) == 1 && n) {
        // reseting
        for(int i = 0; i < MaxN; i++)
            for(int j = 0; j < MaxN; j++)
                dp[i][j] = INF;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        // taking input
        for(int i = n; i > 0; i--) {
            scanf("%d %d", &weight[i], &load[i]);
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                if(dp[i - 1][j - 1] <= load[i]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + weight[i]);
                    ans = max(ans, j);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
