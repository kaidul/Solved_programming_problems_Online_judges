#include <bits/stdc++.h>

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
using namespace std;

int Z, I, M;

/*
Time Complexity: O(mu + lambda)
Space: O(1)
mu is the smallest index i and lambda(the loop length) is the smallest positive integer such that x(mu) = x(mu + lambda).
*/

pair<int, int> floyd_cycle_finding(int (*f)(int), int x0) {
    // the main phase of the algorithm, finding a repetation x(i) = x(2i). hare's speed is 2 * tortoise's
    int tortoise = f(x0), hare = f(f(x0));
    while( tortoise != hare ) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    // find the position of mu, the hare and tortoise move at the same speed
    int mu = 0;
    hare = tortoise;
    tortoise = x0;
    while( tortoise != hare ) {
        tortoise = f(tortoise);
        hare = f(hare);
        ++mu;
    }

    // find the length of the shortest cycle starting from x(mu), hare moves, tortoise stays
    int lambda = 1;
    hare = f(tortoise);

    while( tortoise != hare ) {
        hare = f(hare);
        ++lambda;
    }

    return make_pair(mu, lambda);
}

int f(int x) {
    return (( Z * x + I ) % M);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int L, caseNo = 0;
    while(scanf("%d %d %d %d", &Z, &I, &M, &L)) {
        if(!Z and !I and !L and !M) break;
        pair<int, int> ans = floyd_cycle_finding(&f, L);
        printf("Case %d: %d\n", ++caseNo, ans.second);
    }
    return 0;
}
