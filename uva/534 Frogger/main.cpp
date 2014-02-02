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
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;

/**
Suppose, Source = A
Destination = Z
there are 3 paths to reach from A to Z
path 1 : A → B → C → Z
path 2 : A → E → Z
path 3 : A → Z
distances are follows,
A → B = 5
B → C = 5
C → Z = 5

A → E = 6
E → Z = 8

A → Z = 20

distance wise,
path 1 : 5 → 5 → 5
path 2 : 6 → 8
path 3 : 20

which path should u take ? 1, 2 or 3 ?
minimum distance = 6 + 8 = 14 → path 2

U r asked to find shortest jump distance
that is, if u take path : 2 then minimum jump distance is 6
if u take path : 1 then minimum jump distance is 5
though path 1 is not the shortest distance to reach from A to Z but it contains minimum jump distance

Use any shortest distance algorithm and modify it according to minimax distance

I have used floyd warshall. Count all the distances between the stones and store it in array D

then run floyd warshall and update the distance as follows,
d [i] [j] = min (d [i] [j], max (d [i] [k], d [k] [j]));
**/

double power (int b, int p) {
    double ret = 1;

    for ( int i = 1; i <= p; i++ )
        ret *= b;

    return ret;
}

int main () {
    int stones;
    int cases = 0;

    while ( scanf ("%d", &stones) && stones ) {
        int x [200 + 10];
        int y [200 + 10];

        for ( int i = 0; i < stones; i++ )
            scanf ("%d %d", &x [i], &y [i]);

        double distance [200 + 10] [200 + 10];

        for ( int i = 0; i < stones; i++ ) {
            for ( int j = i + 1; j < stones; j++ )
                distance [i] [j] = distance [j] [i] = sqrt (power (x [i] - x [j], 2) + power (y [i] - y [j], 2));
        }

        // floyd warshall minimax algorithm
        for ( int k = 0; k < stones; k++ ) {
            for ( int i = 0; i < stones; i++ ) {
                for ( int j = 0; j < stones; j++ )
                    // distance [i] [j] = min (distance [i] [j], max (distance [i] [k] + distance [k] [j]));
                    distance [i] [j] = min (distance [i] [j], max (distance [i] [k], distance [k] [j]));
            }
        }

        printf ("Scenario #%d\n", ++cases);
        printf ("Frog Distance = %.3lf\n\n", distance [0] [1]);

    }

    return 0;
}
