#include <bits/stdc++.h>

using namespace std;

#define Max 201
#define i64 long long

char input[Max];
i64 dp[Max];
int n, tc;

i64 f(int i) {
    if ( dp[i] != -1 )
        return dp[i];
    if (i == n)
        return 0;
    if (input[i] == '0')
        return dp[i] = f(i + 1);

    int k = 1;
    i64 ans = 0, pref;
    while ( i + k <= n ) {
        pref = 0;
        for (int j = i; j < i + k; j++)
            pref = pref * 10 + (input[j] - '0');

        if (pref > INT_MAX)
            break;
        ans = max(ans, pref + f(i + k));
        k++;
    }
    return dp[i] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &tc);

    while (tc--) {
        scanf("%s", input);
        n = strlen(input);
        memset(dp, -1, sizeof dp);
        printf("%lld\n", f(0));
    }
    return 0;
}
