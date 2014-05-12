/*
#include <bits/stdc++.h>

using namespace std;

#define eps 1e-6
#define Max 45

int n, m;
struct couple {
    int color, cost;
    couple(): color(), cost() {}
    couple(int x, int y): color(x), cost(y) {}
    bool operator < (const couple &other) const {
        return color < other.color;
    }
} arr[Max];

int dp[Max][Max][Max];

int solve(int pos, int taken, int last_color) {
    if(pos == n) {
        if(taken >= m) return 1;
        return 0;
    }
    int add = 0;
    if(last_color != arr[pos].color) ++add;
    int ans = solve(pos + 1, taken + add, arr[pos].color) + solve(pos + 1, taken, last_color);
    return ans;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int tcase;
    int color, cost;
    double ans;
    scanf("%d", &tcase);
    while(tcase--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &color, &cost);
            arr[i] = couple(color, cost);
        }
        sort(arr, arr + n);
        memset(dp, -1, sizeof dp);
        int subsets = solve(0, 0, 0);
//        ans = double(ans) / cont;
        printf("%d\n", subsets);
    }
    return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#define Max 45

/*
    dp[i][j] = sum of all subsets has j different colors color_index from 1 to i
    S[i] = sum of all subsets of ballons having i color
*/
int n, m, P[Max][Max], nball[Max], color[Max], cost[Max];
i64 dp[Max][Max], Cnt[Max][Max], S[Max];

int main(void) {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
#endif
    int tcase;
    scanf("%d", &tcase);
    while(tcase--) {
        scanf("%d %d", &n, &m);
        memset(nball, 0, sizeof nball);
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", color + i, cost + i);
            // P[i][j] = cost of jth ball of ith color
            // nball[i] = number of ball with color i
            P[ color[i] ][nball[ color[i] ]++] = cost[i];
        }
        for(int i = 1; i <= 40; ++i) {
            S[i] = 0;
            for(int j = 0; j < nball[i]; ++j) {
                S[i] += P[i][j] * (1LL << (nball[i] - 1));
            }
        }
        memset(Cnt, 0, sizeof Cnt);
        memset(dp, 0, sizeof dp);
        Cnt[0][0] = 1;
        for(int i = 1; i <= 40; ++i) {
            Cnt[i][0] = 1;
            for(int j = 1; j <= i; ++j) {
                if(nball[i] > 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * ((1LL << nball[i]) - 1) + Cnt[i - 1][j - 1] * S[i];
                    Cnt[i][j] = Cnt[i - 1][j] + Cnt[i - 1][j - 1] * ((1LL << nball[i]) - 1);
                } else {
                    dp[i][j] = dp[i - 1][j];
                    Cnt[i][j] = Cnt[i - 1][j];
                }
            }
        }
        double total_sum = 0, total_cnt = 0, res;
        for(int j = m; j <= n; ++j) {
            total_sum += dp[40][j];
            total_cnt += Cnt[40][j];
        }
        res = total_sum / total_cnt;
        printf("%.9lf\n", res);
    }
    return 0;
}
