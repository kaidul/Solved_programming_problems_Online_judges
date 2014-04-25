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
struct Point {
    int x, y;
    Point() {}
    Point(int a, int b): x(a), y(b) {}
};
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

Point line[2];
Point sides[4][2];

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) and q.x >= min(p.x, r.x) and
            q.y <= max(p.y, r.y) and q.y >= min(p.y, r.y))
        return true;
    return false;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;

    return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 and o3 != o4) return true;
    if (o1 == 0 and onSegment(p1, p2, q1)) return true;
    if (o2 == 0 and onSegment(p1, q2, q1)) return true;
    if (o3 == 0 and onSegment(p2, p1, q2)) return true;
    if (o4 == 0 and onSegment(p2, q1, q2)) return true;
    return false;
}

int main(void) {
#ifndef ONLINE_JUDGE
     READ("input.txt");
//     WRITE("out.txt");
#endif
    int tcase, caseNo = 0;
    int xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
    SDi(tcase);
    while(tcase--) {
        SD3(xstart, ystart, xend); SD3(yend, xleft, ytop); SD2(xright, ybottom);
        line[0] = Point(xstart, ystart);
        line[1] = Point(xend, yend);

        if(xleft > xright) swap(xleft, xright);
        if(ybottom > ytop) swap(ybottom, ytop);

        sides[0][0] = Point(xleft, ytop);
        sides[0][1] = Point(xleft, ybottom);

        sides[1][0] = Point(xleft, ybottom);
        sides[1][1] = Point(xright, ybottom);

        sides[2][0] = Point(xright, ybottom);
        sides[2][1] = Point(xright, ytop);

        sides[3][0] = Point(xleft, ytop);
        sides[3][1] = Point(xright, ytop);

        bool yes = false;
        rep(i, 4) if( doIntersect(line[0], line[1], sides[i][0], sides[i][1]) ) {
            yes = true;
            break;
        }
        // check if the line is completely inside the rectangle and doesn't intersect
        if(xstart >= xleft and xstart <= xright and xend >= xleft and xend <= xright and ystart >= ybottom and ystart <= ytop and yend >= ybottom and yend <= ytop) yes = true;

        if(yes) pf("T\n");
        else pf("F\n");
    }
    return EXIT_SUCCESS;
}
