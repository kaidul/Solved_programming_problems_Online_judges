#include <stdio.h>

/**
The problem here is asking us to calculate the minimum,maximum time it would take all ants to fall off from the stick, lets focus on the maximum time first:

    1. That maximum time would be the maximum time that would take the last ant to fall from the stick.
       So how do we make this time maximum if we had one ant at position x, simply the time would be max(x, L - x) where L is the length of the stick.

    2. What makes the problem harder is the collision, so lets focus on what happens when 2 ants collide

        Assume we have 2 ants A, B in those directions —A—><—B— and they collided at point z, what happens that
        * before collision B should walk distance z, A should walk distance L-z
        * after collision A should walk distance z, B should walk distance L-z
        * so they just exchanged roles here, i.e before collision we were going to    wait max(z, L - z) for both ants to fall (if they didn't collide and just shook hands) after collision we're also going to wait max(z, L - z), so collision doesn't change the result.
**/

int max(int a, int b) {
    return a > b? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tc, i, n, c, l, h, m;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d",&c, &n);
        l = h = 0;
        while(n--) {
            scanf("%d", &i);
            l = max(l, min(c - i, i));
            h = max(h, max(c - i, i));
        }
        printf("%d %d\n", l, h);
    }
    return 0;
}
