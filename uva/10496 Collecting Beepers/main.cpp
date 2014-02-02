#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#define min(a, b) (a < b)? a : b
#define INF 1 << 30

#define Max 10

using namespace std;
int n;
int maxV;
int dp[Max + 1][(1 << Max) + 1];
typedef struct p {
    int x, y;
} point;

int distance(point* a, point* b) {
    return abs(a -> x - b -> x) + abs(a -> y - b -> y);
}

point nodes[Max + 1];

bool Check(int N, int pos) {
    return (bool)(N & (1 << pos));
}

int Set(int N, int pos) {
    return N | (1 << pos);
}

int tsp(int current, int mask) {
    if(mask == maxV)
        return dp[current][mask] = distance(nodes + current, nodes);

    if(dp[current][mask] != -1)
        return dp[current][mask];

    int m = INF;
    for(int i = 1; i < n; i++)
        if( !Check(mask, i) )
            m = min( m, distance(nodes + current, nodes + i) + tsp(i, Set(mask, i) ));
    return dp[current][mask] = m;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int c, j, i;
    scanf("%d", &c);
    while(c--) {
        scanf("%d %d", &i, &i); // fao fao
        scanf("%d %d", &nodes[0].x, &nodes[0].y);
        scanf("%d", &n);
        n++; // because I put initial co-ordiate at (0, 0)
        for(i = 1; i < n; i++)
            scanf("%d %d", &nodes[i].x, &nodes[i].y);

        maxV = (1 << n) - 1;

        for(i = 0; i < n; i++)
            for(j = 0; j <= maxV; j++)
                dp[i][j] = -1;

        printf("The shortest path has length %d\n", tsp(0, 1) );
    }
    return 0;
}
