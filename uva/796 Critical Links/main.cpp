/****************************************************
 * Author      : Kaidul Islam
 * University  : Khulna University of Engr. and Tech.
*****************************************************/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(__typeof(n) i = 0; i < (n); i++)
#define rrep(i, n) for(__typeof(n) i = (n) - 1; i >= 0; --i)
#define rep1(i, n) for(__typeof(n) i = 1; i <= (n); i++)
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
struct Point {
    int x, y;
    Point() {}
    Point(int a, int b): x(a), y(b) {}
    bool operator < (const Point &other) const {
        return x < other.x;
    }
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

#define MAX 250

vector< int > adj[MAX];

//  low[u] be the earliest discovery time of any vertex in the subtree rooted at u or connected to a vertex in that subtree by a back edge.
int low[MAX], disc[MAX], parent[MAX], dfstime;
bool visited[MAX];
bool edge[MAX][MAX];
int cnt = 0;

void dfs(int u) {
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++dfstime;

    // If some child v of u has low[v] >= disc_time[u], then u is an articulation point.
    // low[u] = min( {low[v] | v is a child of u} and {disc_time[x] | (u, x) is a back edge from u or any child-vertex of it} )

    for(int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];

        if(!visited[v]) {
            ++children;
            parent[v] = u;
            dfs(v);
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // If the lowest vertex reachable from subtree under v is
            // below u in DFS tree, then u-v is a bridge
            if (low[v] > disc[u]) ++cnt, edge[u][v] = edge[v][u] = true;

        } else if(v != parent[u]) // Update low value of u for parent function calls.
            low[u]  = min(low[u], disc[v]);
    }

}

int main(void) {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int N;
    int u, v, n;
    while(~SDi(N)) {
        rep(i, N) {
            scanf("%d (%d)", &u, &n);
            rep(j, n) {
                SDi(v);
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        mem(visited, false);
        mem(parent, -1);
        rep(i, MAX) rep(j, MAX) edge[i][j] = false;
        dfstime = 0, cnt = 0;
        rep(i, N) if(!visited[i]) dfs(i);
        pf("%d critical links\n", cnt);
        rep(i, N) FOR(j, i + 1, N - 1) if(edge[i][j]) pf("%d - %d\n", i, j);
        puts("");
        rep(i, MAX) adj[i].clear();
        result.clear();
    }
    return 0;
}
