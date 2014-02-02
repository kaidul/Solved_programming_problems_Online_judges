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
using namespace std;
#define INF 1<<30
#define Row 12
#define Col 102

typedef long long i64;

i64 grid[Row][Col];
i64 Parent[Row][Col];
bool flag[Row][Col];

i64 R, C;

i64 Recur(i64 r, i64 c) {
    i64 straight, up, down, x, y, z, indx;
    if(c == C - 1) return grid[r][c];
    if(flag[r][c]) return grid[r][c];

    up = (r - 1 + R) % R;
    straight = r;
    down = (r + 1) % R;

    x = Recur(up, c + 1);
    y = Recur(straight, c + 1);
    z = Recur(down, c + 1);

    indx = up;
    if(x > y || (x == y && indx > straight)) {
        x = y, indx = straight;
    }
    if(x > z || (x == z && indx > down)) {
        x = z, indx = down;
    }
    grid[r][c] += x;
    Parent[r][c] = indx;
    flag[r][c] = true;
    return grid[r][c];
}

void Print(i64 r, i64 c) {
    if(c == C - 1) {
        printf(" %lld", r + 1);
        return;
    }
    if(c != 0) printf(" ");
    printf("%lld", r + 1);

    Print(Parent[r][c], c + 1);
}

void minPath() {
    i64 min, d, minr;
    bool first = true;
    for(int i = 0; i < R; i++) {
        d = Recur(i, 0);
        if(first) {
            min = d, minr = i, first = false;
        } else if(d < min) {
            min = d, minr = i;
        }
    }
    if(C == 1) {
        printf("%d\n%lld\n", minr + 1, min);
        return;
    }
    Print(minr, 0);
    printf("\n%lld\n", min);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int i, j;

    while(scanf("%lld %lld", &R, &C) == 2) {
        for( i = 0; i < R; i++) {
            for(j = 0; j < C; j++)
                scanf("%lld", &grid[i][j]);
        }
        minPath();
        memset(flag, false, sizeof flag);
    }
    return 0;
}
