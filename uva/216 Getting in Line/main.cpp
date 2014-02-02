/* Ac code
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
#define pi acos(-1.0)
#define N 1000000
using namespace std;


int main () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    int cases = 0;

    while ( scanf ("%d", &n) && n ) {
        int permute [8] = {0, 1, 2, 3, 4, 5, 6, 7};
        int x [10];
        int y [10];
        int dummyX [10];
        int dummyY [10];

        for ( int i = 0; i < n; i++ ) {
            scanf ("%d %d", &x [i], &y [i]);
            dummyX [i] = x [i];
            dummyY [i] = y [i];
        }

        double minDistance = INT_MAX;
        int dummy [8];

        do {
            double calculateDistance = 0;

            for ( int i = 0; i < n; i++ ) {
                x [i] = dummyX [permute [i]];
                y [i] = dummyY [permute [i]];
            }

            for ( int i = 1; i < n; i++ ) {
                calculateDistance += sqrt ((x [i - 1] - x [i]) * (x [i - 1] - x [i]) + (y [i - 1] - y [i]) * (y [i - 1] - y [i]) );
            }

            if ( calculateDistance < minDistance ) {
                minDistance = calculateDistance;
                for ( int i = 0; i < n; i++ )
                    dummy [i] = permute [i];
            }
        } while ( next_permutation (permute, permute + n) );

        for ( int i = 0; i < n; i++ ) {
            x [i] = dummyX [dummy [i]];
            y [i] = dummyY [dummy [i]];
        }

        // print output
        printf ("**********************************************************\n");
        printf ("Network #%d\n", ++cases);
        double total = 0;
        for ( int i = 1; i < n; i++ ) {
            double d = sqrt ((x [i - 1] - x [i]) * (x [i - 1] - x [i]) + (y [i - 1] - y [i]) * (y [i - 1] - y [i]) );
            d += 16;
            printf ("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x [i - 1], y [i - 1], x [i], y [i], d);
            total += d;
        }
        printf ("Number of feet of cable required is %.2lf.\n", total);
    }


    return 0;
}
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<limits.h>
using namespace std;
#define Max 8
int n;

float dp[Max + 1][ (1 << Max) + 1];
pair <int, float> trace[Max + 1][(1 << Max) + 1];
pair <int, int> points[25];
int maxN;

bool Check(int N, int pos) {
    return (bool)(N & (1 << pos));
}

int Set(int N, int pos) {
    return N | (1 << pos);
}

float tsp(int node, int  mask) {
    if(mask == maxN)
        return (float) 0.0;

    if(dp[node][mask] != -1)
        return (float) dp[node][mask];

        float ans = INT_MAX, weight, ret;
        int v = 0;
        float cost;
        for(int i = 0; i < n; i++)
            if(!Check(mask, i)) {
                ret = tsp(i, Set(mask, i) );
                weight = sqrt( pow( (float) abs(points[node].first -  points[i].first), 2) +
                               pow( (float) abs(points[node].second -  points[i].second), 2)
                             );
                if(ans > ret + weight ) {
                    ans = ret + weight;
                    v = i;
                    cost = weight;
                }

            }

        trace[node][mask] = make_pair (v, cost + 16.00);

        return dp[node][mask] = ans;

}


int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int caseNo = 0;
    while(scanf("%d", &n) && n) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < (1 << n ); j++)
                dp[i][j] = -1;
        maxN = (1 << n) - 1;
        for(int i = 0; i < n; i++)
            scanf("%d %d", &points[i].first, &points[i].second);

        int mask = 0, origin = 0;
        float result = INT_MAX, ret;
        for(int i = 0; i < n; i++) {
            ret = tsp(i, (1 << i) );
            if(ret < result) {
                result = ret;
                origin = i;
            }
        }
        mask |= ( 1 << origin );
        int u = origin, v;
        float cost;
        printf("**********************************************************\n");
        printf("Network #%d\n", ++caseNo);
        for (int i = 0; i < n - 1; i++) {
            v = trace[u][mask].first;
            cost = trace[u][mask].second;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", points[u].first, points[u].second, points[v].first, points[v].second, cost);
            mask |= ( 1 << v);
            u = v;
        }
        printf("Number of feet of cable required is %.2lf.\n", result + ((n - 1) * 16.00) );

    }


    return 0;
}
