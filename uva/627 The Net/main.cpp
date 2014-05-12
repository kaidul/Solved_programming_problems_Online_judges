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

#define Max 305

queue <int> q;
vector <int> adj[Max], path;
bool visited[Max];
int dist[Max], parent[Max];

int main(void) {
#ifndef ONLINE_JUDGE
    READ("input.txt");
//     WRITE("out.txt");
#endif
    int tcase, caseNo = 0;
    int n, m, indx, arr[Max];
    int u, v, len, fact, src, dest;
    char input[Max * Max];
    while(~SDi(n)) {
        getc(stdin);
        rep(i, n) {
            gets(input);
            indx = 0;
            while(input[indx] != '-') {
                arr[indx] = input[indx] - '1' + 1;
                ++indx;
            }
            fact = 1, u = 0;
            rrep(j, indx) u += fact * arr[j], fact *= 10;
            ++indx;
            len = strlen(input);
            int idx = 0;
            FOR(j, indx, len - 1) {
                while(input[j] != ',' and j < len) {
                    arr[idx] = input[j] - '1' + 1;
                    ++j, ++idx;
                }
                fact = 1, v = 0;
                rrep(k, idx) v += fact * arr[k], fact *= 10;
                idx = 0;
                adj[u].pb(v);
            }
        }
        /*
        for ( int i = 1; i <= routers; i++ ) {
            char inp [1000]; gets (inp);
            char *pch;
            pch = strtok (inp, "-,");
            int id = atoi (pch);
            pch = strtok (NULL, "-,");

            while ( pch != NULL ) {
                int sees = atoi (pch);
                matrix [id].push_back (sees);
                pch = strtok (NULL, "-,");
            }
        }
        */
        SDi(m);
        printf ("-----\n");
        rep(i, m) {
            SD2(src, dest);
            rep(k, Max) parent[k] = k, dist[k] = INF, visited[k] = false;
            q = queue <int> ();
            q.push(src);
            dist[src] = 0;
            visited[src] = true;
            while(!q.empty()) {
                u = q.front(), q.pop();
                if(u == dest) break;
                rep(k, (int)adj[u].size()) {
                    v = adj[u][k];
                    if(visited[v]) continue;
                    visited[v] = true;
                    parent[v] = u;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
            path.pb(dest);
            int curr = dest;
            while(parent[curr] != curr) {
                curr = parent[curr];
                path.pb(curr);
            }
            reverse(all(path));
            if(dist[dest] == INF) {
                printf ("connection impossible\n");
            } else {
                pf("%d", path[0]);
                FOR(i, 1, path.size() - 1) printf (" %d", path[i]);
                newLine;
            }
            path.clear();
        }
        rep(i, Max) adj[i].clear();
    }
    return EXIT_SUCCESS;
}
