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
#include <bitset>
#include <utility>
#include <set>
#include <math.h>
#define pi acos(-1.0)
#define N 1000000
using namespace std;

int m, n;
char a [100 + 5] [100 + 5];
int dr1, dr2;
int dc1, dc2;
char ch;

bool isSquare () {
    if ( dr1 < 0 || dr2 == m || dc1 < 0 || dc2 == n )
        return false;

    // up
    for ( int i = dc1; i <= dc2; i++ )
        if ( a [dr1] [i] != ch ) return false;

    // right
    for ( int i = dr1; i <= dr2; i++ )
        if ( a [i] [dc2] != ch ) return false;

    // down
    for ( int i = dc1; i <= dc2; i++ )
        if ( a [dr2] [i] != ch ) return false;

    // left
    for ( int i = dr1; i <= dr2; i++ )
        if ( a [i] [dc1] != ch ) return false;

    return true;
}

int main () {
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        int q;
        scanf ("%d %d %d", &m, &n, &q);
        printf ("%d %d %d\n", m, n, q);

        for ( int i = 0; i < m; i++ )
            scanf ("%s", a [i]);

        for ( int i = 0; i < q; i++ ) {
            int r, c;
            scanf ("%d %d", &r, &c);

            int length = 0;
            ch = a [r] [c];
            dr1 = dr2 = r;
            dc1 = dc2 = c;

            while ( isSquare () ) {
                length++;

                dr1--;
                dc1--;

                dr2++;
                dc2++;
            }

            printf ("%d\n", length * 2 - 1);
        }
    }

    return 0;
}
