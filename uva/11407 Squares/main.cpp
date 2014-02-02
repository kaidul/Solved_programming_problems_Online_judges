#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;
/**
This is a fairly simple DP problem. A greedy solution looks plausible, but isn't correct.

Build the solutions for each number from 1 to 10,000 in sequence. We know that a[1] is 1, so use that as a base case. For each new number, i, find the following minimum:

Min across all s of (a[i-s] + 1)

...where s is some square (1, 4, 9, 16, etc.)
**/

#define Max 10000

int dp[Max + 10];
vector <int> square;

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1, n = sqrt(Max) + 10; i < n; i++) {
        square.push_back( pow(i, 2) );
    }
    for (int i = 2; i <= Max; i++) {
        int ans = INT_MAX, j = 0;
        while (square[j] <= i) {
            ans = min( ans, dp[i - square[j] ] + 1 );
            ++j;
        }
        dp[i] = ans;
    }
    int tcase, N;
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d", &N);
        printf("%d\n", dp[N]);
    }
    return 0;
}
