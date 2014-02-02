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

/**  Main Code **/

#define Max 1010

bool visited[Max][Max], end[Max];
i64 mat[Max][Max], dp[Max][Max];
i64 C, S, E, T;

#define INF64 1 << 60

/**
It's a modified travelling salesman problem : typical TSP problem describes - Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city EXACTLY ONCE and returns to the origin city?

solve (current_node, nodes_to_go) = max ( profit[current_node][new_node_1] + 'total profits after visiting from new_node_1 to destination' - solve (new_node_1, nodes_to_go - 1), profit[current_node][new_node_2] + 'total profits after visiting from new_node_2 to destination' - solve (new_node_2, nodes_to_go - 1) )

here, profit[current_node][new_node] = maximum profits can be achieved if visit from current_node to new_node
**/

i64 solve(i64 u, i64 n) {
    if(n == 0) return 0; // base case 1: when all intermediate nodes have been visited
    if(visited[u][n])
        return dp[u][n];
    visited[u][n] = true;
    i64 ans = INF64;
    if(n == 1) { // base case 2: when only 1 intermeiate node has to be visited
        for(int i = 0; i < C; i++)
            if(end[i])
                ans = max(ans, mat[u][i]);

        return dp[u][n] = ans;
    }
    for(int i = 0; i < C; i++) {
        ans = max(ans, mat[u][i] + solve(i, n - 1));
    }
    return dp[u][n] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    i64 in;
    while(sf("%lld%lld%lld%lld", &C, &S, &E, &T) != EOF and C and S and E and T) {
        rep(i, C) rep(j, C) SDl(mat[i][j]);
        mem(end, false);
        mem(visited, false);
        rep(i, E) {
            SDl(in);
            end[in - 1] = true;
        }
        pf("%lld\n", solve(S - 1, T));
    }
    return 0;
}
