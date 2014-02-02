#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define M 8000
typedef long long i64;
int coin[]= {1, 5, 10, 25, 50};
i64 make, dp[6][M];

i64 call(int i, i64 amount) {
    if(i >= 5) {   //All coins have been taken
        if(amount == 0)
            return 1;
        else return 0;
    }
    if(dp[i][amount] != -1)
        return dp[i][amount];

    i64 ret1 = 0, ret2 = 0;

    if(amount - coin[i] >= 0)
        ret1 = call(i, amount - coin[i]);

    ret2 = call(i + 1, amount);

    return dp[i][amount] = ret1 + ret2;
}
int main() {
    freopen("input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    while(scanf("%lld", &make) != EOF) {
        printf("%lld\n", call(0, make));
    }
    return 0;
}
