#include <bits/stdc++.h>

using namespace std;

char str[1024];
int dp[1024][1024], len;

int solve(int i, int j) {
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ret = 0;
    if(str[i] == str[j])
        ret = solve(i + 1, j - 1);
    else
        ret = min(solve(i + 1, j) + 1, solve(i, j - 1) + 1);
    return dp[i][j] = ret;
}

void print(int i, int j) {
    if(i > j) return;
    if(str[i] == str[j]) {
        printf("%c", str[j]);
        print(i + 1, j - 1);
        if(i != j) printf("%c", str[j]);
    } else if(dp[i + 1][j] + 1 == dp[i][j]) {
        printf("%c", str[i]);
        print(i + 1, j);
        printf("%c", str[i]);
    } else if(dp[i][j - 1] + 1 == dp[i][j]) {
        printf("%c", str[j]);
        print(i, j - 1);
        printf("%c", str[j]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int ret;
    while(scanf("%s", str) == 1) {
        memset(dp, -1, sizeof dp);
        len = strlen(str);
        ret = solve(0, len - 1);
        printf("%d ", ret);
        print(0, len - 1);
        putchar('\n');
    }
    return 0;
}
