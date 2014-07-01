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

#define MAX 110

vector< int > adj[MAX];
int low[MAX], disc[MAX], parent[MAX], dfstime, cnt = 0;
bool ap[MAX], visited[MAX];

void dfs(int u) {
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++dfstime;

    for(int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];

        if(!visited[v]) {
            ++children;
            parent[v] = u;
            dfs(v);
            low[u]  = min(low[u], low[v]);

            if (parent[u] == -1 and children > 1)
                ap[u] = true;

            if (parent[u] != -1 and low[v] >= disc[u])
                ap[u] = true;

        } else if(v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }

}

int main(void) {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int N, vertex;
    vector <int> v;
    char str[500];

    while(SDi(N) and N) {
        getchar();
        while(gets(str)) {
            stringstream ss(str);
            while(ss >> vertex) v.pb(vertex);
            int u = v[0];
            if(u == 0) break;
            for(int i = 1, n = (int)v.size(); i < n; ++i) {
                int V = v[i];
                adj[u].pb(V);
                adj[V].pb(u);
            }
            v.clear();
        }

        mem(ap, false);
        mem(visited, false);
        mem(parent, -1);
        dfstime = 0, cnt = 0;

        rep1(i, N) if(!visited[i]) dfs(i);

        rep1(i, N) if(ap[i]) ++cnt;

        println(cnt);

        v.clear();
        rep(i, MAX) adj[i].clear();
    }
    return 0;
}
