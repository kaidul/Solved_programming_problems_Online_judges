/****************************************************
***   Problem       :
***   Author        : Kaidul Islam
***   E-mail        : ikaidul@yahoo.com
***   Blog          : http://kaidul.efireit.com
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
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
#define SDi(x) sf("%d", &x)
#define SDl(x) sf("%lld", &x)
#define SDs(x) sf("%s", x)
#define SD2(x,y) sf("%d%d", &x, &y)
#define SD3(x,y,z) sf("%d%d%d", &x, &y, &z)
#define pf printf
#define print(x) pf("%d ", x)
#define println(x) pf("%d\n", x)
#define sf scanf
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

const i64 INF64 = (i64)1E18;

/** BitMask **/
int Set(int N, int pos) {
    return N = N | (1 << pos);
}
int Reset(int N,int pos) {
    return N = N & ~(1 << pos);
}
int Check(int N, int pos) {
    return (N & (1 << pos));
}
int toggle(int N, int pos) {
    if( Check(N, pos) )
        return N = Reset(N, pos);
    return N = Set(N, pos);
}

const i64 INFFF = 1e16;

//int dx[] = {0, -1, 0, 1};
//int dy[] = {-1, 0, 1, 0};
//int Dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
//int Dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int row, col;
bool isValid(int i, int j) {
    return i >= 0 and j >= 0 and i < row and j < col;
}

/* TLE Code

int main(void) {
    int tcase, caseNo = 0;
#ifndef ONLINE_JUDGE
     READ("input.txt");
    // WRITE("output.txt");
#endif
    int N, q;
    int code, pos, debug = 0;
    bool R, C;
    SDi(N);
    int mat[N + 1][N + 1];
    int rows[N + 1];
    int cols[N + 1];
    mem(rows, 0);
    mem(cols, 0);
    rep(i, N) rep(j, N) SDi(mat[i][j]);
    SDi(q);
    while(q--) {
        SDi(code);
        if(code == 1) {
            SDi(pos);
            R = true;
            ++rows[--pos];
        } else if(code == 2) {
            SDi(pos);
            C = true;
            ++cols[--pos];
        } else {
            ++debug;
            if(R) {
                rep(i, N) {
                    if(rows[i] > 0 and rows[i] & 1) {
                        rep(j, N) mat[i][j] ^= 1;
                        rows[i] = 0;
                    }
                }
                R = false;
            }
            if(C) {
                rep(i, N) {
                    if(cols[i] > 0 and cols[i] & 1) {
                        rep(j, N) mat[j][i] ^= 1;
                        cols[i] = 0;
                    }
                }
                C = false;
            }
            int ans, sum = 0;
            rep(i, N) {
                ans = 0;
                rep(j, N) ans += (mat[i][j] & mat[j][i]);
                ans %= 2;
                sum += ans;
            }
            sum %= 2;
            pf("%d", sum);
        }
    }
    return 0;
}
*/
int main() {
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int t;
            scanf("%d",&t);
            if(i==j) {
                ans+=t;
            }
        }
    }

    int q;
    scanf("%d",&q);
    for(int i=0; i<q; i++) {
        int t1;
        scanf("%d",&t1);
        if(t1==3) printf("%d",ans%2);
        else {
            int t2;
            scanf("%d",&t2);
            ans++;
        }
    }
}
