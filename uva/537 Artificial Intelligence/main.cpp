/*Notes :
1. print a blank line after each testCase.
even after the last testCase.

2. I = P / U
if U == 0 then I == 0
similarly, U = P / I
if I == 0 then U == 0

3. there might be no space/s between two infos. Like,
U=200VP=100W

4. Sample input :
3
I=-1e-2A and U=2e3V
xx xx x I=0.0000000000000001MA yy yy U=1000000000000000.0000000mV zz
U=200VI=4.5A.
*/
#include <stdio.h>
#include <string.h>

char var [2 + 3] [50];

double adjust (char a) {
    if ( a == 'm' ) return 0.001;
    if ( a == 'k' ) return 1000;
    if ( a == 'M' ) return 1000000;
    return 1;
}

void upi () {
    double u = -1, p = -1, i = -1;
    char c1, c2;
    char mkM;

    for ( int j = 0; j < 2; j++ ) {
        if ( var [j] [0] == 'P' ) {
            sscanf (var [j], "%c%c%lf%c", &c1, &c2, &p, &mkM);
            p *= adjust (mkM);
        }

        if ( var [j] [0] == 'U' ) {
            sscanf (var [j], "%c%c%lf%c", &c1, &c2, &u, &mkM);
            u *= adjust (mkM);
        }

        if ( var [j] [0] == 'I' ) {
            sscanf (var [j], "%c%c%lf%c", &c1, &c2, &i, &mkM);
            i *= adjust (mkM);
        }
    }

    // these are for avoiding infinite result
    if ( u == 0 ) {
        p = 0;
        u = 1;
    }
    if ( i == 0 ) {
        p = 0;
        i = 1;
    }

    if ( i == -1 ) printf ("I=%.2lfA\n", p / u);
    if ( u == -1 ) printf ("U=%.2lfV\n", p / i);
    if ( p == -1 ) printf ("P=%.2lfW\n", u * i);
}

int main (void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int testCase;
    scanf ("%d", &testCase);
    getchar ();
    int cases = 0;

    while ( testCase-- ) {

        char input [5000];
        gets (input);

        char *p;
        int index = 0;

        p = strtok (input, " AVW");

        while ( p != NULL ) {
            if ( strchr (p, '=') )
                strcpy (var [index++], p);
            //printf ("%s\n", p);
            p = strtok (NULL, " ");

        }
        //for (int i = 0; i < index; i++) printf("%s ", var[i]);
        //putchar('\n');
        printf ("Problem #%d\n", ++cases);
        upi ();
        printf ("\n");
    }

    return 0;
}
