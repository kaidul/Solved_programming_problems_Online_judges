/****************************************************
 * Author      : Kaidul Islam
 * University  : Khulna University of Engr. and Tech.
*****************************************************/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(__typeof(n) i = 0; i < (n); i++)
#define rrep(i, n) for(__typeof(n) i = (n) - 1; i >= 0; --i)
#define repl(i, n) for(__typeof(n) i = 1; i <= (n); i++)
#define FOR(i, a, b) for(__typeof(b) i = (a); i <= (b); i++)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define INF (1 << 30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define mem(x, y) memset(x, y, sizeof x)
#define eps 1e-9
#define pii pair<int, int>
#define couple make_pair
#define X first
#define Y second
#define vi vector<int>
#define vpii vector< pii >
#define si set<int>
#define SDi(x) sf("%d", &x)
#define SD2(x, y) sf("%d %d", &x, &y)
#define SD3(x, y, z) sf("%d %d %d", &x, &y, &z)
#define SDs(x) sf("%s", x)
#define pf printf
#define print(x) pf("%d ", x)
#define println(x) pf("%d\n", x)
#define newLine pf("\n")
#define sf scanf
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#if ( _WIN32 or __WIN32__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define SDl(x) sf(LLD, &x)
#define MAX5 100000
#define MAX7 10000000
#define MAX9 1000000000
#define MOD7 (MAX7 + 7)
#define MOD9 (MAX9 + 9)
typedef long long i64;
typedef unsigned long long ui64;
const i64 INF64 = (i64)1E18;

string toString(int num) {
    ostringstream convert;
    convert << num;
    return convert.str();
}
struct point {
    int x, y;
    point(int a, int b): x(a), y(b) {}
};
// BitMask
int Set(int N, int pos) {
    return N = N | (1 << pos);
}
int Reset(int N, int pos) {
    return N = N & ~(1 << pos);
}
int Check(int N, int pos) {
    return (N & (1 << pos));
}
int toggle(int N, int pos) {
    if( Check(N, pos) )
        return N = Reset(N, pos);
    return N = Set(N, pos);
}

// direction array
//int dx[] = {0, -1, 0, 1};
//int dy[] = {-1, 0, 1, 0};
//int Dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
//int Dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
//int row, col;
//bool isValid(int i, int j) {
//    return i >= 0 and j >= 0 and i < row and j < col;
//}

/** Implementation **/

#define Max 105

int N;
int src, dest;
vector<int> adj[Max];
bool visited[Max];
stack <int> Stack;
int dist[Max];

void topologicalSortUtil(int u) {
    visited[u] = true;
    rep(i, (int)adj[u].size()) {
        int v = adj[u][i];
        if (!visited[v]) topologicalSortUtil(v);
    }
    Stack.push(u);
}

int longestPath() {
    mem(visited, false);
//    rep(i, Max) dist[i] = -INF;
    fill_n(dist, Max, -INF);
//    fill(dist, dist + Max, -INF);
    dist[src] = 0;
    repl(i, N) if(!visited[i]) topologicalSortUtil(i);
    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();
        if (dist[u] != -INF) {
            rep(i, (int)adj[u].size()) {
                int v = adj[u][i];
                if (dist[u] + 1 > dist[v])
                    dist[v] = dist[u] + 1;
            }
        }
    }
    int ret = -1;
    repl(i, N) if(dist[i] > ret) ret = dist[i], dest = i;
    return ret;
}

int main(void) {
#ifndef ONLINE_JUDGE
     READ("in.txt");
//     WRITE("out.txt");
#endif
    int tcase, caseNo = 0;
    int p, q;
    while(~SDi(N)) {
        if(!N) break;
        SDi(src);
        while(SD2(p, q)) {
            if(!p and !q) break;
            adj[p].pb(q);
        }
        int ans = longestPath();
        pf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++caseNo, src,ans, dest);
        rep(i, Max) adj[i].clear();
    }
    return 0;
}

/* DP approach. still WA
#define M 105

int dp[M], dir[M], n;
vector <int> adj[M];

int longest(int u) {
    if(dp[u] != -1) return dp[u];
    int maxi = 0, path, v;
    rep(i, adj[u].size()) {
        v = adj[u][i], path = longest(v);
        if(path >= maxi) {
            if(path > maxi)
                maxi = path, dir[u] = v;
            if(path == maxi)
                if(v < dir[u])
                    maxi = path, dir[u] = v;
        }
    }
    dp[u] = 1 + maxi;
    return dp[u];
}

int main() {
#ifndef ONLINE_JUDGE
    READ("in.txt");
#endif
    int u, v, start, caseNo = 0, save, end, longPath;
    while(SDi(n)) {
        if(!n) break;
        SDi(start);
        while(SD2(u, v)) {
            if(!u and !v) break;
            adj[u].pb(v);
        }
        fill_n(dp, M, -1), fill_n(dir, M, -1);
        longPath = longest(start) - 1;
        save = start;
        while(dir[start] != -1) {
            start = dir[start];
        }
        end = start, start = save;
        pf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++caseNo, start, longPath, end);
        rep(i, M) adj[i].clear();
    }
    return 0;
}
*/
