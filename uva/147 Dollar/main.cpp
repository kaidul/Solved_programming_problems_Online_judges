#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define Range 6000
typedef long long i64;

int coin[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
i64 dp[15][Range + 10];
double make;

i64 call(int i, int amount) {
    if(i >= 11) {
        if(amount == 0) return 1;
        else return 0;
    }

    if(dp[i][amount] != -1) return dp[i][amount];

    i64 ret1 = 0, ret2 = 0;
    if (amount - coin[i] >= 0)
        ret1 = call(i, amount - coin[i]);
    ret2 = call(i + 1, amount);
    return dp[i][amount] = ret1 + ret2;

}

int main() {
    freopen("input.txt", "r", stdin);
    memset(dp, -1, sizeof dp);
    while (cin >> make) {
        if(make == 0) break;
        i64 index = make * 20;
        printf ("%6.2lf%17lld\n", make, call(0, index));
    }
    return 0;
}


