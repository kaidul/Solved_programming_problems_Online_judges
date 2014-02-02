#include <iostream>
#include <cstdio>
#include <cstring>

#define Max 10000

using namespace std;

/**
Analysis :
array burgers [i] = highest number of burgers Homer can have in time ‘i’
surely, burgers [m] = burgers [n] = 1

if ( burgers [k] > 0 ) then
    burgers [k + m] = burgers [k] + 1;

at last, if ( burgers [t] > 0 ) then
    print burgers [t]
otherwise, find the last possible time, k ( k < t ) such that, burgers [k] > 0
**/

int main () {
    int m, n, t;

    while ( scanf ("%d %d %d", &m, &n, &t) != EOF ) {
        int burgers [Max + 10];
        memset (burgers, 0, sizeof (burgers));

        if ( m > n ) swap (m, n);

        burgers [m] = 1;
        burgers [n] = 1;

        for ( int i = m; i <= t; i++ ) {
            if ( burgers [i] ) {
                if ( i + m <= t )
                    burgers [i + m] = max ( burgers [i + m], burgers [i] + 1);
                if ( i + n <= t )
                    burgers [i + n] = max ( burgers [i + n], burgers [i] + 1);
            }
        }

        if ( burgers [t] > 0 ) printf ("%d\n", burgers [t]);
        else {
            bool printed = false;
            for ( int i = t - 1; i >= 0; i-- ) {
                if ( burgers [i] > 0 ) {
                    printf ("%d %d\n", burgers [i], t - i);
                    printed = true;
                    break;
                }
            }

            if ( !printed ) printf ("0 %d\n", t);
        }
    }

    return 0;
}
