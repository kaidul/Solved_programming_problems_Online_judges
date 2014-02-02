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
#include <climits>
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

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define RFOR(i,a,b) for(__typeof(b) i=(a); i>(b); i--)
#define RESET(t,value) memset((t), value, sizeof(t))

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define PI acos(-1.0)
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define G struct Graph

typedef long long int64;
typedef unsigned long long ui64;
typedef long double d64;

#define Max 1001

int dp[Max << 2][2];
int parent[Max];
vector <int> adj[Max];

int min_vertex_cover(int node, bool hasFireExit) {

    if( adj[node].size() == 0 ) return 0;
    if( dp[node][hasFireExit] != -1 ) return dp[node][hasFireExit];

    int sum = 0;
    REP( i, (int)adj[node].size() ) {
        int v = adj[node][i];
        if( v != parent[node] ) {
            parent[v] = node;
            if( !hasFireExit ) sum += min_vertex_cover(v, true);
            else sum += min( min_vertex_cover(v, false), min_vertex_cover(v, true) );
        }
    }
    return dp[node][hasFireExit] = sum + hasFireExit;
}

void _reset() {
    RESET(dp, -1);
    RESET(parent, 0);
}

int main() {
    READ("input.txt");
    int n, adj_no, vertex;
    int result;
    while(cin >> n && n) {
        _reset();

        FOR(i, 1, n) {
            cin >> adj_no;
            REP(j, adj_no) {
                cin >> vertex;
                adj[i].pb(vertex);
            }
        }

        result = 0;
        result = min( min_vertex_cover(1, false), min_vertex_cover(1, true) );
        if(n > 1) printf("%d\n", result);
        else printf("1\n");
        REP(i, n + 10) adj[i].clear();
    }
    return 0;
}
