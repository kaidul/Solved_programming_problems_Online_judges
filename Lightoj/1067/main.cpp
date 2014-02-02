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
typedef long long i64;
typedef unsigned long long ui64;
/** function **/
#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)
#define pf printf
#define sf scanf
#define READ(f) freopen(f, "r", stdin)

#define Max 1000010
#define Mod 1000003

i64 bigmod(i64 b, i64 p, i64 m){
	i64 r=1;
	i64 pow = b % m;
	while (p > 0) {
        if (p % 2 == 1) r = (r * pow) % m;
        pow = (pow * pow) % m;
        p >>= 1;
    }
    return r;
}

i64 cache[Max];

i64 factorial(int n) {
    if(cache[n] != -1) return cache[n];
    if(n == 0 || n == 1) return cache[n] = 1;
    return cache[n] = (factorial(n - 1) % Mod * n % Mod) % Mod;
}

int main() {
    READ("in.txt");
    int tcase, caseNo = 1, n, r, save;
    i64 sum;
    mem(cache, -1);
    SDi(tcase);
    while(tcase--) {
        SD2(n, r);
        save = r, sum = 1;
        sum = ((factorial(n) % Mod)  * bigmod(factorial(r) * factorial(n - r), Mod - 2, Mod)) % Mod;
        pf("Case %d: %lld\n", caseNo, sum);
        caseNo++;
    }
    return 0;
}
