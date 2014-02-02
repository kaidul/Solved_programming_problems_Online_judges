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

#define M 15

char grid[M][M];
int n;
int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};

char valid(int row, int col) {
    map <char, bool> letter;
    rep(i, 4) {
        int x = row + dirx[i], y = col + diry[i];
        if(grid[x][y] != '#')
            letter[grid[x][y]] = true;
    }
    FOR(i, 65, 90) {
        char c = (char) i;
        if(letter[c] == false) return c;
    }
    return 'A';
}

int main() {
    #ifndef ONLINE_JUDGE
        READ("input.txt");
    #endif
    int tcase, caseNo = 0;
    char ch;
    SDi(tcase);
    while(tcase--) {
        rep(i, M) rep(j, M) grid[i][j] = '#';
        SDi(n);
        getchar();
        FOR(i, 1, n) {
            FOR(j, 1, n)
                sf("%c", &ch), grid[i][j] = ch;
            getchar();
        }
        FOR(i, 1, n) {
            FOR(j, 1, n)
                if(grid[i][j] == '.')
                    grid[i][j] = valid(i, j);
        }
        pf("Case %d:\n", ++caseNo);
        FOR(i, 1, n) {
            FOR(j, 1, n)
                pf("%c", grid[i][j]);
            pf("\n");
        }
    }
    return 0;
}
