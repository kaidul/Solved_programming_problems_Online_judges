#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

struct sprinkler {
    double left;
    double right;
} sprinklers[10000];

int n, l, w;

int cmp(struct sprinkler *a, struct sprinkler *b) {
    return a->left - b->left;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    while(scanf("%d %d %d", &n, &l, &w) == 3) {
        double r, x;
        int m = 0;
        for(int i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &r);
            double d = r * r - 0.25 * w * w;
            if (d <= 0) continue;
            d = sqrt(d);
            sprinklers[m].left = x - d;
            sprinklers[m].right = x + d;
            m++;
        }
        // ascending order of left
        qsort( sprinklers, m, sizeof(sprinklers[0]), (int(*)(const void*, const void*)) cmp );
        double nowLeft = 0;
        double nowRight = 0;
        int count = 1;
        for(int i = 0; i < m; i++) {
            if(sprinklers[i].left <= nowLeft) {
                nowRight = max(nowRight, sprinklers[i].right);
            } else {
                if(nowRight < sprinklers[i].left)
                    break;
                nowLeft = nowRight;
                count++;
                i--;
            }
        }
        if( nowRight >= l)
            printf("%d\n", count);
        else
            printf("-1\n");
    }
    return 0;
}
