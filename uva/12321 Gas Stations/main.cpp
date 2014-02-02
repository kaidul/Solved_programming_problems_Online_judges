#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

struct station {
    int left, right;
} stations[10000];

int l, g;

int cmp(struct station *a, struct station *b) {
    return a->left - b->left;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int r, x;
    while(scanf("%d %d", &l, &g) == 2) {
        if(l == 0 && g == 0) break;
        for(int i = 0; i < g; i++) {
            scanf("%d %d", &x, &r);
            stations[i].left = x - r;
            stations[i].right = x + r;
        }
        qsort( stations, g, sizeof(stations[0]), (int(*)(const void*, const void*)) cmp );
        int nowLeft = 0, nowRight = 0, count = 1;
        for(int i = 0; i < g; i++) {
            if(nowRight >= l) break;
            if(stations[i].left <= nowLeft) {
                nowRight = max(nowRight, stations[i].right);
            } else {
                if(nowRight < stations[i].left)
                    break;
                nowLeft = nowRight;
                count++;
                i--;
            }
        }
        if( nowRight >= l)
            printf("%d\n", g - count);
        else
            printf("-1\n");
    }
    return 0;
}
