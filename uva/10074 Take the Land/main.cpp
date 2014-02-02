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

int m, n, matrix[100][100];

int main() {
    freopen("input.txt","r",stdin);
    int k, item, l, max;
    while (scanf("%d %d", &m, &n), m || n) {
        max = 0;

        rep(i, m) {
            k = 0;
            rep(j, n) {
                SDi(matrix[i][j]);
                matrix[i][j] = matrix[i][j] == 0 ? k = k + 1 : k = 0;
                //printf("%d ",matrix[i][j]);
            }
            //printf("\n");
        }

        rep(i, m)
            rep(j, n)
                if (matrix[i][j]) {
                    item = matrix[i][j];
                    if (item > max) max = item;
                    for (k= i + 1, l = 2; k < m; k++, l++)
                        if (matrix[k][j]) {
                            if (item > matrix[k][j]) item = matrix[k][j];
                            if (item * l > max) max = item * l;
                        } else break;
                }
        println(max);
    }
    return 0;
}
