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

#define M 31
#define Max 1001
int n, t, w, d[M], v[M], cache[M][Max];
bool visited[M][Max], taken[M][Max], mark[M];

int knapsack(int indx, int sec) {
    if(indx == n) return 0;
    if(visited[indx][sec])
        return cache[indx][sec];
    int ret1 = 0, ret2 = 0, time;
    time = 3 * d[indx] * w;
    if(sec + time <= t)
        ret1 = v[indx] + knapsack(indx + 1, sec + time);
    ret2 = knapsack(indx + 1, sec);
    taken[indx][sec] = (ret1 > ret2);
    return cache[indx][sec] = max(ret1, ret2);
}

int main() {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    bool first = true;
    while(SD2(t, w) != EOF) {
        if(!first) pf("\n");
        first = false;
        mem(visited, false);
        mem(taken, false);
        mem(mark, false);

        SDi(n);
        rep(i, n) SD2(d[i], v[i]);
        println(knapsack(0, 0));

        int count = 0, i = 0, j = 0;
        while(i < n) {
            if(taken[i][j]) {
                mark[i] = true, count++;
                j += 3 * w * d[i];
            }
            i++;
        }

        pf("%d\n", count);
        rep(i, n)
            if(mark[i])
                pf("%d %d\n", d[i], v[i]);
    }
    return 0;
}
