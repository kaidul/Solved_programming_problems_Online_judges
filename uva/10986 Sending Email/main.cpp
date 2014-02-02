#include <bits/stdc++.h>
using namespace std;
/*** typedef ***/
#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define vi vector<int>
#define vpii vector<pii>
#define si set<int>
#define msi map<string , int >
#define mis map<int , string >
typedef long long i64;
typedef unsigned long long ui64;
/** function **/
#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)
#define pf printf
#define sf scanf
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
const i64 INF64 = (i64)1E18;
const i64 INFFF = 1e16;

#define Max 20010

vector <pii> adj[Max];
int dis[Max];
priority_queue <pii, vector<pii>, greater<pii> > q;

int dijkstra(int src, int des) {
    memset(dis, 100, sizeof dis);
    q = priority_queue <pii, vector<pii>, greater<pii> > ();
    dis[src] = 0;
    q.push(pii(dis[src] , src ));
    int u, v, cost;
    while(!q.empty()) {
        u = q.top().second, q.pop();
        if(u == des) return dis[des];
        rep(i, (int)adj[u].size()) {
            v = adj[u][i].first;
            cost = adj[u][i].second;
            if(dis[v] > dis[u] + cost) {
                dis[v] = dis[u] + cost;
                q.push(pii(dis[v], v));
            }
        }
    }
    return -1;
}

int main() {
    READ("input.txt");
    int vertex, edge, u, v, cost, src, des, tcase, caseNo = 0;
    SDi(tcase);
    while(tcase--) {
        scanf("%d %d %d %d", &vertex, &edge, &src, &des);
        rep(i, edge) {
            scanf("%d %d %d", &u, &v, &cost);
            adj[u].pb(pii(v, cost));
            adj[v].pb(pii(u, cost));
        }
        int result = dijkstra(src, des);
        printf("Case #%d: ", ++caseNo);
        result == -1 ? printf("unreachable\n") : printf("%d\n", result);
        rep(i, vertex + 2) adj[i].clear();
    }
    return 0;
}
