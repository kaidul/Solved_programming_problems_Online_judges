#include <bits/stdc++.h>

using namespace std;

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define rrep(i, n) for(__typeof(n) i = (n); i >= 0; --i)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define INF (1<<30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define memsp(x) mem(x,MEMSET_INF)
#define memdp(x) mem(x,-1)
#define memca(x) mem(x,0)
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
#define SDi(x) sf("%d", &x)
#define SDl(x) sf("%lld", &x)
#define SDs(x) sf("%s", x)
#define SD2(x,y) sf("%d%d", &x, &y)
#define SD3(x,y,z) sf("%d%d%d", &x, &y, &z)
#define pf printf
#define print(x) pf("%d ", x)
#define println(x) pf("%d\n", x)
#define sf scanf
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

//LCA using sparse table
//Complexity: O(NlgN,lgN)
#define Max 100002
int depth[Max]; // depth of every node from root. depth[i] denotes depth of node i
int table[Max][22]; // sparse table. there will be n rows for n nodes and logn columns for every node. pre-processing complexity O(nlogn) and Query complexity O(logn). table[i][j] holds 2^j th parent of ith node.
int parent[Max]; // parent of node. parent[x] = y denotes y is parent of x
vector <int> adj[Max]; // to store grpah
void dfs(int from, int u, int dep) {
    parent[u] = from;
    depth[u] = dep;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if(v == from) continue;
        dfs(u, v, dep + 1);
    }
}

void lca_init(int N) {
    mem(table, -1);
    rep(i, N) table[i][0] = parent[i];

    for (int j = 1; (1 << j) < N; j++)
        rep(i, N) if (table[i][j - 1] != -1) table[i][j] = table[table[i][j - 1]][j - 1];
}

int lca_query(int p, int q) {
    if (depth[p] < depth[q]) swap(p, q);

    // building log's value
    int log = 1;
    while(true) {
        int next = log + 1;
        if((1 << next) > depth[p]) break;
        log++;
    }

    // uplifting p at the same level of q
    rrep(i, log) if (depth[p] - (1 << i) >= depth[q]) p = table[p][i];

    if (p == q) return p;

    // uplifting p and q untill both of their parents are same and we're in root
    rrep(i, log) if (table[p][i] != -1 and table[p][i] != table[q][i]) p = table[p][i], q = table[q][i];

    // when p and q are in the same level, return one of their parent
    return parent[p];
}

int main(void) {
    adj[0].pb(1);
    adj[1].pb(2);
    adj[2].pb(3);
    adj[3].pb(4);
    adj[4].pb(5);
    adj[5].pb(6);
    adj[6].pb(7);
    adj[6].pb(14);
    adj[1].pb(8);
    adj[8].pb(9);
    adj[9].pb(10);
    adj[10].pb(11);
    adj[11].pb(12);
    adj[11].pb(15);
    adj[12].pb(13);
    adj[12].pb(16);

    dfs(0, 0, 0);
    lca_init(17);
    println( lca_query(14, 11) );

    return 0;
}
