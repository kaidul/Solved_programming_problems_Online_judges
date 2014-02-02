/**
Notes :
1. 0/1 Knapsack problem

2. u can't take an object more than one time.
suppose, u can stand with maximum 30 kg weight
an object has a weight of 10 kg
but u can take the object only once, not 3 times, though u still have 20 kg space

3. calculate all the values up to 30 and save in an array dp [30]
if ur maxWeightLimit = i, then dp [i] = maxValue u can get
**/
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
#define N 1000000
using namespace std;


int main () {
    freopen("input.txt", "r", stdin);
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        int objects;
        int price [1000 + 5];
        int weight [1000 + 5];

        scanf ("%d", &objects);

        for ( int i = 0; i < objects; i++ )
            scanf ("%d %d", &price [i], &weight [i]);

        int dp [30 + 5];
        memset (dp, 0, sizeof (dp));

        // bottom up knapsack logic
        for ( int j = 0; j < objects; j++ ) {
            for ( int i = 30; i >= 0; i-- ) {
                if ( weight [j] <= i )
                    dp [i] = max (dp[i], dp [i - weight [j]] + price [j]);
            }
        }

        int g;
        scanf ("%d", &g);

        int maxPrice = 0;

        while ( g-- ) {
            int volume;
            scanf ("%d", &volume);
            maxPrice += dp [volume];
        }

        printf ("%d\n", maxPrice);
    }

    return 0;
}
/* another AC code */

/*

int dp[1002][102];
int Weight[1002], Cost[1002];
int capacity, n;

int knapsack(int i, int w) {
    if(i > n) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    int profitByTaken = 0, profitBySkip = 0;

    if(w + Weight[i] <= capacity)
        profitByTaken = Cost[i] + knapsack(i + 1, w + Weight[i]);
    else
        profitByTaken = 0;

    profitBySkip = knapsack(i + 1, w);

    return dp[i][w] = max(profitByTaken, profitBySkip);
}
int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> Cost[i] >> Weight[i];
        int q, ans = 0;
        cin >> q;
        while(q--)  {
            memset(dp, -1, sizeof dp);
            cin >> capacity;
            int ret = knapsack(1, 0);
            ans += ret;
        }
        cout << ans << endl;
    }
    return 0;
}
*/
