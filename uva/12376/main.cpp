#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
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

/* Main Code */

#define Max 110
#define Range 5000

class Compare {
public:
    int operator() ( const pii& p1, const pii& p2 ) {
        return p1.second > p2.second;
    }
};
priority_queue <pii, vector<pii>, Compare> q;
vector <pii> adj[Range];
int dis[Max], cost[Max];

void reset() {
    q = priority_queue <pii, vector<pii>, Compare> ();
    rep(i, Max) dis[i] = -1;
}

pair <int, int> dijkstra(int src) {
    reset();
    int sum = 0, end = 0, max;
    dis[src] = 0;
    q.push(pii(src, dis[src]));
    while(!q.empty()) {
        int u = q.top().first;
        q.pop();
        max = -1;
        rep(i, (int)adj[u].size()) {
            int v = adj[u][i].first;
            int cost = adj[u][i].second;
            if(max < cost) max = cost, end = v;
        }
        if(max > 0) sum += max, q.push(pii(end, max));
    }
    return make_pair(sum, end);
}

int main() {
    READ("input.txt");
    int vertex, edge, u, v, src, des, tcase, caseNo = 1;
    SDi(tcase);
    while(tcase--) {
        SD2(vertex, edge);
        rep(i, vertex) SDi(cost[i]);
        rep(i, edge) {
            SD2(u, v);
            adj[u].pb(pii(v, cost[v]));
        }
        src = 0;
        pair <int, int> result = dijkstra(src);
        pf("Case %d: %d %d\n", caseNo, result.first, result.second);
        rep(i, vertex + 10) adj[i].clear();
        caseNo++;
    }

    return 0;
}
