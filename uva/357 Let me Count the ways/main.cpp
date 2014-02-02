#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define Range 30000
#define int64 long long
int coin[] = {1, 5, 10, 25, 50};
int make;
int64 dp[10][Range + 10];

int64 call(int i, int64 amount) {
    if(i >= 5) {
        if(amount == 0) return 1;
        else return 0;
    }

    if(dp[i][amount] != -1) return dp[i][amount];

    int64 ret1 = 0, ret2 = 0;
    if (amount - coin[i] >= 0) ret1 = call(i, amount - coin[i]);
    ret2 = call(i + 1, amount);
    return dp[i][amount] = ret1 + ret2;

}

int main() {
    freopen("input.txt", "r", stdin);
    memset(dp, -1, sizeof dp);
    int64 result;
    while (cin >> make) {
        result = call(0, make);
        if(result <= 1) cout << "There is only 1 way to produce " <<  make << " cents change.\n";
        else cout << "There are " << result << " ways to produce " << make << " cents change.\n";
    }
    return 0;
}
