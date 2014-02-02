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

#define M 105
#define MAX 50005

int dp[M][MAX], m, total, amount[M], half;
bool visited[M][MAX];

int diff(int i, int sofar) {
    if(i == m) {
        if(total %2 == 0) return 2 * (half - sofar);
        return 2 * (half - sofar) + 1;
    }
    if(visited[i][sofar]) return dp[i][sofar];
    int diffByTaken = INT_MAX, diffBySkip = INT_MAX;
    if(half - (sofar + amount[i]) >= 0)
     diffByTaken = diff(i + 1, sofar + amount[i]);
    diffBySkip = diff(i + 1, sofar);
    visited[i][sofar] = true;
    return dp[i][sofar] = min(diffByTaken, diffBySkip);
}

int main() {
    #ifndef ONLINE_JUDGE
        READ("input.txt");
    #endif
    int tcase;
    total = 0;
    SDi(tcase);
    while(tcase--) {
        total = 0;
        SDi(m);
        rep(i, m)
            SDi(amount[i]), total += amount[i];
        mem(visited, false);
        half = floor(total / 2);
        println(diff(0, 0));
    }
    return 0;
}
