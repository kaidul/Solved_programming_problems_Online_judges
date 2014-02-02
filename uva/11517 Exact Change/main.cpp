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
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)

#define N 10000
using namespace std;

/**
 * Use Dynamic Programming to determine whether there is a way to make a value V from the n bills.
 * Let dp[X] be the number of bills/coins needed to make a value of X or lowest possible greater than X.
 * To fill in this DP table, first set dp[0] = 0 and set the rest to INFINITY.
 * For each bill with value C, update dp[v + C] = min( dp[v + C], dp[v] + 1) for all value v where dp[v] is not INFINITY.
 * The answer is X and dp[X], where X >= Bill and dp[X] is not INFINITY and X is possibly minimum. To find such X, a simple iteration will do.
**/

int main () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        int bill;
        scanf ("%d", &bill);

        int coinNumber;
        scanf ("%d", &coinNumber);

        int coins [100 + 1];
        for ( int i = 0; i < coinNumber; i++ )
            scanf ("%d", &coins [i]);

        int dp [N + 10];

        for ( int i = 1; i <= N; i++ )
            dp [i] = INT_MAX;

        dp [0] = 0;


        // this iteration works when each coins has only one item
        for ( int i = 0; i < coinNumber; i++ ) {
            for ( int j = N; j >= 0; j-- ) {
                if ( dp [j] != INT_MAX && j + coins [i] <= N )
                    dp [j + coins [i]] = min( dp [j + coins [i]], dp [j] + 1 );
            }
        }

        /*
        // this would work if the quantity of bills/coins is unlimited. but in this case, there is only one item of each value
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < coinNumber; j++) {
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                }
            }
        }
        */

        for ( int i = bill; i <= N; i++ ) {
            if ( dp [i] != INT_MAX ) {
                printf ("%d %d\n", i, dp[i]);
                break;
            }
        }
    }

    return 0;
}
