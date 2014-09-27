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
#define output(x, y); pf("Case %d: %d", ++x, y)
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

class TimeTracker {
    clock_t start, end;
public:
    TimeTracker() {
        start = clock();
    }
    ~TimeTracker() {
        end = clock();
        fprintf(stderr, "%.3lf s\n", (double)(end - start) / CLOCKS_PER_SEC);
    }
};

string toString(int num) {
    ostringstream convert;
    convert << num;
    return convert.str();
}
struct Point {
    int x, y;
    Point(): x(0), y(0) {}
    Point(int a, int b): x(a), y(b) {}
    bool operator < (const Point& other) const {
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

#define MAX 105

int src, dest, f;
vector <int> adj[MAX];
int par[MAX], flow[MAX][MAX];
bool visited[MAX];

void augmentingPath(int v, int minEdge) {
    if(v == src) {
        f = minEdge;
        return;
    } else if(visited[v]) {
        augmentingPath(par[v], min(minEdge, flow[par[v]][v]));
        flow[par[v]][v] -= f;
        flow[v][par[v]] += f;
    }
}

int maxFLow() {
    int max_flow = 0;
    mem(par, 0);
    while(true) {
        mem(visited, false);
        queue <int> Q;
        Q.push(src);
        f = 0, visited[src] = true;
        while(!Q.empty()) {
            int v, u = Q.front(); Q.pop();
            if(u == dest) break;
            for(int i = 0, n = (int)adj[u].size(); i < n; ++i) {
                v = adj[u][i];
                if(!visited[v] and flow[u][v] > 0) {
                    visited[v] = true;
                    par[v] = u;
                    Q.push(v);
                }
            }
        }
        augmentingPath(dest, INF);
        if(f == 0) break;
        max_flow += f;
    }
    return max_flow;
}

int main(void) {
#ifndef ONLINE_JUDGE
     READ("in.txt");
//     WRITE("out.txt");
#endif
    int caseNo = 0, m, n;
    int u, v, bandWidth;
    while(~SDi(n)) {
        if(!n) break;
        SD3(src, dest, m);
        --src, --dest;
        rep(i, m) {
            SD3(u, v, bandWidth);
            --u, --v;
            adj[u].pb(v);
            adj[v].pb(u);
            flow[u][v] += bandWidth;
            flow[v][u] += bandWidth;
        }
        pf("Network %d\nThe bandwidth is %d.\n\n", ++caseNo, maxFLow());
        FOR(i, 0, n) adj[i].clear();
        memset(&flow[0][0], 0, sizeof flow);
    }
    return EXIT_SUCCESS;
}
