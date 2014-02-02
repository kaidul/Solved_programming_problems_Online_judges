#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int lowLimit;
int highLimit;
int dp [100] [100];
int n, t, p;

/**
Suppose n = 3, t = 31, p = 10
then after getting every subject's pass mark, 31 - (10 * 3) = 1 is extra to distribute.
so a subject can be passed by getting at least 10 marks and at most 31 - (10 * 2) = 11 marks.
All possible distribution can be mapped into a recursion tree

                                 /    \
                                /      \
                               /        \
                              /          \
                            10           11
                            / \         /  \
                           /   \       10   \
                          10    11    /  \   \
                         /  \   / \  10  11  10
                        10  11 10  \ (s)    /  \
                            (s)(s)  \      11  10(s)
                                    11
s = success i.e. a solution tuple

The tree's depth is equal to the total subjects. At the leaf stage, when the total value of that branch is equal to t, then we got a solution. here 3 solution exits:
10 10 11
10 11 10
10 10 11

dp[index] [sum] = total mark 'sum' achieved so far in [0..index] subjects
base case:
when total marks exceeds target mark, return 0 to prune tree as there is no possibility to get a solution deeper.
when all subjects are assigned marks (index == n), then if we can make sum same as target, we get a solution

**/

int bktk (int index, int sum) {
    if ( sum > t )
        return 0;

    if ( index == n ) {
        if ( sum == t )
            return 1;
        return 0;
    }

    if ( dp [index] [sum] != -1 )
        return dp [index] [sum];

    dp [index] [sum] = 0;
    int ret = 0;


    for ( int i = lowLimit; i <= highLimit; i++ ) {
        //sum += i;
        ret += bktk (index + 1, sum + i);
        //sum -= i;
    }

    return dp [index] [sum] = ret;

}

int main () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        scanf ("%d %d %d", &n, &t, &p);

        lowLimit = p;
        highLimit = t - p * (n - 1);

        for ( int i = 0; i < 100; i++ ) {
            for ( int j = 0; j < 100; j++ )
                dp [i] [j] = -1;
        }

        printf ("%d\n", bktk (0, 0));

    }

    return 0;
}
