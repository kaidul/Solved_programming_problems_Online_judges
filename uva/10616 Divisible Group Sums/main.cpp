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
#define SDi(x) sf("%lld",&x)
#define SD2(x,y) sf("%lld %lld",&x,&y)
#define pf printf
#define print(x) pf("%d ", x)
#define println(x) pf("%d\n", x)
#define sf scanf
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

/** Main Code **/

#define Max 210
#define Query_N 16
#define MOD 25

i64 N, Q, D, M, data[Max], cache[Max][Query_N][MOD];
bool visited[Max][Query_N][MOD];

i64 knapsack(i64 indx, i64 taken, i64 sumModD) {
    if(taken == M) {
        if(sumModD == 0) return 1;
        return 0;
    }
    if(indx == N) return 0;
    if(visited[indx][taken][sumModD])
        return cache[indx][taken][sumModD];

    visited[indx][taken][sumModD] = true;
    return cache[indx][taken][sumModD] = knapsack( indx + 1, taken + 1, (((sumModD + data[indx]) % D) + D) % D ) + knapsack( indx + 1, taken, sumModD );
}

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int caseNo = 0, queryNo;
    while(SD2(N, Q) != EOF) {
        if(!N && !Q) break;
        rep(i, N) SDi(data[i]);


        pf("SET %d:\n", ++caseNo);
        queryNo = 0;
        rep(i, Q) {
            SD2(D, M);
            mem(visited, false);
            pf("QUERY %d: %lld\n", ++queryNo, knapsack(0, 0, 0));
        }
    }
    return 0;
}
