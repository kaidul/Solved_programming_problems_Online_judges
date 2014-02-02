#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#define maxn 1110
#define eps 1e-6
using namespace std;

struct problemSet {
    int a, b;
} problem[30];
int N;
bool cmp(problemSet x, problemSet y) {
    // from where this fuckin sorting logic come?
    return x.a + max(x.b, y.a) + y.b < y.a + max(y.b, x.a) + x.b;
}

int main() {
    freopen("input.txt","r",stdin);
    while( ~scanf("%d",&N) ) {
        for(int i = 0; i < N; i++) {
            scanf("%d", &problem[i].a);
        }
        for(int i = 0; i < N; i++) {
            scanf("%d", &problem[i].b);
        }

        sort(problem, problem + N, cmp);

        int ans = 0;
        int t1, t2;
        t1 = 0;
        t2 = problem[0].a;

        for(int i = 0; i < N; i++) {
            t1 += problem[i].a;
            t2 = max(t1, t2);
            t2 += problem[i].b;
        }

        printf("%d\n", t2);
    }
    return 0;
}
