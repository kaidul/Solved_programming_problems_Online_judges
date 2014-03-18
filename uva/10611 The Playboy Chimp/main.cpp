#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N, n, Q, q;
    set<int> s;
    scanf("%d", &N);
    while (N-- and (scanf("%d", &n) == 1))
        s.insert(n);

    scanf("%d", &Q);

    while (Q-- and (scanf("%d", &q) == 1)) {
        set<int>::iterator begin = s.begin(), chimp = s.find(q), taller = s.upper_bound(q), end = s.end(), beforeEnd = --end;

        if (q < *begin)
            printf("X %d\n", *(++begin));

        else if (*beforeEnd < q)
            printf("%d X\n", *beforeEnd);

        else if (*chimp == *begin)
            printf("X %d\n", *(++begin));

        else if (*chimp == *beforeEnd)
            printf("%d X\n", *beforeEnd);
        else {
            int u = *(taller--);
            int l = *(taller) == q ? *(--taller) : *(taller);
            printf("%d %d\n", l, u);
        }
    }
    return 0;
}
