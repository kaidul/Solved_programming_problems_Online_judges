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
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;

char a [4 + 3] [4 + 3];
int f [4 + 3] [4 + 3];
int n;

int bktk (int rook) {
    int ret = rook;
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            if ( f [i] [j] == 0 ) {
                for ( int k = j; k >= 0 && a [i] [k] != 'X'; k-- ) // < current row
                    f [i][k]++;
                for ( int k = j + 1; k < n && a [i] [k] != 'X'; k++ ) // current row >
                    f [i][k]++;
                for ( int k = i - 1; k >= 0 && a [k] [j] != 'X'; k-- ) // current col ^
                    f [k][j]++;
                for ( int k = i + 1; k < n && a [k] [j] != 'X'; k++ ) // current col
                    f [k][j]++;

                int val = bktk (rook + 1);
                if ( val > ret ) ret = val;

                for ( int k = j; k >= 0 && a [i] [k] != 'X'; k-- ) // < current row
                    f [i] [k]--;
                for ( int k = j + 1; k < n && a [i] [k] != 'X'; k++ ) // current row >
                    f [i] [k]--;
                for ( int k = i - 1; k >= 0 && a [k] [j] != 'X'; k-- ) // current col ^
                    f [k] [j]--;
                for ( int k = i + 1; k < n && a [k] [j] != 'X'; k++ ) // current col
                    f [k] [j]--;

            }
        }
    }
    return ret;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    while ( scanf ("%d", &n) && n ) {

        for ( int i = 0; i < n; i++ ) scanf ("%s", a [i]);

        memset (f, 0, sizeof (f));

        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ )
                if ( a [i] [j] == 'X' ) f[i][j] = N;
        }

        printf ("%d\n", bktk (0));
    }

    return 0;
}
