#include <cstdio>
#include <vector>

using namespace std;

#define rep(i, n) for(__typeof(n) i = 0; i < (n); i++)
#define rrep(i, n) for(__typeof(n) i = (n); i >= 0; --i)
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

// Time Complexity: O(log^2 n)
#define root 0
#define N 10100
#define LogN 14 // log(N)
#define segTreeSize 32768 // 2 * pow(2.0, floor(log((double) N ) / log(2.0)) + 1

vector <int> adj[N], costs[N], indexx[N];
int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], table[N][LogN], otherEnd[N], subTreeSize[N];
int segment_tree[segTreeSize];

void buildSegTree(int node = 1, int start = 0, int end = ptr - 1) {
    if (start == end) {
        segment_tree[node] = baseArray[start];
        return;
    }
    int leftIndx = node << 1, rightIndx = leftIndx | 1, middle = (start + end) >> 1;

    buildSegTree(leftIndx, start, middle);
    buildSegTree(rightIndx, middle + 1, end);

    segment_tree[node] = ( segment_tree[leftIndx] > segment_tree[rightIndx] ) ? segment_tree[leftIndx] : segment_tree[rightIndx];
}

void update(int node, int start, int end, int index, int value ) {

    if( index < start or index > end) return;

    if(start == end and start == index) {
        segment_tree[node] = value;
        return;
    }
    int leftIndx = node << 1, rightIndx = leftIndx | 1, mid = (start + end) >> 1;

    update(leftIndx, start, mid, index, value );
    update(rightIndx, mid + 1, end, index, value );

    segment_tree[node] = ( segment_tree[leftIndx] > segment_tree[rightIndx] ) ? segment_tree[leftIndx] : segment_tree[rightIndx];
}

int querySegTree(int node, int start, int end, int i, int j) {
    if (start > j or end < i) return -1;

    if (start >= i and end <= j) return segment_tree[node];

    int leftIndx = node << 1, rightIndx = leftIndx | 1, mid = (start + end) >> 1;
    int val1 = querySegTree(leftIndx, start, mid, i, j);
    int val2 = querySegTree(rightIndx, mid + 1, end, i, j);

    if(val1 == -1) return val2;
    if(val2 == -1) return val1;

    return (val1 > val2) ? val1 : val2;
}

/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */

int query_up(int u, int v) {
    if(u == v) return 0; // Trivial
    int uchain, vchain = chainInd[v], ans = -1, ret;
    // uchain and vchain are chain numbers of u and v
    while(true) {
        uchain = chainInd[u];
        if(uchain == vchain) {
            // Both u and v are in the same chain, so we need to query from u to v, update answer and break.
            // We break because we came from u up till v, we are done
            if(u == v) break;
            ret = querySegTree(1, 0, ptr - 1, posInBase[v] + 1, posInBase[u]);
            // Above is call to segment tree query function
            ans = max(ans, ret); // Update answer
            break;
        }
        ret = querySegTree(1, 0, ptr - 1, posInBase[chainHead[uchain]], posInBase[u]);
        // Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
        // start till head. We then update the answer
        ans = max(ans, ret);
        u = chainHead[uchain]; // move u to u's chainHead
        u = table[u][0]; //Then move to its parent, that means we changed chains
    }
    return ans;
}

int LCA(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    int log = 1;
    while(true) {
        int next = log + 1;
        if((1 << next) > depth[u]) break;
        log++;
    }
    rrep(i, log) if(depth[u] - (1 << i) >= depth[v]) u = table[u][i];
    if(u == v) return u;
    rrep(i, log) if(table[u][i] != -1 and table[u][i] != table[v][i]) {
        u = table[u][i];
        v = table[v][i];
    }
    return table[u][0];
}

void query(int u, int v) {
    int lca = LCA(u, v);
    int ans = max(query_up(v, lca), query_up(u, lca));
    println(ans);
}

void change(int i, int val) {
    int u = otherEnd[i];
    update(1, 0, ptr - 1, posInBase[u], val);
}

void HLD(int curNode = root, int cost = -1, int prev = -1) {
    if(chainHead[chainNo] == -1) { // Given a chain, what is the head of the chain
        chainHead[chainNo] = curNode; // Assign chain head
    }
    chainInd[curNode] = chainNo; // Given a node, to which chain does that node belong to
    //chainPos[cur] = chainSize[chainNo]; // Given a node, what is the position of that node in its chain
    //chainSize[chainNo]++; // Given a chain, what is the length of the chain
    posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
    baseArray[ptr++] = cost;

    int sc = -1, ncost;
    // Loop to find special child
    for(int i = 0, n = (int)adj[curNode].size(); i < n; i++) {
        int v = adj[curNode][i];
        if(v != prev) {
            if(sc == -1 or subTreeSize[sc] < subTreeSize[v]) {
                sc = v, ncost = costs[curNode][i];
            }
        }
    }

    if(sc != -1) { // Incase of curNode is leaf node
        // Expand the chain
        HLD(sc, ncost, curNode);
    }

    for(int i = 0, n = adj[curNode].size(); i < n; i++) {
        int v = adj[curNode][i];
        if(v != prev and v != sc) {
            // New chains at each normal node
            chainNo++;
            HLD(v, costs[curNode][i], curNode);
        }
    }
}

void dfs(int cur = root, int prev = -1, int _depth = 0) {
    table[cur][0] = prev;
    depth[cur] = _depth;
    subTreeSize[cur] = 1;
    for(int i = 0, n = adj[cur].size(); i < n; i++) {
        int v = adj[cur][i];
        if(v != prev) {
            otherEnd[indexx[cur][i]] = v;
            dfs(v, cur, _depth + 1);
            subTreeSize[cur] += subTreeSize[v];
        }
    }
}

void initLCA(int n) {
    for(int j = 1; (1 << j) < n; j++)
        rep(i, n) if(table[i][j - 1] != -1)
            table[i][j] = table[table[i][j - 1]][j - 1];
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int tcase;
    SDi(tcase);
    while(tcase--) {
        ptr = 0;
        int n;
        SDi(n);
        // Cleaning step, new test case
        rep(i, n) {
            adj[i].clear();
            costs[i].clear();
            indexx[i].clear();
            chainHead[i] = -1;
            rep(j, LogN) table[i][j] = -1;
        }
        rep(i, n - 1) {
            int u, v, cost;
            SD3(u, v, cost);
            u--, v--;
            adj[u].pb(v);
            adj[v].pb(u);

            costs[u].pb(cost);
            costs[v].pb(cost);

            indexx[u].pb(i);
            indexx[v].pb(i);
        }

        chainNo = 0;
        dfs(); // We set up subTreeSize, depth and parent for each node
        HLD(); // We decomposed the tree and created baseArray

        buildSegTree(); // We use baseArray and construct the needed segment tree

        initLCA(n);

        while(true) {
            char s[100];
            SDs(s);
            if(s[0] == 'D') break;
            int a, b;
            SD2(a, b);
            if(s[0] == 'Q') {
                query(a - 1, b - 1);
            } else {
                change(a - 1, b);
            }
        }
    }
    return 0;
}
