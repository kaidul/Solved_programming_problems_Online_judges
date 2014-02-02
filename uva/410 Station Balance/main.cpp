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

int main() {
    #ifndef ONLINE_JUDGE
        READ("input.txt");
    #endif
    int S, C, val, sum, total, set = 0;
    vector <int> chamber[12], specimen;
    double imbalance, AM;
    while(SD2(C, S) == 2) {
        sum = 0;
        rep(i, S) {
            SDi(val);
            specimen.pb(val);
            sum += val;
        }
        FOR(i, specimen.size(), 2 * C - 1) specimen.pb(0);
        //rep(i, 2 * C) print(specimen[i]);
        AM = (double)sum / (double)C;
        //pf("%f\n", AM);
        sort(all(specimen));
        //rep(i, 2 * C) print(specimen[i]);
        for(int i = 0, j = 2 * C - 1; i < j; i++, j--) {
            chamber[i].pb(specimen[i]);
            chamber[i].pb(specimen[j]);
        }
        imbalance = 0;
        rep(i, C) {
            total = 0;
            rep(j, chamber[i].size()) {
                total += chamber[i][j];
            }
            //print(total);
            imbalance += abs(total - AM);
        }
        pf("Set #%d\n", ++set);
        rep(i, C) {
            pf(" %d:", i);
            rep(j, chamber[i].size()) {
                if(chamber[i][j] != 0) pf(" %d", chamber[i][j]);
            }
            pf("\n");
        }
        pf("IMBALANCE = %.5f\n\n", imbalance);
        //clear
        rep(i, C + 2) chamber[i].clear();
        specimen.clear();
    }
    return 0;
}
