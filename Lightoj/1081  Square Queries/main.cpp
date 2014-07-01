/****************************************************
 * Author      : Kaidul Islam
 * University  : Khulna University of Engr. and Tech.
*****************************************************/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(__typeof(n) i = 0; i < (n); i++)
#define rrep(i, n) for(__typeof(n) i = (n) - 1; i >= 0; --i)
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
#define MAX5 100000
#define MAX7 10000000
#define MAX9 1000000000
#define MOD7 (MAX7 + 7)
#define MOD9 (MAX9 + 9)
typedef long long i64;
typedef unsigned long long ui64;
const i64 INF64 = (i64)1E18;

string toString(int num) {
    ostringstream convert;
    convert << num;
    return convert.str();
}

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

#define MAX 505
int grid[MAX][MAX];

struct Point {
    int x, y, Max;
    Point(): x(0), y(0), Max(-INF) {}
    Point(int a, int b, int c): x(a), y(b), Max(c) {}
    bool operator < (const Point& other) const {
        return Max < other.Max;
    }
};

struct SegmentTree2D {
    Point T[2 * MAX * MAX];
    int row, col;

    void init(int dimen) {
        this->row = dimen;
        this->col = dimen;
        build(1, 1, 1, row, col);
    }

    Point build(int node, int a1, int b1, int a2, int b2) {
        if (a1 > a2 or b1 > b2)
            return Point();

        if (a1 == a2 and b1 == b2)
            return T[node] = Point(a1, b1, grid[a1][b1]);

        T[node] = Point();
        T[node] = maxNode(T[node], build(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 ) );
        T[node] = maxNode(T[node], build(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 ));
        T[node] = maxNode(T[node], build(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2) );
        T[node] = maxNode(T[node], build(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2) );
        return T[node];
    }

    Point query(int node, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2) {
        if (x1 > a2 or y1 > b2 or x2 < a1 or y2 < b1 or a1 > a2 or b1 > b2)
            return Point();

        if (x1 <= a1 and y1 <= b1 and a2 <= x2 and b2 <= y2)
            return T[node];

        Point ret = Point();
        ret = maxNode(ret, query(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1, y1, x2, y2) );
        ret = maxNode(ret, query(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2) );
        ret = maxNode(ret, query(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x1, y1, x2, y2) );
        ret = maxNode(ret, query(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2));

        return ret;
    }

    Point query(int x1, int y1, int x2, int y2) {
        return query(1, 1, 1, row, col, x1, y1, x2, y2);
    }

    Point maxNode(Point a, Point b) {
        return max(a, b);
    }
};

SegmentTree2D obj;


int main(void) {
#ifndef ONLINE_JUDGE
     READ("input.txt");
//     WRITE("out.txt");
#endif
    int tcase, caseNo = 0;
    int N, Q, I, J, S;
    SDi(tcase);
    while(tcase--) {
        SD2(N, Q);
        rep1(i, N) rep1(j, N) SDi(grid[i][j]);
        obj.init(N);
        pf("Case %d:\n", ++caseNo);
        rep(i, Q) {
            SD3(I, J, S);
            println(obj.query(I, J, I + S - 1, J + S - 1).Max);
        }
    }
    return EXIT_SUCCESS;
}
