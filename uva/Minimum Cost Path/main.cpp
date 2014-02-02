/**
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0)
http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/
 **/
#include <bits/stdc++.h>
#define _ ios_base:sync_with_stdio(0);cin.tie(0);
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
#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)
#define pf printf
#define print(x) pf("%d ", x)
#define println(x) pf("%d\n", x)
#define sf scanf
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

// cost of minimum cost path to reach (m, n) from (0, 0)

#define R 3
#define C 3

/* A utility function that returns minimum of 3 integers */
int min(int x, int y, int z) {
    if (x < y)
        return (x < z)? x : z;
    else
        return (y < z)? y : z;
}

int minCost(int cost[R][C], int m, int n) {
    int i, j;

    // Instead of following line, we can use int cache[m+1][n+1] or
    // dynamically allocate memoery to save space. The following line is
    // used to keep te program simple and make it working on all compilers.
    int cache[R][C];

    cache[0][0] = cost[0][0];

    /* Initialize first column of total cost(cache) array */
    for (i = 1; i <= m; i++)
        cache[i][0] = cache[i-1][0] + cost[i][0];

    /* Initialize first row of cache array */
    for (j = 1; j <= n; j++)
        cache[0][j] = cache[0][j-1] + cost[0][j];

    /* Construct rest of the cache array */
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            cache[i][j] = min(cache[i-1][j-1], cache[i-1][j], cache[i][j-1]) + cost[i][j];

    return cache[m][n];
}

/* Driver program to test above functions */
int main() {
    int cost[R][C] = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}
    };
    println(minCost(cost, 2, 2));
    return 0;
}
