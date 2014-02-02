#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define min(a, b) (a < b)? a : b
#define INF 1 << 30
using namespace std;

#define Max 20

int k;
int maxV;
int dp[Max + 1][(1 << Max) + 1];
typedef struct p {
    int x, y;
} point;

int distance(point* a, point* b) {
    /**
        key line: They can travel in all 8 adjacent directions in one step.
        that means they can travel diagonally
    **/
    return max ( abs(a -> x - b -> x), abs(a -> y - b -> y) );
    //return abs(a -> x - b -> x) + abs(a -> y - b -> y);
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

    int ans = INF;
    for(int i = 1; i < k; i++)
        if( !Check(mask, i) )
            ans = min( ans, distance(nodes + current, nodes + i) + tsp(i, Set(mask, i) ));
    return dp[current][mask] = ans;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int row, col;
    char input[Max + 1] [Max + 1];
    while (scanf("%d %d", &row, &col) == 2) {
        getchar();
        k = 0;
        for (int i = 0; i < row; i++) {
            gets(input[i]);
            for (int j = 0; j < col; j++) {
            	if(input[i][j] == 'L') {
                    nodes[0].x = i;
                    nodes[0].y = j;
            	} else if(input[i][j] == '#') {
                    nodes[++k].x = i;
                    nodes[k].y = j;
            	}
            }
        }
        ++k;
        maxV = (1 << k) - 1;

        for(int i = 0; i < k; i++)
            for(int j = 0; j <= maxV; j++)
                dp[i][j] = -1;

        printf("%d\n", tsp(0, 1) );
    }
    return 0;
}
