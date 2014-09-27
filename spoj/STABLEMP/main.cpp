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
#define output(x, y); pf("Case %d: %d", ++x, y)
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

class TimeTracker {
    clock_t start, end;
public:
    TimeTracker() {
        start = clock();
    }
    ~TimeTracker() {
        end = clock();
        fprintf(stderr, "%.3lf s\n", (double)(end - start) / CLOCKS_PER_SEC);
    }
};

string toString(int num) {
    ostringstream convert;
    convert << num;
    return convert.str();
}
struct Point {
    int x, y;
    Point(): x(0), y(0) {}
    Point(int a, int b): x(a), y(b) {}
    bool operator < (const Point& other) const {
        return x < other.x;
    }
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

#define MAX 505

int prefM[MAX][MAX], rankW[MAX][MAX], options[MAX], marriedTo[MAX];
queue <int> bachelor;
int N;

void stableMarriage() {
    memset(marriedTo, -1, sizeof marriedTo);

    int man, woman, husband;

    // while there is a free man m who still has a woman to propose to
    while(!bachelor.empty()) {
        man = bachelor.front();
        bachelor.pop();
        bool friendZoned = true;
        for(int j = options[man] - 1; j >= 0; --j) {
            // man's highest ranked such woman to whom he has not yet proposed
            woman = prefM[man][j];
            // man won't propose this woman again
            options[man]--;

            // if this woman is free
            if(marriedTo[woman] == -1) {
                // man and woman become engaged
                marriedTo[woman] = man;
                // man is no longer friend, so stop
                friendZoned = false;
                break;
            } else { // if woman is already engaged
                husband = marriedTo[woman];
                // if woman prefers man to husband (bitch)
                if(rankW[woman][man] > rankW[woman][husband]) {
                    // woman divorces her husband and man-woman get engaged
                    marriedTo[woman] = man;

                    // welcome to friendzone, you miserable bastard! :3)
                    bachelor.push(husband);

                    // man is no longer friend, so stop
                    friendZoned = false;
                    break;
                }
            }
        }
        // if man got his dick still dry, push the filth into frinedzone again
        if(friendZoned) bachelor.push(man);
    }
}

int main(void) {
#ifndef ONLINE_JUDGE
     READ("input.txt");
//     WRITE("out.txt");
#endif
    int tcase, caseNo = 0;
    SDi(tcase);
    int man;
    while(tcase--) {
        SDi(N);
        rep1(i, N) {
            SDi(i);
            rrep(j, N) {
                SDi(man);
                rankW[i][man] = j;
            }
        }
        rep1(i, N) {
            SDi(i);
            bachelor.push(i);
            options[i] = N;
            rrep(j, N) SDi(prefM[i][j]);
        }
        stableMarriage();
        rep1(i, N) printf("%d %d\n", marriedTo[i], i);
    }
    return EXIT_SUCCESS;
}
