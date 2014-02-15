#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define RESET(t,value) memset((t), value, sizeof(t))
typedef long long int64;
typedef long double d64;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PI acos(-1.0)
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define G struct node


#define Max 30001

queue <int> q;
vector <int> node[Max + 1], weight[Max + 1];
int dis[Max + 1];

int dijkstra(int src) {
    FOR(i, 0, Max) dis[i] = -1;
    dis[src] = 0;
    int max_d = -1;
    q.push(src);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        REP(i, node[u].size()) {
            int v = node[u][i];
            int cost = weight[u][i];
            if(dis[v] < 0) {
                q.push(v);
                dis[v] = dis[u] + cost;
                max_d = max(max_d, dis[v]);
            }
        }
    }
    return max_d;
}

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int tcase, caseNo = 0;;
    int n, u, v, cost;
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d", &n);
        for(int i = 0; i < n - 1; ++i) {
            scanf("%d %d %d", &u, &v, &cost);
            node[u].pb(v);
            node[v].pb(u);
            weight[u].pb(cost);
            weight[v].pb(cost);
        }
        printf("Case %d:\n", ++caseNo);
        for(int i = 0; i < n; ++i) {
            printf("%d\n", dijkstra(i));
        }
        FOR(i, 0, Max) {
            node[i].clear();
            weight[i].clear();
        }
    }
    return 0;
}
