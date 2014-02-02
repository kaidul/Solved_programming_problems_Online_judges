#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int64;

#define Max 50

int64 dp [Max + 1] [Max + 1];
int64 n, k, m;

/**
Suppose n = 7, k = 4, m = 2
that means a bar can be made of at least 1 unit bar or atmost 2 unit bar. and total bar should be 4.
Tree representation for all possible bar:

                                    /\
                                   /  \
                                  /    \
                                 /      \
                                1        2
                               / \       |
                              /   \      |
                             /     \   (something same)
                            /       \
                           1         2
                          / \       / \
                         /   \     /   \
                        /     \   1\    2
                       1       2  | \   |\
                      / \     / \ 1  2  1 \
                     /   \   /   \         2
                    1     2  1    2

I extend this tree from 1 to m along breadth and 1 to k along depth. Then traverse the tree untill leaves nodes are found. If at leaf state, the sum is equal to n, then we get a solution.

dp[index] [sum] = total bars 'sum' achieved so far in [0..index]
base case:
when total exceeds target sum (n), return 0 to prune tree as there is no possibility to get a solution deeper.
when all bars are built (index == n), then if we can make sum same as n, we get a solution

**/

int64 bktk (int64 index, int64 sum) {
    if ( sum > n )
        return 0;

    if ( index == k ) {
        if ( sum == n )
            return 1;
        return 0;
    }

    if ( dp [index] [sum] != -1 )
        return dp [index] [sum];

    dp [index] [sum] = 0;
    int64 ret = 0;


    for ( int i = 1; i <= m; i++ ) {
        ret += bktk (index + 1, sum + i);
    }

    return dp [index] [sum] = ret;

}

int main () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while ( scanf ("%lld %lld %lld", &n, &k, &m) == 3 ) {

        for ( int i = 0; i <= Max; i++ ) {
            for ( int j = 0; j <= Max; j++ )
                dp [i] [j] = -1;
        }

        printf ("%lld\n", bktk (0, 0));

    }

    return 0;
}
