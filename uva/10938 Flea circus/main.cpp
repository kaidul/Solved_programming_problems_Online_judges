/****************************************************
 * Kaidul Islam, Eyeball Networks Inc.
 * topcoder: cohesion, codeforces: Kaidul, codechef: kaidul, hackerrank: kaidul, UVa: Kaidul
**********************************************************************************************/
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

#define MAX 5001
#define LOG_MAX 13
int depth[MAX];
int table[MAX][LOG_MAX];
int parent[MAX];
vector<int> adj[MAX];

void dfs(int from, int u, int d) {
    parent[u] = from;
    depth[u] = d;
    for(int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if(v == from) continue;
        dfs(u, v, d + 1);
    }
}

void lcaInit(int N) {
    memset(table, -1, sizeof table);
    for(int i = 0; i < N; ++i) {
        table[i][0] = parent[i];
    }
    for(int j = 1; (1 << j) < N; j++) {
        for(int i = 0; i < N; ++i) {
            if(table[i][j - 1] != -1) {
                table[i][j] = table[table[i][j - 1]][j - 1];
            }
        }
    }
}

void lcaQuery(int p, int q) {
    if(depth[p] < depth[q]) swap(p, q);
    int log = 1;
    while(true) {
        int next = log + 1;
        if((1 << next) > depth[q]) break;
        log++;
    }
    if(depth[p] == depth[q]) {
        if(p == q) {
            printf("The fleas meet at %d.\n", p);
            return;
        }
        for(int i = log; i >= 0; --i) {
            if(table[p][i] != -1 and table[p][i] != table[q][i]) {
                p = table[p][i], q = table[q][i];
            }
        }
        printf("The fleas meet at %d.\n", parent[p]);
    } else {
        for(int i = log; i >= 0; --i) {
            if(depth[q] - (1 << i) >= 0) {
                q = table[q][i], p = table[p][i];
            }
        }
        printf("The fleas jump forever between %d and %d.\n", q, p);
    }
}

int main(void) {
#ifndef ONLINE_JUDGE
     READ("in.txt");
//     WRITE("out.txt");
#endif
    int tcase, caseNo = 0;
    int n;
    int a, b;
    while(SDi(n)) {
        if(n == 0) break;
        for(int i = 0; i < n - 1; ++i) {
            SD2(a, b);
            adj[a].pb(b);
        }
        dfs(1, 1, 0);
        lcaInit(n + 1);
        int p, q, m;
        SDi(m);
        for(int i = 0; i < m; ++i) {
            SD2(p, q);
            lcaQuery(p, q);
        }
    }
    return EXIT_SUCCESS;
}
