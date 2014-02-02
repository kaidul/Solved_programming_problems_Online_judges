#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define READ(f) freopen(f, "r", stdin)

/**  Main Code **/

#define Max 500
#define No_city 100
#define No_days 200

bool visited[No_city + 1][No_days + 1];
bool dp[No_city + 1][No_days + 1];
vector<int> adj[Max + 10];
int cities, edge, start, end, days;

bool tsp (int city, int days) {
    if(days == 0) {
        if (city == end)
            return true;
        return false;
    }

    if (visited[city][days])
        return dp[city][days];

    visited[city][days] = true;
    bool ans = false;

    for (int i = 0; i < (int) adj[city].size(); i++) {
        ans = ans or tsp(adj[city][i], days - 1);
        if(ans) break;
    }
    return dp[city][days] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int u, v;
    while(scanf("%d%d", &cities, &edge) != EOF and cities and edge >= 0) {

        for (int i = 0; i < edge; i++) {
        	scanf("%d %d", &u, &v);
        	adj[u].push_back(v);
        	adj[v].push_back(u);
        }
        scanf("%d%d%d", &start, &end, &days);

        mem(visited, false);

        tsp(start, days) ? printf("Yes, Teobaldo can travel.\n") :
                           printf("No, Teobaldo can not travel.\n");

        for (int i = 0; i < cities + 5; i++)
            adj[i].clear();
    }
    return 0;
}


/**
state:
    dp[i][j] - can be 0 or 1, whether can reach city j at day i
transition:
    dp[i][j] = true if ( path[k][j] and dp[i - 1][k] ), 1 <= k <= n
    for all city k, if there is a link between k and j, and he was there yesterday
    then of course he can reach city j today
**/

/*
int cities, edge, start, end, days, u, v;

bool path[No_city + 1][No_city + 1];
bool dp[No_days + 1][No_city + 1];

int main(void) {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    while (scanf("%d %d", &cities, &edge) != EOF and cities and edge >= 0) {
        memset(path, false, sizeof path);
        for (int i = 0; i < edge; i++) {
            scanf("%d %d", &u, &v);
            path[u][v] = true;
            path[v][u] = true;
        }
        scanf("%d %d %d", &start, &end, &days);
        memset(dp, false, sizeof dp);
        dp[0][start] = true;
        for (int i = 1; i <= days; i++) {
            for (int j = 1; j <= cities; j++) {
                for (int k = 1; k <= cities; k++) {
                    if(dp[i - 1][k] and path[k][j])
                        dp[i][j] = true;
                }
            }
        }

        dp[days][end] ? printf("Yes, Teobaldo can travel.") : printf("No, Teobaldo can not travel.");
        putchar('\n');
    }
    return 0;
}
*/
