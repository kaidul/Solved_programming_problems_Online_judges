/****************************************************
 * Author      : Kaidul Islam
 * University  : Khulna University of Engr. and Tech.
*****************************************************/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(__typeof(n) i = 0; i < (n); i++)
#define rep1(i, n) for(__typeof(n) i = 1; i <= (n); i++)
#define FOR(i, a, b) for(__typeof(b) i = (a); i <= (b); i++)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define INF (1 << 30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define mem(x, y) memset(x, y, sizeof x)
#define eps 1e-9
#define pii pair<int, int>
#define couple make_pair
#define X first
#define Y second
#define vi vector<int>
#define vpii vector< pii >
#define si set<int>
#define SDi(x) sf("%d", &x)
#define SD2(x, y) sf("%d %d", &x, &y)
#define SD3(x, y, z) sf("%d %d %d", &x, &y, &z)
#define SDs(x) sf("%s", x)
#define pf printf
#define print(x) pf("%d ", x)
#define println(x) pf("%d\n", x)
#define newLine pf("\n")
#define sf scanf
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#if ( _WIN32 or __WIN32__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define SDl(x) sf(LLD, &x)
#define MAX6 1000000
#define MAX7 10000000
#define MAX9 1000000000
#define MOD7 (MAX7 + 7)
#define MOD9 (MAX9 + 9)
typedef long long i64;
typedef unsigned long long ui64;
const i64 INF64 = (i64)1E18;

// BitMask
int Set(int N, int pos) {
    return N = N | (1 << pos);
}
int Reset(int N, int pos) {
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

// direction array
//int dx[] = {0, -1, 0, 1};
//int dy[] = {-1, 0, 1, 0};
//int Dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
//int Dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
//int row, col;
//bool isValid(int i, int j) {
//    return i >= 0 and j >= 0 and i < row and j < col;
//}

/** Implementation **/

#define LOG 16
#define NMAX 260000
#define BMAX 509

inline int bit(int value, int idx) {
    return (value >> idx) & 1;
}

struct trie {
    vector<int> nx[2], cnt;
    int xored;

    trie() {
        xored = 0;
    }

    void rebuild() {
        xored = 0;
        cnt.assign(1, 0);
        nx[0].assign(1, -1);
        nx[1].assign(1, -1);
        assert(cnt.size() == 1 and nx[0][0] == -1);
    }

    void add(int num) {
        int v = 0;
        rep(i, LOG) {
            int c = bit(num, LOG - i - 1);
            int nv = nx[c][v];
            if(nv == -1) {
                nv = cnt.size();
                cnt.pb(0), nx[0].pb(-1), nx[1].pb(-1);
                nx[c][v] = nv;
            }
            v = nx[c][v];
        }
        cnt[v]++;
    }

    pii getmin() {
        if(cnt.size() == 1)
            return couple(INF, 0);
        int ans = 0, v = 0;
        rep(i, LOG) {
            rep(b, 2) {
                if(nx[b ^ bit(xored, LOG - i - 1)][v] != -1) {
                    ans |= b << (LOG - i - 1);
                    v = nx[b ^ bit(xored, LOG - i - 1)][v];
                    break;
                }
            }
        }
        assert(cnt[v] > 0);
        return couple(ans, cnt[v]);
    }
} t[NMAX / BMAX];

int a[NMAX], add[NMAX / BMAX], n, q;

inline void relax(int id) {
    if(add[id]) {
        FOR(i, BMAX * id, min(n, BMAX * (id + 1)) - 1)
        a[i] ^= add[id];
        add[id] = 0;
    }
}

void build(int id) {
    t[id].rebuild();
    add[id] = 0;

    FOR(i, BMAX * id, min(n, BMAX * (id + 1)) - 1) {
        t[id].add(a[i]);
    }
}

void update(pii& self, const pii& other) {
    if(other.X <= self.X) {
        if(other.X < self.X)
            self.X = other.X, self.Y = 0;
        self.Y += other.Y;
    }
}

int main(void) {
#ifndef ONLINE_JUDGE
    READ("input.txt");
    // WRITE("output.txt");
#endif

    SD2(n, q);
    rep(i, n) SDi(a[i]);

    for(int l = 0, i = 0; l < n; l += BMAX, i++)
        build(i);

    int q1 = 0, q2 = 0;
    while(q--) {
        int type;
        SDi(type);
        if(type == 1) {
            q1++;
            int l, r;
            SD2(l, r);
            l--, r--;

            relax(l / BMAX);
            relax(r / BMAX);

            pii e(INF, 0);
            for(int pos = l; pos <= r;) {
                if(pos % BMAX == 0 and pos + BMAX - 1 <= r) {
                    pii cur = t[pos / BMAX].getmin();
                    update(e, cur);
                    pos += BMAX;
                } else {
                    update(e, couple(a[pos], 1));
                    pos++;
                }
            }

            print(e.X);
            println(e.Y);
        } else {
            q2++;
            int l, r, k;
            SD3(l, r, k);
            l--, r--;

            relax(l / BMAX);
            relax(r / BMAX);

            for(int pos = l; pos <= r;) {
                if(pos % BMAX == 0 and pos + BMAX - 1 <= r) {
                    int id = pos / BMAX;
                    t[id].xored ^= k;
                    add[id] ^= k;
                    pos += BMAX;
                } else {
                    a[pos] ^= k;
                    pos++;
                }
            }

            relax(l / BMAX);
            relax(r / BMAX);

            build(l / BMAX);
            if(l / BMAX != r / BMAX)
                build(r / BMAX);
        }
    }
    return EXIT_SUCCESS;
}
