
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>

#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define LL long long
#define Set(a, s) memset(a, s, sizeof (a))
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)

using namespace std;

int mat [1024 + 3] [1024 + 3];

int main () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int testCases;
    scanf ("%d", &testCases);

    while ( testCases-- ) {

        Set(mat, 0);

        int d;
        scanf ("%d", &d);
        int n;
        scanf ("%d", &n);

        int x, y, cost;

        for ( int i = 0; i < n; i++ ) {
            scanf ("%d %d %d", &x, &y, &cost);

            for ( int j = max (0, x - d); j <= min (x + d, 1024); j++)
                for ( int k = max (0, y - d); k <= min (y + d, 1024); k++)
                    mat [j] [k] += cost;
        }

        int resX, resY, maxi = -1;

        for ( int i = 0; i < 1025; i++ ) {
            for ( int j = 0; j < 1025; j++ ) {
                if ( maxi < mat [i] [j] ) {
                    maxi = mat [i] [j];
                    resX = i;
                    resY = j;
                }
            }
        }

        printf ("%d %d %d\n", resX, resY, maxi);

    }
    return 0;
}
