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
#include <utility>
#include <set>
#include <math.h>
#define pi acos(-1.0)
#define N 1000000
using namespace std;

int n;
int a [20];
bool available [20];
int isPrime [42] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0,
                    1, 0, 1, 0, 0, 0, 1, 0, 1, 0,
                    0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
                    1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                    1
                   };

bool valid (int indx, int ring) {
    if ( ring == n - 1 ) {
        if (isPrime [a [ring - 1] + indx] && isPrime [indx + 1])
            return true;
        return false;
    }
    return isPrime [a [ring - 1] + indx];
}

void bktk (int ring) {
    if ( ring == n ) {
        printf ("%d", a [0]);
        for ( int i = 1; i < n; i++ )
            printf (" %d", a [i]);
        printf ("\n");
        return;
    }

    for ( int i = 2; i <= n; i++ ) {
        if ( available [i] ) {
            if ( valid (i, ring) ) {
                available [i] = false;
                a [ring] = i;
                bktk (ring + 1);
                available [i] = true;
            }
        }
    }
}

int main () {
    int cases = 0;
    freopen("input.txt", "r", stdin);
    while ( scanf ("%d", &n) != EOF ) {
        a [0] = 1;
        if(cases > 0) printf ("\n");
        printf ("Case %d:\n", ++cases);
        memset (available, true, sizeof (available));

        bktk (1);
    }

    return 0;
}
