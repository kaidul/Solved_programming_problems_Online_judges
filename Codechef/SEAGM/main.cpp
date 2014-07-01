#include <iostream>
#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int i, n, j, fw, ai, ms[100 + 5], it, a[100 + 5], m, sz[100 + 5], tn, g, t;
bool mem[100 + 5][2], rt[100 + 5][2];
double f[100 + 5][100 + 5], ret;

bool winner (int t, int pl) { // the game can be stated as the current GCD and the index of the player that take a turn now
    if (mem[t][pl]) return rt[t][pl];
    mem[t][pl] = true;
    bool fl = false;
    for(int i = 1; i <= n; i++)
        if (__gcd(t, a[i]) > 1 and __gcd(t, a[i]) != t) { // trying to make a new GCD and not to lose the game
            fl = true;
            if (!winner(__gcd(t, a[i]), 1 - pl)) return rt[t][pl] = true;
        }
    if (fl) return rt[t][pl] = false; // losing case
    return rt[t][pl] = sz[t] % 2 == pl;
}

int main (int argc, char * const argv[]) {
    scanf("%d", &tn);
    assert(1 <= tn and tn <= 10);
    while (tn--) {
        scanf("%d", &n);
        assert(1 <= n and n <= 100);
        for(i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            assert(1 <= a[i] and a[i] <= 100);
        }
        g = a[1];
        for(i = 2; i <= n; i++) g = __gcd(g, a[i]);
        // the degenerate case
        // if the GCD is not equal to one, the game will end only if there are no more cards
        if (g != 1) {
            printf("%d %d.0000\n", n % 2, n % 2);
            continue;
        }
        for(i = 0; i <= 100; i++) sz[i] = mem[i][0] = mem[i][1] = rt[i][0] = rt[i][1] = 0;
        for(i = 0; i <= 100; i++)
            for(j = 1; j <= n; j++) if (__gcd(i, a[j]) == i) ++sz[i]; // size of the maximal subset that has GCD with i equal to i
        if (winner(0, 1)) printf("1 ");
        else printf("0 "); // the first subproblem

        for(i = 0; i <= n; i++) for(j = 0; j <= 100; j++) f[i][j] = 0.0;
        // now, the second part of a problem
        // let's have dp f[i][j] with a meaning: we've taken i numbers, and their GCD is equal to j
        // what is the probability that the game still goes on
        // having that calculated we can get the answer easily
        f[0][0] = 1.0;
        ret = 0;
        for(i = 0; i < n; i++) for(j = 0; j <= 100; j++)
            if (f[i][j] > 1e-8) {
                    if (i < sz[j]) f[i + 1][j] += f[i][j] * 1.0 * (sz[j] - i) / (n - i); // a variant when we can append a number and not to change the GCD
                    for(t = 1; t <= n; t++) { // trying to append a numer that will change the GCD
                        g = __gcd(a[t], j); // the new GCD
                        if (g == 1 and i % 2) ret += f[i][j] * (1.0 / (n - i)); // if this is the end, we can consider this probability
                        if (g != j and g > 1) f[i + 1][g] += f[i][j] * (1.0 / (n - i)); // if this is not the end, we've just obtained the state with the new GCD
                    }
            }
        printf("%.4lf\n", ret);
    }
    return 0;
}
